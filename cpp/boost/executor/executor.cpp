#include "executor.h"

#include <atomic>
#include <boost/asio.hpp>
#include <queue>
#include <vector>

class PriorityScheduler::PrioritySchedulerImpl
    : public boost::asio::execution_context
{
 public:
  void run()
  {
    std::unique_lock<std::mutex> lock(mutex_);
    for (;;)
    {
      condition_.wait(lock, [&] { return stopped_ || !queue_.empty(); });
      if (stopped_) return;
      std::shared_ptr<item_base> p(queue_.top());
      queue_.pop();
      lock.unlock();
      p->execute_(p);
      lock.lock();
    }
  }

  void stop()
  {
    stopped_ = true;
    condition_.notify_all();
  }

  struct item_base
  {
    // Priorité de l'ordre.
    int priority_;
    // Pour trier les item ayant le même ordre.
    std::chrono::high_resolution_clock::time_point timestamp;
    // Fonction a exécuter dans un wrapper compatible avec
    // boost::asio::dispatch.
    std::function<void(std::shared_ptr<item_base>&)> execute_;
  };

  template <class Func>
  struct item : item_base
  {
    item(int pri, Func f) : function_(std::move(f))
    {
      priority_ = pri;
      execute_ = [](std::shared_ptr<item_base>& p) {
        Func tmp(std::move(static_cast<item*>(p.get())->function_));
        p.reset();
        tmp();
      };
      timestamp = std::chrono::high_resolution_clock::now();
    }

    Func function_;
  };

  // Pour comparer les items et savoir quel sera la prochaine fonction à
  // exécuter.
  struct item_comp
  {
    bool operator()(const std::shared_ptr<item_base>& a,
                    const std::shared_ptr<item_base>& b)
    {
      if (a->priority_ != b->priority_)
        return a->priority_ < b->priority_;
      else
        return a->timestamp > b->timestamp;
    }
  };

  std::mutex mutex_;
  std::condition_variable condition_;
  std::priority_queue<std::shared_ptr<item_base>,
                      std::vector<std::shared_ptr<item_base>>, item_comp>
      queue_;
  std::atomic<bool> stopped_ = false;
};

class PriorityScheduler::ExecutorType::ExecutorTypeImpl
{
 public:
  ExecutorTypeImpl(PriorityScheduler& ctx, int pri) noexcept
      : context_(ctx), priority_(pri)
  {
  }

  ExecutorTypeImpl(ExecutorTypeImpl&& other) noexcept = default;
  ExecutorTypeImpl(ExecutorTypeImpl const& other) = delete;
  ExecutorTypeImpl& operator=(ExecutorTypeImpl&& other) noexcept = default;
  ExecutorTypeImpl& operator=(ExecutorTypeImpl const& other) = delete;

  // Pour boost::asio::dispatch
  PriorityScheduler& context() const noexcept { return context_; }

  // Pour boost::asio::dispatch
  void on_work_started() const noexcept {}

  // Pour boost::asio::dispatch
  void on_work_finished() const noexcept {}

  // Partout Func est boost::asio::detail::work_dispatcher<void()>
  template <class Func, class Alloc>
  void dispatch(Func&& f, const Alloc& a) const
  {
    post(std::forward<Func>(f), a);
  }

 private:
  PriorityScheduler& context_;
  int priority_;

  template <class Func, class Alloc>
  void post(Func&& f, const Alloc& a) const
  {
    // On se force à utiliser l'allocateur fournit.
    std::shared_ptr<PriorityScheduler::PrioritySchedulerImpl::item_base> p(
        std::allocate_shared<
            PriorityScheduler::PrioritySchedulerImpl::item<Func>>(
            typename std::allocator_traits<Alloc>::template rebind_alloc<char>(
                a),
            priority_, std::forward<Func>(f)));
    // On sécurise seulement queue_.
    {
      std::lock_guard<std::mutex> lock(context_.impl_->mutex_);
      context_.impl_->queue_.push(p);
    }
    context_.impl_->condition_.notify_one();
  }

  // Pour boost::asio::dispatch
  template <class Func, class Alloc>
  void defer(Func&& f, const Alloc& a) const
  {
    post(std::forward<Func>(f), a);
  }
};

PriorityScheduler::ExecutorType::ExecutorType(PriorityScheduler& ctx, int pri)
    : impl_(std::make_unique<ExecutorTypeImpl>(ctx, pri))
{
}

PriorityScheduler::ExecutorType::~ExecutorType() = default;

PriorityScheduler::ExecutorType::ExecutorType(ExecutorType&& other) noexcept =
    default;

PriorityScheduler& PriorityScheduler::ExecutorType::context() const noexcept
{
  return impl_->context();
}

void PriorityScheduler::ExecutorType::add(std::function<void()> f)
{
  boost::asio::dispatch(*impl_, f);
}

bool operator==(const PriorityScheduler::ExecutorType& a,
                const PriorityScheduler::ExecutorType& b) noexcept
{
  return &a.context() == &b.context();
}

bool operator!=(const PriorityScheduler::ExecutorType& a,
                const PriorityScheduler::ExecutorType& b) noexcept
{
  return &a.context() != &b.context();
}

PriorityScheduler::PriorityScheduler()
    : impl_(std::make_unique<PrioritySchedulerImpl>())
{
}

PriorityScheduler::~PriorityScheduler() = default;

PriorityScheduler::ExecutorType PriorityScheduler::get_executor(
    int pri) noexcept
{
  return PriorityScheduler::ExecutorType(*this, pri);
}

void PriorityScheduler::run() { impl_->run(); }

void PriorityScheduler::stop() { impl_->stop(); }

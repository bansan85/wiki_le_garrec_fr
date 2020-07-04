#pragma once

#include <functional>
#include <memory>

class PriorityScheduler final
{
 public:
  // Classe satisfaisant l'interface Executor.
  class ExecutorType final
  {
   public:
    ExecutorType(PriorityScheduler* ctx, int pri);
    ~ExecutorType();

    ExecutorType(ExecutorType&& other) noexcept;
    ExecutorType(ExecutorType const& other) = delete;
    ExecutorType& operator=(ExecutorType&& other) noexcept = delete;
    ExecutorType& operator=(ExecutorType const& other) = delete;

    // Pour boost::asio::dispatch
    const PriorityScheduler& context() const noexcept;

    void add(std::function<void()> f);

   private:
    struct ExecutorTypeImpl;
    std::unique_ptr<ExecutorTypeImpl> impl_;
  };

  PriorityScheduler();
  ~PriorityScheduler();

  PriorityScheduler(PriorityScheduler&& other) noexcept = delete;
  PriorityScheduler(PriorityScheduler const& other) = delete;
  PriorityScheduler& operator=(PriorityScheduler&& other) noexcept = delete;
  PriorityScheduler& operator=(PriorityScheduler const& other) = delete;

  ExecutorType get_executor(int pri) noexcept;

  void run();

  void stop();

 private:
  struct PrioritySchedulerImpl;
  std::unique_ptr<PrioritySchedulerImpl> impl_;
};

bool operator==(const PriorityScheduler::ExecutorType& a,
                const PriorityScheduler::ExecutorType& b) noexcept;

bool operator!=(const PriorityScheduler::ExecutorType& a,
                const PriorityScheduler::ExecutorType& b) noexcept;

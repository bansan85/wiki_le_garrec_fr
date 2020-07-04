#pragma once

#include <functional>
#include <memory>

class PriorityScheduler
{
 public:
  // Classe satisfaisant l'interface Executor.
  class ExecutorType
  {
   public:
    ExecutorType(PriorityScheduler& ctx, int pri);
    ~ExecutorType();

    ExecutorType(ExecutorType&& other) noexcept;
    ExecutorType(ExecutorType const& other) = delete;
    ExecutorType& operator=(ExecutorType&& other) noexcept = delete;
    ExecutorType& operator=(ExecutorType const& other) = delete;

    // Pour boost::asio::dispatch
    PriorityScheduler& context() const noexcept;

    void add(std::function<void()> f);

   private:
    class ExecutorTypeImpl;
    std::unique_ptr<ExecutorTypeImpl> impl_;
  };

  PriorityScheduler();
  ~PriorityScheduler();

  ExecutorType get_executor(int pri) noexcept;

  void run();

  void stop();

 private:
  class PrioritySchedulerImpl;
  std::unique_ptr<PrioritySchedulerImpl> impl_;
};

bool operator==(const PriorityScheduler::ExecutorType& a,
                const PriorityScheduler::ExecutorType& b) noexcept;

bool operator!=(const PriorityScheduler::ExecutorType& a,
                const PriorityScheduler::ExecutorType& b) noexcept;

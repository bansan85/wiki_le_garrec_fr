#include <iostream>
#include <thread>

#include "executor.h"

int main()
{
  PriorityScheduler sched;

  PriorityScheduler::ExecutorType&& nulle = sched.get_executor(-1);
  PriorityScheduler::ExecutorType&& low = sched.get_executor(0);
  PriorityScheduler::ExecutorType&& med = sched.get_executor(1);
  PriorityScheduler::ExecutorType&& high = sched.get_executor(2);

  med.add([] { std::cout << "2\n"; });
  low.add([] { std::cout << "1\n"; });
  med.add([] { std::cout << "22\n"; });
  low.add([] { std::cout << "11\n"; });
  high.add([] { std::cout << "3\n"; });
  high.add([] { std::cout << "33\n"; });
  high.add([] { std::cout << "333\n"; });

  nulle.add([&sched] { sched.stop(); });

  std::thread t([&sched] { sched.run(); });

  t.join();
}

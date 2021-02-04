#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#include <list>

namespace
{
void f(const std::list<int>&) {}
}  // namespace
#define F(XXXX, ...) f(XXXX)

int main()
{
  std::list<int> c;
  f(c);
  f(std::list<int>{1, 2, 3, 4});
  f({1, 2, 3, 4});

  // Failed. Macro stops at first comma.
  STR(F(std::list<int>{1, 2, 3, 4}));

  // OK
  STR(F((std::list<int>{1, 2, 3, 4})));

  // OK
  STR(F(std::list<int>({1, 2, 3, 4})));

  // Failed. Macro stops at first comma.
  STR(F({1, 2, 3, 4}));

  // Failed. With double parentheses, c++ can't auto deduce std::list<std::string>.
  STR(F(({1, 2, 3, 4})));
}

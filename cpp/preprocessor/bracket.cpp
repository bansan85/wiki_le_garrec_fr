// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define STR_HELPER(x) #x
// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define STR(x) STR_HELPER(x)

#include <list>

namespace
{
// NOLINTNEXTLINE(readability-named-parameter)
void f(const std::list<int>&) {}
}  // namespace
// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define F(XXXX, ...) f(XXXX)

int main()
{
  std::list<int> c;
  f(c);
  // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
  f(std::list<int>{1, 2, 3, 4});
  // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
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

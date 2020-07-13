#include <cstdlib>

[[gnu::pure]] char square(char x);

int f(int a);
// NOLINTNEXTLINE(cert-msc30-c,cert-msc50-cpp)
int f(int a) { return rand() % a; }

int main(int argc, char* argv[])
{
  // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
  char x = square(argv[0][0]);
  // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
  argv[0][0] = x;
  // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
  char y = square(argv[0][0]);
  return x + y + argc;
}

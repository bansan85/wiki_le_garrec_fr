#include <cstdlib>

[[gnu::pure]] char square(char x);

int f(int a) { return rand() % a; }

int main(int argc, char* argv[])
{
  char x = square(argv[0][0]);
  argv[0][0] = x;
  char y = square(argv[0][0]);
  return x + y + argc;
}

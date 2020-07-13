[[gnu::pure]] int square(int x);

[[gnu::pure]] int f(int a);

int main(int argc, char* /*argv*/[])
{
  int x = square(argc);
  x = x + f(argc);
  int y = square(argc);
  return x + y;
}

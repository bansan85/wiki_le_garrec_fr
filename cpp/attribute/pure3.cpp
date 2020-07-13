[[gnu::pure]] int square(int x);

void f(int a);

int main(int argc, char* /*argv*/[])
{
  int x = square(argc);
  f(argc);
  int y = square(argc);
  return x + y;
}

[[gnu::pure]] int square(int x);

int main(int argc, char* /*argv*/[])
{
  int x = square(argc);
  argc++;
  int y = square(argc);
  return x + y;
}

int foo(int i);
int foo(int i)
{
  const int value = [i]() {
    if (i == 1)
    {
      return 1;
    }
    if (i == 2)
    {
      return 2;
    }
    return 3;
  }();
  return value;
}
int main(int argc, char* /* argv */[]) { return foo(argc); }

int foo(int i);
int foo(int i)
{
  int value;
  if (i == 1)
  {
    value = 1;
  }
  else if (i == 2)
  {
    value = 2;
  }
  else
  {
    value = 3;
  }
  return value;
}
int main(int argc, char* /* argv */[]) { return foo(argc); }

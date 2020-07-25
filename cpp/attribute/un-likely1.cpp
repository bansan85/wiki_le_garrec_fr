int s(int i);
int iff(int i);

int s(int i)
{
  switch (i)
  {
    case 1:
      return 1;

      [[likely]] case 2 : return 2;

      [[unlikely]] default : return 3;
  }
}

int iff(int i)
{
  int retval;
  if (i == 1)
  {
    retval = 1;
  }
  else if (i == 2)
    [[likely]] { retval = 2; }
  else
    [[unlikely]] { retval = 3; }
  return retval;
}

int main(int argc, char* /* argv */[]) { return s(argc) + iff(argc); }

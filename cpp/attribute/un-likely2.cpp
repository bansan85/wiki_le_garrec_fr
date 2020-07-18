int s(int i);
int iff(int i);

int s(int i)
{
  switch (i)
  {
    case 1:
      return 1;
    case 2:
      return 2;
    default:
      return 3;
  }
}

int iff(int i)
{
  // NOLINTNEXTLINE(cppcoreguidelines-init-variables)
  int retval;
  if (i == 1)
  {
    retval = 1;
  }
  else if (i == 2)
  {
    retval = 2;
  }
  else
  {
    retval = 3;
  }
  return retval;
}

int main(int argc, char* /* argv */[]) { return s(argc) + iff(argc); }

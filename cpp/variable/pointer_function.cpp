class Classe
{
 public:
  int function(int i) const { return i; }
};

int main()
{
  // The name of the variable is ptr_func.
  int (Classe::*ptr_func)(int i) const = &Classe::function;
  Classe c;
  return (c.*ptr_func)(2);
}

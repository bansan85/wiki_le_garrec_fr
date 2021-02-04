#define RET_NEG (ARG1) - ARG1;

int main()
{
  int ARG1 = 1;
  // Interprétation erronée à cause de l'espace après ADD lors de la définition de la macro.
  // cppcheck-suppress unreachableCode
  // cppcheck-suppress constStatement
  return RET_NEG(ARG1);
}

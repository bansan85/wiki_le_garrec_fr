#define RET_NEG (ARG1) - ARG1;  // NOLINT

int main()
{
  int ARG1 = 1;
  // Interprétation erronée à cause de l'espace après ADD lors de la définition de la macro.
  return RET_NEG(ARG1);  // NOLINT
}

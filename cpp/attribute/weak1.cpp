#include <iostream>

// Défini dans le header
extern int __attribute__((weak)) variable;
extern unsigned char __attribute__((weak)) variableNull;

// Défini dans le code source.
int __attribute__((weak)) variable = 1;

int main()
{
  // variable a bien un pointeur non nullptr.
  std::cout << "variable : nullptr ? " << std::boolalpha
            << (&variable == nullptr) << " et vaut " << variable << ".\n";
  // variableNull est bien une variable avec un pointeur nullptr.
  std::cout << "variableNull : nullptr ? " << std::boolalpha
            << (&variableNull == nullptr) << " et ne peut être lu.\n";
}

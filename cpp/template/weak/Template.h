#pragma once

#include <iostream>

class Entete
{
public:
  static void go()
  {
#ifdef HACK
    std::cout << "A" << std::endl;
#else
    std::cout << "B" << std::endl;
#endif
  }
};

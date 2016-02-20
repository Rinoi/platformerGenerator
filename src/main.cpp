#include <iostream>
#include <fstream>

#include <cstdio>
#include <cstdlib>

#include "bruit.h"

#include "Space.hpp"

int			main(int argc, char **argv)
{
  int			seed = 1;
  Space			space(t_ptn(0, 0, 0));

  if (argc > 1)
    seed = atoi(argv[1]);
  if (seed < 1)
    seed = (seed * -1) + 1;

  std::cout << space.generate(seed) << std::endl;
  space.print();

  return (0);
}

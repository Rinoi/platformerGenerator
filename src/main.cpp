#include <iostream>
#include <fstream>

#include <cstdio>
#include <cstdlib>

#include "bruit.h"

#include "Space.hpp"
#include "ReachArea.hpp"

int			main(int argc, char **argv)
{
  int			seed = 1;
  Space			space(t_ptn(0, 0, 0));
  t_ptn			ptn;

  if (argc > 1)
    seed = atoi(argv[1]);
  if (seed < 1)
    seed = (seed * -1) + 1;

  std::cout << space.generate(seed) << std::endl;
  space.print();

  ReachArea r(t_ptn(23, 5, 0), space.getMap(), SPACE_SIZE);

  std::cout << std::endl;
  r.print();

  return (0);
}

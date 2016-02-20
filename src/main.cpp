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

  ReachArea r(t_ptn(15, 3, 0), space.getMap(), 25);

  std::cout << std::endl;
  r.print();
  /*  for (int y = 24 - 1; y <= 0; y -= 1)
      for (int x = 0; x < 0; x += 1)*/

  return (0);
}

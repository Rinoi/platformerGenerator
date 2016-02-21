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
  Space			space(45, 45);
  t_ptn			ptn1;
  t_ptn			ptn2;

  if (argc > 1)
    seed = atoi(argv[1]);
  if (seed < 1)
    seed = (seed * -1) + 1;

  std::cout << space.generate(seed) << std::endl;
  space.print();

  for (int x = 0; x < space.getWidth(); x += 1)
    for (int y = space.getHeight() - 1; y > 0; y -= 1)
      if (space.getMap()[y][x] == 0 &&
	  space.getMap()[y - 1][x] != 0)
	{
	  ptn1 = t_ptn(x, y, 0);
	  goto conti;
	}

 conti:

  for (int x = space.getWidth() - 1; x >= 0; x -= 1)
    for (int y = 1; y < space.getHeight(); y += 1)
      if (space.getMap()[y][x] == 0 &&
	  space.getMap()[y - 1][x] != 0)
	{
	  ptn2 = t_ptn(x, y, 0);
	  goto end;
	}
 end:

  ReachArea r1(ptn1, space);
  std::cout << std::endl;
  r1.print();

  ReachArea r2(ptn2, space);
  std::cout << std::endl;
  r2.print();

  return (0);
}

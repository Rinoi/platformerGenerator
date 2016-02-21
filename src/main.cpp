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
  t_ptn			ptn1;
  t_ptn			ptn2;

  if (argc > 1)
    seed = atoi(argv[1]);
  if (seed < 1)
    seed = (seed * -1) + 1;

  std::cout << space.generate(seed) << std::endl;
  space.print();

  for (int x = 0; x < SPACE_SIZE; x += 1)
    for (int y = SPACE_SIZE - 1; y > 0; y -= 1)
      if (space.getMap()[y][x] == 0 &&
	  space.getMap()[y - 1][x] != 0)
	{
	  ptn1 = t_ptn(x, y, 0);
	  goto conti;
	}

 conti:

  for (int x = SPACE_SIZE - 1; x >= 0; x -= 1)
    for (int y = 1; y < SPACE_SIZE; y += 1)
      if (space.getMap()[y][x] == 0 &&
	  space.getMap()[y - 1][x] != 0)
	{
	  ptn2 = t_ptn(x, y, 0);
	  goto end;
	}
 end:

  ReachArea r1(ptn1, space.getMap(), SPACE_SIZE);
  std::cout << std::endl;
  r1.print();

  ReachArea r2(ptn2, space.getMap(), SPACE_SIZE);
  std::cout << std::endl;
  r2.print();

  return (0);
}

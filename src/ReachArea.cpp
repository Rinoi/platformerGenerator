#include <stack>

#include "ReachArea.hpp"

ReachArea::ReachArea()
{
  this->map = NULL;
  this->empty = true;
  this->size = 0;
}

ReachArea::ReachArea(const t_ptn &start, char **map, unsigned int size)
{
  this->map = NULL;
  this->empty = true;
  this->size = 0;
  this->creatReach(start, map, size);
}

ReachArea::~ReachArea()
{

}

void			ReachArea::freeMap()
{
  if (this->map == NULL)
    return ;

  for (unsigned int y = 0; y < this->size; y += 1)
    delete[] (this->map[y]);
  delete[] (this->map);
  this->map = NULL;
  this->empty = true;
}

bool			ReachArea::allocMap()
{
  this->freeMap();
  this->map = new double *[this->size];

  for (unsigned int y = 0; y < this->size; y += 1)
    {
      this->map[y] = new double[this->size];

      for (unsigned int x = 0; x < this->size; x += 1)
        this->map[y][x] = -2;
    }
  return (true);
}

void			ReachArea::print() const
{
  if (this->empty == true)
    return ;

  for (int y = (int)(this->size) - 1; y >= 0 ; y -= 1)
    {
      for (unsigned int x = 0; x < this->size; x += 1)
        {
          char  c = ' ';

          if (this->mapB[y][x] != 0)
            c = 'T';
	  if (this->map[y][x] != -2)
	    c = '.';
	  if (y == this->start.y && x == this->start.x)
	    c = 'O';
	  std::cout << c;
        }
      std::cout << std::endl;
    } 
}

bool			ReachArea::creatReach(const t_ptn &start, char **map,
					      unsigned int size)
{
  if (this->size != size)
    {
      this->size = size;
      if (this->allocMap() == false)
	return (false);
    }
  this->size = size;
  this->start = start;
  this->mapB = (char **)map;

  this->empty = false;
  this->creatReachF();

  return (true);
}

bool			ReachArea::canGo(const t_ptn &ptn, const t_ptn &from) const
{
  if (ptn.x < 0 || ptn.x >= this->size ||
      ptn.y < 0 || ptn.y >= this->size)
    return (false);
  if (this->mapB[(int)(ptn.y)][(int)(ptn.x)] != 0)
    return (false);

  if (this->map[(int)(ptn.y)][(int)(ptn.x)] >= ptn.z)
    return (false);

  if (ptn.z < 0 && ptn.y >= from.y)
    return (false);

  return (true);
}

void			ReachArea::creatReachF()
{
  std::stack<t_ptn>	stack;
  t_ptn			ptn;
  bool			inAir = true;

  stack.push(this->start);
  while (stack.empty() == false)
    {
      ptn = stack.top();
      stack.pop();

      inAir = true;

      if (ptn.z < 0.)
	ptn.z = 0.5;

      if (ptn.y > 0 && this->mapB[(int)(ptn.y) - 1][(int)(ptn.x)] != 0)
	{
	  ptn.z = 0;
	  inAir = false;
	}

      this->map[(int)(ptn.y)][(int)(ptn.x)] = ptn.z;

      if (inAir == false)
	{
	  if (canGo(t_ptn(ptn.x, ptn.y + 1, 1), ptn) == true)
	    stack.push(t_ptn(ptn.x, ptn.y + 1, 1));

	  if (canGo(t_ptn(ptn.x + 1, ptn.y, ptn.z), ptn) == true)
	    stack.push(t_ptn(ptn.x + 1, ptn.y, ptn.z));

	  if (canGo(t_ptn(ptn.x - 1, ptn.y, ptn.z), ptn) == true)
	    stack.push(t_ptn(ptn.x - 1, ptn.y, ptn.z));
	}
      else
	{      
	  if (canGo(t_ptn(ptn.x, ptn.y - 1, ptn.z - 1), ptn) == true)
	    stack.push(t_ptn(ptn.x, ptn.y - 1, ptn.z - 1));

	  if (canGo(t_ptn(ptn.x + 1, ptn.y, ptn.z - 0.5), ptn) == true)
	    stack.push(t_ptn(ptn.x + 1, ptn.y, ptn.z - 0.5));

	  if (canGo(t_ptn(ptn.x - 1, ptn.y, ptn.z - 0.5), ptn) == true)
	    stack.push(t_ptn(ptn.x - 1, ptn.y, ptn.z - 0.5));
	}
    }

}

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
  unsigned int		y;

  this->freeMap();
  this->map = new bool *[this->size];
  if (this->map == NULL)
    return (false);

  y = 0;
  while (y < this->size)
    {
      this->map[y] = new bool[this->size];

      if (this->map[y] == NULL)
        goto free;
      for (unsigned int x = 0; x < this->size; x += 1)
        this->map[y][x] = false;

      y += 1;
    }
  return (true);

 free:
  while (y != 0)
    {
      delete[] (this->map[y - 1]);
      y -= 1;
    }
  delete[] (this->map);
  this->map = NULL;
  return (false);
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
            c = '|';
	  if (this->map[y][x] == true)
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
  bool			startInAir = false;

  if (ptn.x < 0 || ptn.x >= this->size ||
      ptn.y < 0 || ptn.y >= this->size)
    return (false);
  if (this->mapB[(int)(ptn.y)][(int)(ptn.x)] != 0)
    return (false);

  if (from.y - 1 < 0 || this->mapB[(int)(from.y - 1)][(int)(from.x)] == 0)
    startInAir = true;

  if (ptn.y > from.y && from.z != 0. && startInAir == false)
    return (false);

  if (startInAir == true)
    {
      if (ptn.y >= from.y)
	return (false);
      else
	return (true);
    }

  return (true);
}

void			ReachArea::creatReachF()
{
  t_ptn			ptn;
  t_ptn			from;
  double		g;
  std::stack< std::pair<t_ptn, t_ptn> >
    stack;

  stack.push(std::pair<t_ptn, t_ptn>(t_ptn(this->start.x + 1, this->start.y, this->start.z),
				     this->start));
  while (stack.empty() == false)
    {
      ptn = stack.top().first;
      from = stack.top().second;
      stack.pop();


      this->map[(int)(ptn.y)][(int)(ptn.x)] = true;

      std::cout << std::endl;
      this->print();

      if (ptn.y < 0 || this->mapB[(int)(ptn.y) - 1][(int)(ptn.x)] == 0)
	g = -1;
      else
	g = 0;

      if (canGo(t_ptn(ptn.x, ptn.y + 1, ptn.z), from) == true &&
	  this->map[(int)ptn.y + 1][(int)(ptn.x)] == false)
	stack.push(std::pair<t_ptn, t_ptn>(t_ptn(ptn.x, ptn.y + 1, 1),
					   ptn));

      if (canGo(t_ptn(ptn.x, ptn.y - 1, ptn.z), from) == true &&
	  this->map[(int)ptn.y - 1][(int)(ptn.x)] == false)
	stack.push(std::pair<t_ptn, t_ptn>(t_ptn(ptn.x, ptn.y - 1, g),
					   ptn));

      if (canGo(t_ptn(ptn.x + 1, ptn.y, ptn.z), from) == true &&
	  this->map[(int)ptn.y][(int)(ptn.x + 1)] == false)
	  stack.push(std::pair<t_ptn, t_ptn>(t_ptn(ptn.x + 1, ptn.y, g),
					     ptn));

      if (canGo(t_ptn(ptn.x - 1, ptn.y, ptn.z), from) == true &&
	  this->map[(int)ptn.y][(int)(ptn.x - 1)] == false)
	stack.push(std::pair<t_ptn, t_ptn>(t_ptn(ptn.x - 1, ptn.y, g),
					   ptn));

    }

}

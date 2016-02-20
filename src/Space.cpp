#include "Space.hpp"
#include "bruit.h"

Space::Space(const t_ptn &pos)
{
  this->pos = pos;
  this->empty = true;
  this->map = NULL;
}

Space::~Space()
{

}


bool			Space::allocSpace()
{
  int			y;

  this->map = new char *[SPACE_SIZE];

  if (this->map == NULL)
    return (false);

  y = 0;
  while (y < SPACE_SIZE)
    {
      this->map[y] = new char[SPACE_SIZE];
      
      if (this->map[y] == NULL)
	goto free;
      for (int x = 0; x < SPACE_SIZE; x += 1)
	this->map[y][x] = 0;
      
      y += 1;
    }
  return (true);

 free:
  y -= 1;
  while (y >= 0)
    {
      delete[] (this->map[y]);
      y -= 1;
    }
  delete[] (this->map);
  this->map = NULL;
  return (false);
}

bool			Space::addPath(const Path &path)
{
  this->pathList.push_back(path);
  return (true);
}

void			Space::print() const
{
  if (this->empty == true)
    return ;

  for (int y = 0; y < SPACE_SIZE; y += 1)
    {
      for (int x = 0; x < SPACE_SIZE; x += 1)
	{
	  char	c = '.';

	  if (this->map[y][x] != 0)
	    c = 'X';
	  std::cout << c;
	}
      std::cout << std::endl;
    }
}

bool			Space::generate(int seed)
{
  double		v;

  if (this->map == NULL)
      if (this->allocSpace() == false)
	return (false);

  initBruit3D(25, 5);
  for (int y = 0; y < SPACE_SIZE; y += 1)
    for (int x = 0; x < SPACE_SIZE; x += 1)
      {
	v = bruit_coherent3D(x, y, seed, 10.);

	if (v < 0)
	  this->map[y][x] = 0;
	else
	  this->map[y][x] = 1;
      }
  this->empty = false;
  return (true);
}

//GETTEUR SETTERS

bool			Space::isEmpty() const
{
  return (this->empty);
}

const t_ptn		&Space::getPos() const
{
  return (this->pos);
}

char			**Space::getMap() const
{
  return (this->map);
}

const std::list<Path>	&Space::getPathList() const
{
  return (this->pathList);
}

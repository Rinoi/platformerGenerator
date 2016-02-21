#include "Space.hpp"
#include "bruit.h"

#include "ScaleImage.hpp"

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
  this->map = new char *[SPACE_SIZE];

  if (this->map == NULL)
    return (false);

  for (int y = 0; y < SPACE_SIZE; y += 1)
    {
      this->map[y] = new char[SPACE_SIZE];
      for (int x = 0; x < SPACE_SIZE; x += 1)
	this->map[y][x] = 0;
    }
  return (true);
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

  for (int y = SPACE_SIZE - 1; y >= 0 ; y -= 1)
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
  ScaleImage<char>	img(SPACE_SIZE, SPACE_SIZE);

  if (this->map == NULL)
      if (this->allocSpace() == false)
	return (false);

  this->empty = false;
  initBruit3D(75, 6);
  for (int y = 0; y < SPACE_SIZE; y += 1)
    for (int x = 0; x < SPACE_SIZE; x += 1)
      {
	v = bruit_coherent3D(x, y, seed, 10.);

	if (v < 0)
	  {
	    img.setValueAt(x, y, 0);
	    this->map[y][x] = img.valueAt(x, y);
	  }
	else
	  {
	    img.setValueAt(x, y, 1);
	    this->map[y][x] = img.valueAt(x, y);
	  }
      }
  //this->print();
  img = img.opening(1);

  for (int y = 0; y < SPACE_SIZE; y += 1)
    for (int x = 0; x < SPACE_SIZE; x += 1)
      this->map[y][x] = img.valueAt(x, y);

  //  this->print();
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

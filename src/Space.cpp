#include "Space.hpp"
#include "bruit.h"

#include "ScaleImage.hpp"

Space::Space(int w, int h)
{
  this->w = w;
  this->h = h;
  this->empty = true;
  this->map = NULL;
}

Space::~Space()
{
  this->freeSpace();
}


void			Space::freeSpace()
{
  if (this->map == NULL)
    return ;
  for (int y = 0; y < this->h; y += 1)
    delete[] (this->map[y]);
  delete[] (this->map);
  this->map = NULL;
  this->empty = true;
}

bool			Space::allocSpace()
{
  this->freeSpace();

  this->map = new char *[this->h];

  for (int y = 0; y < this->h; y += 1)
    {
      this->map[y] = new char[this->w];
      for (int x = 0; x < this->w; x += 1)
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

  for (int y = this->h - 1; y >= 0 ; y -= 1)
    {
      for (int x = 0; x < this->w; x += 1)
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
  ScaleImage<char>	img(this->w, this->h);

  if (this->allocSpace() == false)
    return (false);

  this->empty = false;
  initBruit3D(75, 6);

  for (int y = 0; y < this->h; y += 1)
    for (int x = 0; x < this->w; x += 1)
      {
	v = bruit_coherent3D(x, y, seed, 10.);

	if (v < 0)
	  img.setValueAt(x, y, 0);
	else
	  img.setValueAt(x, y, 1);
      }
  img = img.opening(1);

  for (int y = 0; y < this->h; y += 1)
    for (int x = 0; x < this->w; x += 1)
      this->map[y][x] = img.valueAt(x, y);

  return (true);
}

//GETTEUR SETTERS

void			Space::setPos(const t_ptn &ptn)
{
  this->pos = ptn;
}

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

int			Space::getWidth() const
{
  return (this->w);
}

int			Space::getHeight() const
{
  return (this->h);
}

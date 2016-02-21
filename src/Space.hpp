#ifndef __SPACE__
#define __SPACE__

#include <iostream>
#include <list>

#include "Ptn.hpp"
#include "Path.hpp"

class World;
class ReachArena;

class Space
{

public:

  Space(int w, int h);
  virtual ~Space();

  bool	addPath(const Path &);

  bool	generate(int seed = 0);

  void	print() const;

private:

  bool	allocSpace();
  void	freeSpace();


public:

  void			setPos(const t_ptn &ptn);


  bool			isEmpty() const;

  char			**getMap() const;
  const t_ptn		&getPos() const;
  const std::list<Path>	&getPathList() const;

  int			getWidth() const;
  int			getHeight() const; 

private:

  int			w;
  int			h;
  t_ptn			pos;
  bool			empty;
  char			**map;
  std::list<Path>	pathList;

};

#endif

#ifndef __SPACE__
#define __SPACE__

#include <iostream>
#include <list>

#include "Ptn.hpp"
#include "Path.hpp"

class World;
class ReachArena;

#define SPACE_SIZE (25)

class Space
{

public:

  Space(const t_ptn &pos);
  virtual ~Space();

  bool	addPath(const Path &);

  bool	generate(int seed = 0);

  void	print() const;

private:

  bool	allocSpace();


public:

  bool			isEmpty() const;

  char			**getMap() const;
  const t_ptn		&getPos() const;
  const std::list<Path>	&getPathList() const;

private:

  t_ptn			pos;
  bool			empty;
  char			**map;
  std::list<Path>	pathList;

};

#endif

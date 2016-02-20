#ifndef __REACH_AREA__
#define __REACH_AREA__

#include <list>
#include "Space.hpp"

class ReachArea
{

public:
  ReachArea();
  ReachArea(const t_ptn &start, char **map, unsigned int size);

  ~ReachArea();

  bool	creatReach(const t_ptn &start, char **map, unsigned int size);

  void	print() const;

private:
  
  //std::list<t_ptn>	whereCanIGo(const t_ptn &start);
  bool			canGo(const t_ptn &ptn, const t_ptn &from) const;
  void			creatReachF();

  bool			allocMap();
  void			freeMap();

private:

  t_ptn			start;
  bool			**map;
  char			**mapB;
  bool			empty;
  unsigned int		size;

};

#endif

#ifndef __REACH_AREA__
#define __REACH_AREA__

#include <list>
#include "Space.hpp"

class ReachArea
{

public:

  static const double	noValue;

public:
  ReachArea();
  ReachArea(const t_ptn &start, const Space &space);

  ~ReachArea();

  bool	creatReach(const t_ptn &start, const Space &space);

  void	print() const;

private:
  
  //std::list<t_ptn>	whereCanIGo(const t_ptn &start);
  bool			canGo(const t_ptn &ptn, const t_ptn &from) const;
  void			creatReachF();

  bool			allocMap();
  void			freeMap();

private:

  t_ptn			start;
  double		**map;
  char			**mapB;
  bool			empty;
  int			h;
  int			w;

};

#endif

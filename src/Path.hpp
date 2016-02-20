#ifndef __PATH__
#define __PATH__

#include <iostream>

#include "Ptn.hpp"

class Path
{

public:

  Path()
  {

  }

  Path(const t_ptn &start, const t_ptn &end)
  {
    this->start = start;
    this->end = end;
  }

  Path(const Path &path)
  {
    *this = path;
  }

  virtual	~Path()
  {}

  const Path	&operator=(const Path &path)
  {
    this->start = path.start;
    this->end = path.end;

    return (*this);
  }

public:

  const t_ptn	&getStart() const
  {
    return (this->start);
  }

  const t_ptn	&getEnd() const
  {
    return (this->end);
  }

private:

  t_ptn		start;
  t_ptn		end;

};

#endif

#ifndef __PTN__
#define __PTN__

typedef struct s_ptn
{
  s_ptn(double x = 0,
	double y = 0,
	double z = 0)
  {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  const s_ptn &operator=(const s_ptn &ptn)
  {
    this->x = ptn.x;
    this->y = ptn.y;
    this->z = ptn.z;

    return (*this);
  }

  double	x;
  double	y;
  double	z;
} t_ptn;

#endif

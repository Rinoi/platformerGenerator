/*
** interpolate.c for RT in /home/mayol_l//git/raytracer
** 
** Made by lucas mayol
** Login   <mayol_l@epitech.net>
** 
** Started on  Wed Jun  5 14:20:55 2013 lucas mayol
** Last update Thu Jun  6 11:33:20 2013 lucas mayol
*/

#include "bruit.h"
#include "math.h"

double		linear_interpolate(double a, double b, double t)
{
  return ((1.0 - t) * a + t * b);
}

double		cosine_interpolate(double a, double b, double t)
{
  double	c;

  c = (1 - cos(t * 3.1415)) / 2;
  return ((1. - c) * a + c * b);
}

double		cosine_interpolate_2d(double a, double b, double c, double d,
				      double x, double y)
{
  double	y1;
  double	y2;

  y1 = cosine_interpolate(a, b, x);
  y2 = cosine_interpolate(c, d, x);
  return (cosine_interpolate(y1, y2, y));

}

double		cubic_interpolate(double bef, double p0,
				  double p1, double af, double t)
{
  double	a3;
  double	a2;
  double	a1;
  double	a0;

  a3 = -0.5 * bef + 1.5 * p0 - 1.5 * p1 + 0.5 * af;
  a2 = bef - 2.5 * p0 + 2 * p1 - 0.5 * af;
  a1 = -0.5 * bef + 0.5 * p1;
  a0 = p0;

  return (a3 * (t * t * t)
	  + a2 * (t * t)
	  + a1 * t
	  + a0);
}

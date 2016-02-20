/*
** lol.c for rt in /home/mayol_l//git/raytracer
** 
** Made by lucas mayol
** Login   <mayol_l@epitech.net>
** 
** Started on  Wed Jun  5 18:57:12 2013 lucas mayol
** Last update Sun Jun  9 21:59:27 2013 karina martynava
*/

#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "bruit.h"

const double	pi = 3.14159265;
static int	pas3D = 0;
static int	nombre_octaves3D = 0;

double		interpolation_cos1D(double a, double b, double x)
{
  double	k;

  k = (1 - cos(x * pi)) / 2;
  return (a * (1 - k) + b * k);
}

void		initBruit3D(int p, int n)
{
  nombre_octaves3D = n;
  pas3D = p;
}

double		interpolation_cos3D(t_bruit_t *br)
{
  double	a;
  double	b;
  double	c;
  double	d;
  double	e;
  double	f;

  a = interpolation_cos1D(br->a0, br->a1, br->x);
  b = interpolation_cos1D(br->b0, br->b1, br->x);
  e = interpolation_cos1D(a, b, br->y);
  c = interpolation_cos1D(br->c0, br->c1, br->x);
  d = interpolation_cos1D(br->d0, br->d1, br->x);
  f = interpolation_cos1D(c, d, br->y);
  return (interpolation_cos1D(e, f, br->z));
}

double		fonction_bruit3D(double x, double y, double z)
{
  int		i;
  int		j;
  int		k;
  t_bruit_t	b;

  i = (int) (x / pas3D);
  j = (int) (y / pas3D);
  k = (int) (z / pas3D);
  b.a0 = noise_3d(i, j, k);
  b.a1 =  noise_3d(i + 1, j, k);
  b.b0 =  noise_3d(i, j + 1, k);
  b.b1 =  noise_3d(i + 1, j + 1, k);
  b.c0 =  noise_3d(i, j, k + 1);
  b.c1 =  noise_3d(i + 1, j, k + 1);
  b.d0 =  noise_3d(i, j + 1, k + 1);
  b.d1 =  noise_3d(i + 1, j + 1, k + 1);
  b.x = fmod(x / pas3D, 1);
  b.y = fmod(y / pas3D, 1);
  b.z = fmod(z / pas3D, 1);
  return (interpolation_cos3D(&b));
}

double		bruit_coherent3D(double x, double y, double z, double persistance)
{
  double	somme;
  double	p;
  int		f;
  int		i;

  somme = 0;
  p = 1;
  f = 1;
  i = 0;
  while (i < nombre_octaves3D)
    {
      somme += p * fonction_bruit3D(x * f, y * f,  z * f);
      p *= persistance;
      f *= 2;
      i += 1;
    }
  return (somme * (1 - persistance) / (1 - p));
}

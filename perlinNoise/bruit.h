/*
** bruit.h for rt in /home/martyn_k//raytracer
** 
** Made by karina martynava
** Login   <martyn_k@epitech.net>
** 
** Started on  Sun Jun  9 18:02:07 2013 karina martynava
** Last update Sun Jun  9 18:29:04 2013 karina martynava
*/

#ifndef _BRUIT_
# define _BRUIT_

double  rand_noise(int t);
double  noise_2d(int x, int y);
double  noise_3d(int x, int y, int z);
double  linear_interpolate(double a, double b, double t);
double  cosine_interpolate(double a, double b, double t);
double  smooth_noise_1d(double x);
double  smooth_noise(double x, double y, double z);
double bruit_coherent2D(double x, double y, double persistance);
double bruit_coherent3D(double x, double y, double z, double persistance);
void initBruit3D(int p, int n);
void initBruit2D(int l, int h, int p, int n);

typedef struct	s_bruit_t
{
  double	a0;
  double	a1;
  double	b0;
  double	b1;
  double	c0;
  double	c1;
  double	d0;
  double	d1;
  double	x;
  double	y;
  double	z;
} t_bruit_t;

#endif

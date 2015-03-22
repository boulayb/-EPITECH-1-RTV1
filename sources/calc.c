/*
** calc.c for rtv1 in /home/boulay_b/Rendu/SE2/MUL/MUL_2014_rtv1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Tue Feb 24 12:04:52 2015 Boulay Arnaud
** Last update Tue Mar 10 00:12:11 2015 Boulay Arnaud
*/

#include <math.h>
#include "my.h"

void	calc_proj(t_rt *rt, int x, int y)
{
  rt->color = VOID_COL;
  rt->proj->k = 1000;
  rt->proj->vx = DIST;
  rt->proj->vy = (I_SIZE_X / 2) - x;
  rt->proj->vz = (I_SIZE_Y / 2) - y;
  rotate_x(rt->proj, ANGLE_X);
  rotate_y(rt->proj, ANGLE_Y);
  rotate_z(rt->proj, ANGLE_Z);
}

void	choose_color(t_rt *rt)
{
  if (rt->color == SPHERE_COL)
    light_sphere(rt);
  else if (rt->color == CYLINDRE_COL)
    light_cylindre(rt);
  else if (rt->color == CONE_COL)
    light_cone(rt);
  else if (rt->color == PLAN_COL)
    light_plan(rt);
}

void	calc_core(t_rt *rt)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (++y <= I_SIZE_Y)
    {
      while (++x <= I_SIZE_X)
	{
	  calc_proj(rt, x, y);
	  plan(rt);
	  sphere(rt);
	  cone(rt);
	  cylindre(rt);
	  choose_color(rt);
	  my_pixel_put_to_image(rt, x, y, rt->color);
	}
      x = 0;
    }
}

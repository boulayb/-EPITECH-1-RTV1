/*
** obj.c for rtv1 in /home/boulay_b/Rendu/SE2/MUL/MUL_2014_rtv1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Wed Feb 25 11:54:39 2015 Boulay Arnaud
** Last update Tue Mar 10 00:10:01 2015 Boulay Arnaud
*/

#include <math.h>
#include <stdio.h>
#include "my.h"

void		plan(t_rt *rt)
{
  double	k;

  if (rt->proj->vz != 0)
    {
      k = -rt->eye->z / rt->proj->vz;
      if (k < rt->proj->k && k > 0.0000001)
	{
	  rt->proj->k = k;
	  rt->color = PLAN_COL;
	}
    }
}

void		sphere(t_rt *rt)
{
  double	k;
  double	ktmp1;
  double	ktmp2;

  rt->sphere->a = pow(rt->proj->vx, 2) + pow(rt->proj->vy, 2)
    + pow(rt->proj->vz, 2);
  rt->sphere->b = (2 * SPHERE_X * rt->proj->vx) +
    (2 * SPHERE_Y * rt->proj->vy) + (2 * SPHERE_Z * rt->proj->vz);
  rt->sphere->c = pow(SPHERE_X, 2) + pow(SPHERE_Y, 2)
    + pow(SPHERE_Z, 2) - pow(SPHERE_R, 2);
  rt->sphere->delta = pow(rt->sphere->b, 2) -
    (4 * rt->sphere->a * rt->sphere->c);
  if (rt->sphere->delta >= 0)
    {
      ktmp1 = (-rt->sphere->b + sqrt(rt->sphere->delta)) / (2 * rt->sphere->a);
      ktmp2 = (-rt->sphere->b - sqrt(rt->sphere->delta)) / (2 * rt->sphere->a);
      k = (ktmp1 < ktmp2 && ktmp1 > 0.0000001) ? ktmp1 : rt->proj->k;
      k = (ktmp2 < ktmp1 && ktmp2 > 0.0000001) ? ktmp2 : rt->proj->k;
      if (k < rt->proj->k)
	{
	  rt->proj->k = k;
	  rt->color = SPHERE_COL;
	}
    }
}

void		cone(t_rt *rt)
{
  double	k;
  double	ktmp1;
  double	ktmp2;
  double	r;

  r = (CONE_R * M_PI) / 180;
  rt->cone->a = pow(rt->proj->vx, 2) + pow(rt->proj->vy, 2)
    - pow(rt->proj->vz, 2) / pow(tan(r), 2);
  rt->cone->b = (2 * CONE_X * rt->proj->vx) +
    (2 * CONE_Y * rt->proj->vy) - (2 * CONE_Z * rt->proj->vz) / pow(tan(r), 2);
  rt->cone->c = pow(CONE_X, 2) + pow(CONE_Y, 2)
    - pow(CONE_Z, 2) / pow(tan(r), 2);
  rt->cone->delta = pow(rt->cone->b, 2) - (4 * rt->cone->a * rt->cone->c);
  if (rt->cone->delta >= 0 && rt->proj->vz > -250)
    {
      ktmp1 = (-rt->cone->b + sqrt(rt->cone->delta)) / (2 * rt->cone->a);
      ktmp2 = (-rt->cone->b - sqrt(rt->cone->delta)) / (2 * rt->cone->a);
      k = (ktmp1 < ktmp2 && ktmp1 > 0.0000001) ? ktmp1 : rt->proj->k;
      k = (ktmp2 < ktmp1 && ktmp2 > 0.0000001) ? ktmp2 : rt->proj->k;
      if (k < rt->proj->k)
	{
	  rt->proj->k = k;
	  rt->color = CONE_COL;
	}
    }
}

void		cylindre(t_rt *rt)
{
  double	k;
  double	ktmp1;
  double	ktmp2;

  rt->cylindre->a = pow(rt->proj->vx, 2) + pow(rt->proj->vy, 2);
  rt->cylindre->b = (2 * CYLINDRE_X * rt->proj->vx) +
    (2 * CYLINDRE_Y * rt->proj->vy);
  rt->cylindre->c = pow(CYLINDRE_X, 2) + pow(CYLINDRE_Y, 2) -
    pow(CYLINDRE_R, 2);
  rt->cylindre->delta = pow(rt->cylindre->b, 2) -
    (4 * rt->cylindre->a * rt->cylindre->c);
  if (rt->cylindre->delta >= 0)
    {
      ktmp1 = (-rt->cylindre->b + sqrt(rt->cylindre->delta)) /
	(2 * rt->cylindre->a);
      ktmp2 = (-rt->cylindre->b - sqrt(rt->cylindre->delta)) /
	(2 * rt->cylindre->a);
      k = (ktmp1 < ktmp2 && ktmp1 > 0.0000001) ? ktmp1 : rt->proj->k;
      k = (ktmp2 < ktmp1 && ktmp2 > 0.0000001) ? ktmp2 : rt->proj->k;
      if (k < rt->proj->k)
	{
	  rt->proj->k = k;
	  rt->color = CYLINDRE_COL;
	}
    }
}

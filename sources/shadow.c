/*
1;2802;0c** shadow.c for rtv1 in /home/boulay_b/Rendu/SE2/MUL/MUL_2014_rtv1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Tue Mar  3 17:03:29 2015 Boulay Arnaud
** Last update Tue Mar 10 00:15:03 2015 Boulay Arnaud
*/

#include <math.h>
#include "my.h"

void		shadow_sphere(t_rt *rt)
{
  double	k;

  rt->proj->px = SPHERE_X + rt->proj->k * rt->proj->vx;
  rt->proj->py = SPHERE_Y + rt->proj->k * rt->proj->vy;
  rt->proj->pz = SPHERE_Z + rt->proj->k * rt->proj->vz;
  rt->sphere->a = pow(rt->light->lx, 2) + pow(rt->light->ly, 2)
    + pow(rt->light->lz, 2);
  rt->sphere->b = (2 * rt->proj->px * rt->light->lx) +
    (2 * rt->proj->py * rt->light->ly) + (2 * rt->proj->pz * rt->light->lz);
  rt->sphere->c = pow(rt->proj->px, 2) + pow(rt->proj->py, 2)
    + pow(rt->proj->pz, 2) - pow(SPHERE_R, 2);
  rt->sphere->delta = pow(rt->sphere->b, 2) -
    (4 * rt->sphere->a * rt->sphere->c);
  if (rt->sphere->delta >= 0)
    {
      k = (-rt->sphere->b + sqrt(rt->sphere->delta)) / (2 * rt->sphere->a);
      if (k >= 0 && k <= 1)
	rt->color = VOID_COL;
    }
}

void		shadow_cylindre(t_rt *rt)
{
  double	k;

  rt->proj->px = CYLINDRE_X + rt->proj->k * rt->proj->vx;
  rt->proj->py = CYLINDRE_Y + rt->proj->k * rt->proj->vy;
  rt->proj->pz = CYLINDRE_Z + rt->proj->k * rt->proj->vz;
  rt->cylindre->a = pow(rt->light->lx, 2) + pow(rt->light->ly, 2);
  rt->cylindre->b = (2 * rt->proj->px * rt->light->lx) +
    (2 * rt->proj->py * rt->light->ly);
  rt->cylindre->c = pow(rt->proj->px, 2) + pow(rt->proj->py, 2) -
    pow(CYLINDRE_R, 2);
  rt->cylindre->delta = pow(rt->cylindre->b, 2) -
    (4 * rt->cylindre->a * rt->cylindre->c);
  if (rt->cylindre->delta >= 0)
    {
      k = (-rt->cylindre->b + sqrt(rt->cylindre->delta)) /
	(2 * rt->cylindre->a);
      if (k > 0 && k < 1)
	rt->color = VOID_COL;
    }
}

void		shadow_cone(t_rt *rt)
{
  double	k;
  double	r;

  rt->proj->px = CONE_X + rt->proj->k * rt->proj->vx;
  rt->proj->py = CONE_Y + rt->proj->k * rt->proj->vy;
  rt->proj->pz = CONE_Z + rt->proj->k * rt->proj->vz;
  r = (CONE_R * M_PI) / 180;
  rt->cone->a = pow(rt->light->lx, 2) + pow(rt->light->ly, 2)
    - pow(rt->light->lz, 2) / pow(tan(r), 2);
  rt->cone->b = (2 * rt->proj->px * rt->light->lx) +
    (2 * rt->proj->py * rt->light->ly) - (2 * rt->proj->pz * rt->light->lz)
    / pow(tan(r), 2);
  rt->cone->c = pow(rt->proj->px, 2) + pow(rt->proj->py, 2)
    - pow(rt->proj->pz, 2) / pow(tan(r), 2);
  rt->cone->delta = pow(rt->cone->b, 2) -
    (4 * rt->cone->a * rt->cone->c);
  if (rt->cone->delta >= 0)
    {
      k = (-rt->cone->b + sqrt(rt->cone->delta)) / (2 * rt->cone->a);
      if (k > 0 && k < 1)
	rt->color = VOID_COL;
    }
}

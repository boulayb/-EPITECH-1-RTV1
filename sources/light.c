/*
** light.c for rtv1 in /home/boulay_b/Rendu/SE2/MUL/MUL_2014_rtv1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Tue Mar  3 13:24:15 2015 Boulay Arnaud
** Last update Mon Mar  9 17:09:09 2015 Boulay Arnaud
*/

#include <math.h>
#include "my.h"

void		light_sphere(t_rt *rt)
{
  rt->proj->px = SPHERE_X + (rt->proj->k * rt->proj->vx);
  rt->proj->py = SPHERE_Y + (rt->proj->k * rt->proj->vy);
  rt->proj->pz = SPHERE_Z + (rt->proj->k * rt->proj->vz);
  rt->proj->norme = sqrt(pow(rt->proj->px, 2) + pow(rt->proj->py, 2) +
			 pow(rt->proj->pz, 2));
  rt->light->lx = rt->light->x - rt->proj->px - 2 * (EYE_X - SPHERE_X);
  rt->light->ly = rt->light->y - rt->proj->py - 2 * (EYE_Y - SPHERE_Y);
  rt->light->lz = rt->light->z - rt->proj->pz - 2 * (EYE_Z - SPHERE_Z);
  rt->light->scalaire = (rt->light->lx * rt->proj->px) +
    (rt->light->ly * rt->proj->py) + (rt->light->lz * rt->proj->pz);
  rt->light->norme = sqrt(pow(rt->light->lx, 2) + pow(rt->light->ly, 2) +
			  pow(rt->light->lz, 2));
  rt->light->cosa = (rt->light->scalaire /
		     (rt->proj->norme * rt->light->norme));
  if (rt->light->cosa < 0)
    rt->color = VOID_COL;
}

void		light_cone(t_rt *rt)
{
  double	r;

  r = tan(CONE_R * M_PI) / 180;
  rt->proj->px = CONE_X + (rt->proj->k * rt->proj->vx);
  rt->proj->py = CONE_Y + (rt->proj->k * rt->proj->vy);
  rt->proj->pz = CONE_Z + (rt->proj->k * rt->proj->vz);
  rt->proj->norme = sqrt(pow(rt->proj->px, 2) + pow(rt->proj->py, 2) +
			 pow(rt->proj->pz * -r, 2));
  rt->light->lx = rt->light->x - rt->proj->px - 2 * (EYE_X - CONE_X);
  rt->light->ly = rt->light->y - rt->proj->py - 2 * (EYE_Y - CONE_Y);
  rt->light->lz = rt->light->z - rt->proj->pz - 2 * (EYE_Z - CONE_Z);
  rt->light->scalaire = (rt->light->lx * rt->proj->px) +
    (rt->light->ly * rt->proj->py) + (rt->light->lz * (rt->proj->pz * -r));
  rt->light->norme = sqrt(pow(rt->light->lx, 2) + pow(rt->light->ly, 2) +
			  pow(rt->light->lz, 2));
  rt->light->cosa = (rt->light->scalaire /
		     (rt->proj->norme * rt->light->norme));
  if (rt->light->cosa < 0)
    rt->color = VOID_COL;
}

void		light_cylindre(t_rt *rt)
{
  rt->proj->px = CYLINDRE_X + (rt->proj->k * rt->proj->vx);
  rt->proj->py = CYLINDRE_Y + (rt->proj->k * rt->proj->vy);
  rt->proj->pz = CYLINDRE_Z + (rt->proj->k * rt->proj->vz);
  rt->proj->norme = sqrt(pow(rt->proj->px, 2) + pow(rt->proj->py, 2));
  rt->light->lx = rt->light->x - rt->proj->px - 2 * (EYE_X - CYLINDRE_X);
  rt->light->ly = rt->light->y - rt->proj->py - 2 * (EYE_Y - CYLINDRE_Y);
  rt->light->lz = rt->light->z - rt->proj->pz - 2 * (EYE_Z - CYLINDRE_Z);
  rt->light->scalaire = (rt->light->lx * rt->proj->px) +
    (rt->light->ly * rt->proj->py);
  rt->light->norme = sqrt(pow(rt->light->lx, 2) + pow(rt->light->ly, 2));
  rt->light->cosa = (rt->light->scalaire /
		     (rt->proj->norme * rt->light->norme));
  if (rt->light->cosa < 0)
    rt->color = VOID_COL;
}

void		light_plan(t_rt *rt)
{
  rt->proj->px = EYE_X + (rt->proj->k * rt->proj->vx);
  rt->proj->py = EYE_Y + (rt->proj->k * rt->proj->vy);
  rt->proj->pz = EYE_Z + (rt->proj->k * rt->proj->vz);
  rt->proj->norme = sqrt(pow(100, 2));
  rt->light->lx = rt->light->x - rt->proj->px;
  rt->light->ly = rt->light->y - rt->proj->py;
  rt->light->lz = rt->light->z - rt->proj->pz;
  rt->light->scalaire = (rt->light->lz * 100);
  rt->light->norme = sqrt(pow(rt->light->lx, 2) + pow(rt->light->ly, 2) +
			  pow(rt->light->lz, 2));
  rt->light->cosa = (rt->light->scalaire /
		     (rt->proj->norme * rt->light->norme));
  if (rt->light->cosa < 0)
    rt->color = VOID_COL;
  shadow_sphere(rt);
  shadow_cylindre(rt);
  shadow_cone(rt);
}

/*
** rotate.c for rtv1 in /home/boulay_b/Rendu/SE2/MUL/MUL_2014_rtv1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Wed Mar  4 11:45:22 2015 Boulay Arnaud
** Last update Wed Mar  4 12:03:25 2015 Boulay Arnaud
*/

#include "my.h"
#include <math.h>

void		rotate_x(t_proj *proj, double angle)
{
  double	tmpx;
  double	tmpy;
  double	tab[3][3];

  angle = (angle * M_PI) / 180;
  tab[0][0] = 1;
  tab[0][1] = 0;
  tab[0][2] = 0;
  tab[1][0] = 0;
  tab[1][1] = cos(angle);
  tab[1][2] = -sin(angle);
  tab[2][0] = 0;
  tab[2][1] = sin(angle);
  tab[2][2] = cos(angle);
  tmpx = proj->vx;
  tmpy = proj->vy;
  proj->vx = tab[0][0] * tmpx + tab[0][1] * tmpy + tab[0][2] * proj->vz;
  proj->vy = tab[1][0] * tmpx + tab[1][1] * tmpy + tab[1][2] * proj->vz;
  proj->vz = tab[2][0] * tmpx + tab[2][1] * tmpy + tab[2][2] * proj->vz;
}

void		rotate_y(t_proj *proj, double angle)
{
  double	tmpx;
  double	tmpy;
  double	tab[3][3];

  angle = (angle * M_PI) / 180;
  tab[0][0] = cos(angle);
  tab[0][1] = 0;
  tab[0][2] = sin(angle);
  tab[1][0] = 0;
  tab[1][1] = 1;
  tab[1][2] = 0;
  tab[2][0] = -sin(angle);
  tab[2][1] = 0;
  tab[2][2] = cos(angle);
  tmpx = proj->vx;
  tmpy = proj->vy;
  proj->vx = tab[0][0] * tmpx + tab[0][1] * tmpy + tab[0][2] * proj->vz;
  proj->vy = tab[1][0] * tmpx + tab[1][1] * tmpy + tab[1][2] * proj->vz;
  proj->vz = tab[2][0] * tmpx + tab[2][1] * tmpy + tab[2][2] * proj->vz;
}

void		rotate_z(t_proj *proj, double angle)
{
  double	tmpx;
  double	tmpy;
  double	tab[3][3];

  angle = (angle * M_PI) / 180;
  tab[0][0] = cos(angle);
  tab[0][1] = -sin(angle);
  tab[0][2] = 0;
  tab[1][0] = sin(angle);
  tab[1][1] = cos(angle);
  tab[1][2] = 0;
  tab[2][0] = 0;
  tab[2][1] = 0;
  tab[2][2] = 1;
  tmpx = proj->vx;
  tmpy = proj->vy;
  proj->vx = tab[0][0] * tmpx + tab[0][1] * tmpy + tab[0][2] * proj->vz;
  proj->vy = tab[1][0] * tmpx + tab[1][1] * tmpy + tab[1][2] * proj->vz;
  proj->vz = tab[2][0] * tmpx + tab[2][1] * tmpy + tab[2][2] * proj->vz;
}

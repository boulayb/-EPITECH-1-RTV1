/*
** init.c for rtv1 in /home/boulay_b/Rendu/SE2/MUL/MUL_2014_rtv1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Feb 23 18:08:47 2015 Boulay Arnaud
** Last update Mon Mar  9 17:41:42 2015 Boulay Arnaud
*/

#include <stdlib.h>
#include "mlx.h"
#include "my.h"

void		init_pos(t_rt *rt)
{
  rt->eye->x = EYE_X;
  rt->eye->y = EYE_Y;
  rt->eye->z = EYE_Z;
  rt->light->x = LIGHT_X;
  rt->light->y = LIGHT_Y;
  rt->light->z = LIGHT_Z;
}

int		init_mlx(t_mlx *mlx)
{
  if ((mlx->ptr = mlx_init()) == NULL ||
      (mlx->img = mlx_new_image(mlx->ptr, I_SIZE_X, I_SIZE_Y)) == NULL ||
      (mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp,
				     &mlx->sizeline, &mlx->endian)) == NULL ||
      (mlx->window = mlx_new_window(mlx->ptr, W_SIZE_X,
				    W_SIZE_Y, "rtv1")) == NULL)
    return (-1);
  return (0);
}

int		init_struct(t_rt *rt)
{
  if ((rt->mlx = malloc(sizeof(t_mlx))) == NULL ||
      (rt->eye = malloc(sizeof(t_eye))) == NULL ||
      (rt->proj = malloc(sizeof(t_proj))) == NULL ||
      (rt->sphere = malloc(sizeof(t_sphere))) == NULL ||
      (rt->cone = malloc(sizeof(t_cone))) == NULL ||
      (rt->cylindre = malloc(sizeof(t_cylindre))) == NULL ||
      (rt->light = malloc(sizeof(t_light))) == NULL)
    return (-1);
  init_pos(rt);
  return (0);
}

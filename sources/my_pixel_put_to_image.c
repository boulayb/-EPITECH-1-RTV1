/*
** my_pixel_put_to_image.c for my_pixel_put_to_image in /home/boulay_b/Work/minilibx/image
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Sun Nov 23 16:31:11 2014 arnaud boulay
** Last update Mon Mar  9 15:34:42 2015 Boulay Arnaud
*/

#include <math.h>
#include "my.h"

void		my_pixel_put_to_image(t_rt *rt, int x, int y, unsigned int color)
{
  t_color	coltab;
  int		i;
  int		o;

  coltab.color = color;
  o = ((y * rt->mlx->sizeline) - rt->mlx->sizeline) + (x * (rt->mlx->bpp / 8));
  i = (o - (rt->mlx->bpp / 8)) - 1;
  while (++i != o)
    if (rt->mlx->endian == 0)
      rt->mlx->data[i] = coltab.bgra[(rt->mlx->bpp / 8) - (o - i)] *
	rt->light->cosa;
    else if (rt->mlx->endian == 1)
      rt->mlx->data[i] = coltab.bgra[(o - i) - 1] *
	rt->light->cosa;
}

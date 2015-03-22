/*
** main.c for rtv1 in /home/boulay_b/Rendu/SE2/MUL/MUL_2014_rtv1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Feb 23 16:58:47 2015 Boulay Arnaud
** Last update Thu Feb 26 13:15:17 2015 Boulay Arnaud
*/

#include <stdlib.h>
#include "mlx.h"
#include "my.h"

void	my_exit(t_rt *rt)
{
  mlx_destroy_window(rt->mlx->ptr, rt->mlx->window);
  free(rt->sphere);
  free(rt->cone);
  free(rt->cylindre);
  free(rt->eye);
  free(rt->proj);
  free(rt->light);
  free(rt->mlx);
  free(rt);
  exit(0);
}

void	rtv1(t_rt *rt)
{
  calc_core(rt);
  mlx_put_image_to_window(rt->mlx->ptr, rt->mlx->window, rt->mlx->img, 0, 0);
  mlx_expose_hook(rt->mlx->window, gere_expose, rt->mlx);
  mlx_key_hook(rt->mlx->window, gere_key, rt);
  mlx_loop(rt->mlx->ptr);
}

int	main(void)
{
  t_rt	*rt;

  if ((rt = malloc(sizeof(t_rt))) == NULL || init_struct(rt) == -1 ||
      init_mlx(rt->mlx) == -1)
    {
      my_putstr("Error: MLX or Malloc failed.\n");
      return (-1);
    }
  rtv1(rt);
  my_exit(rt);
  return (0);
}

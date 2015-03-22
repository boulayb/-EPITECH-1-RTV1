/*
** gere.c for rtv1 in /home/boulay_b/Rendu/SE2/MUL/MUL_2014_rtv1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Feb 23 18:29:30 2015 Boulay Arnaud
** Last update Mon Feb 23 18:42:36 2015 Boulay Arnaud
*/

#include "mlx.h"
#include "my.h"

int	gere_expose(t_mlx *mlx)
{
  mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img, 0, 0);
  return (0);
}

int	gere_key(int key, t_rt *rt)
{
  if (key == ESCAPE)
    my_exit(rt);
  return (0);
}

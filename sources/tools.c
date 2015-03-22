/*
** tools.c for rtv1 in /home/boulay_b/Rendu/SE2/MUL/MUL_2014_rtv1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Feb 23 17:58:22 2015 Boulay Arnaud
** Last update Mon Feb 23 18:01:35 2015 Boulay Arnaud
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    my_putchar(str[i]);
}

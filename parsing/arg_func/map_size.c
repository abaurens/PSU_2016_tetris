/*
** map_size.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/parsing/arg_func/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed Mar  8 15:10:39 2017 Arthur Baurens
** Last update Wed Mar 15 14:20:38 2017 Arthur Baurens
*/

#include <unistd.h>
#include "tetris.h"

char	map_size(t_tetris *tetris, char *arg)
{
  int	i;
  int	w;
  int	h;

  i = -1;
  while (arg[++i] && arg[i] != ',');
  if ((h = get_nbr(arg)) < 1 || arg[i] != ',' || (w = get_nbr(&arg[++i])) < 1)
    {
      write(2, "./tetris: invalid map size : '", 30);
      write(2, arg, str_len(arg));
      write(2, "'\n", 2);
      return (-1);
    }
  tetris->h = h;
  tetris->w = w;
  return (0);
}

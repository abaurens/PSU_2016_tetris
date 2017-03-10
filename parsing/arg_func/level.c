/*
** level.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/parsing/arg_func/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed Mar  8 15:10:36 2017 Arthur Baurens
** Last update Thu Mar  9 20:11:53 2017 Arthur Baurens
*/

#include <unistd.h>
#include "tetris.h"

char	level(t_tetris *tetris, char *arg)
{
  int	lvl;

  if ((lvl = get_nbr(arg)) < 1)
    {
      write(2, "./tetris: invalid starting level : '", 36);
      write(2, arg, str_len(arg));
      write(2, "'\n", 2);
      return (-1);
    }
  tetris->level = lvl;
  return (0);
}

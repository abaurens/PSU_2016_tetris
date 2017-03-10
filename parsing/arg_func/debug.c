/*
** debug.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/parsing/arg_func/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed Mar  8 15:09:55 2017 Arthur Baurens
** Last update Thu Mar  9 14:56:14 2017 Arthur Baurens
*/

#include "tetris.h"

char	debug(t_tetris *tetris, char *arg)
{
  UNUSED(arg);
  tetris->flags |= F_DEBUG;
  return (0);
}

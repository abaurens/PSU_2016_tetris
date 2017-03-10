/*
** without_next.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/parsing/arg_func/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed Mar  8 15:10:42 2017 Arthur Baurens
** Last update Thu Mar  9 15:00:08 2017 Arthur Baurens
*/

#include "tetris.h"

char	without_next(t_tetris *tetris, char *arg)
{
  UNUSED(arg);
  tetris->flags |= F_NONXT;
  return (0);
}

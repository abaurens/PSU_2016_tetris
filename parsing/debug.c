/*
** debug.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/parsing/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed Mar 15 14:25:42 2017 Arthur Baurens
** Last update Fri Mar 17 10:45:25 2017 Arthur Baurens
*/

#include <unistd.h>
#include "tetris.h"

void		print_tetri_debug(t_list *tetri, char error)
{
  int		i;
  int		j;
  t_shape	*shape;

  i = str_len(TETR_DIR);
  j = str_len(&tetri->data[i]) - str_len(FILE_EXTENTION);
  write(1, "Tetriminos :  Name ", 19);
  write(1, &tetri->data[i], j);
  write(1, error ? " :  Error" : " :  Size ", 9);
  if (!(error * (i = -1)))
    {
      shape = tetri->tetri.shape;
      put_nbr(tetri->tetri.shape[0].w);
      write(1, "*", 1);
      put_nbr(tetri->tetri.shape[0].h);
      write(1, " :  Color ", 10);
      put_nbr(tetri->tetri.color);
      write(1, " :", 2);
      while (++i < tetri->tetri.shape->h)
        {
          write(1, "\n", 1);
          write(1, shape->data[i], str_len(shape->data[i]));
        }
    }
  write(1, "\n", 1);
}

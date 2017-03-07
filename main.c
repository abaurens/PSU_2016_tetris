/*
** main.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu Mar  2 16:38:42 2017 Arthur Baurens
** Last update Tue Mar  7 17:30:56 2017 Arthur Baurens
*/

#include "tetris.h"

int		main(int ac, char **av)
{
  int		i;
  int		a;
  int		h;
  int		loop;
  t_tetrimino	*tetriminos;

  ac = ac;
  av = av;
  tetriminos = get_tetriminos();
  i = -1;
  while (tetriminos[++i].shape)
    {
      h = 0;
      loop = 1;
      while (loop)
	{
	  a = -1;
	  loop = 0;
	  while (++a < 4)
	    {
	      if (h >= tetriminos[i].shape[a].h)
		printf("          ");
	      else
		{
		  printf("%-10s", tetriminos[i].shape[a].data[h]);
		  loop = 1;
		}
	    }
	  printf("\n");
	  h++;
	}
    }
  return (0);
}

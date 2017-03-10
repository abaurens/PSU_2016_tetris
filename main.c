/*
** main.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu Mar  2 16:38:42 2017 Arthur Baurens
** Last update Thu Mar  9 20:04:05 2017 Arthur Baurens
*/

#include "tetris.h"

void		print_tab(t_tetrimino *tetriminos)
{
  int		i;
  int		a;
  int		h;
  int		loop;

  i = -1;
  while (tetriminos[++i].shape && (h = 0) == 0 && (loop = 1))
    {
      while (loop && (loop = 0) == 0)
	{
	  a = -1;
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
}

t_tetris	init_tetris()
{
  t_tetris	tetris;

  tetris.w = 10;
  tetris.h = 20;
  tetris.level = 1;
  tetris.flags = 0;
  return (tetris);
}

/*
** void	my_put_bin(char nb)
** {
**   if (nb / 2 > 0)
**     my_put_bin(nb / 2);
**   nb = nb % 2 + '0';
**   write(1, &nb, 1);
** }
*/

int		main(int ac, char **av)
{
  char		res;
  t_tetrimino	*tetriminos;
  t_tetris	tetris;

  tetris = init_tetris();
  if ((res = parse_opt(&tetris, ac, av)) != 0)
    return (res == -1 ? 84 : 0);
  if ((tetriminos = get_tetriminos()) == 0)
    return (84);
  print_tab(tetriminos);
  delete_tetri_tab(tetriminos);
  return (0);
}

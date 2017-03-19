/*
** main.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu Mar  2 16:38:42 2017 Arthur Baurens
** Last update Sun Mar 19 17:54:36 2017 Arthur Baurens
*/

#include <unistd.h>
#include "tetris.h"

t_tetris	init_tetris()
{
  t_tetris	tetris;

  tetris.w = 10;
  tetris.h = 20;
  tetris.level = 1;
  tetris.flags = 0;
  tetris.keys.kd = 258;
  tetris.keys.kt = 259;
  tetris.keys.kl = 260;
  tetris.keys.kr = 261;
  tetris.keys.kp = ' ';
  tetris.keys.kq = 'q';
  tetris.is_paused = 0;
  return (tetris);
}

void	print_debug(t_tetris *tetris)
{
  char	next;

  next = ((tetris->flags & F_NONXT) == 0);
  write(1, "*** DEBUG MODE ***\n", 19);
  write(1, "Next : ", 7);
  write(1,  next ? "Yes\n" : "No\n", next ? 4 : 3);
  write(1, "Level : " , 8);
  put_nbr(tetris->level);
  write(1, "\nSize : ", 8);
  put_nbr(tetris->h);
  write(1, "*", 1);
  put_nbr(tetris->w);
  write(1, "\n", 1);
}

int		main(int ac, char **av)
{
  char		res;
  t_tetris	tetris;

  tetris = init_tetris();
  if ((res = parse_opt(&tetris, ac, av)) != 0)
    return (res == -1 ? 84 : 0);
  if ((tetris.flags & F_DEBUG) != 0)
    print_debug(&tetris);
  if ((tetris.tetriminos = get_tetriminos(&tetris)) == 0)
    return (84);
  if ((tetris.map = new_tab(tetris.w, tetris.h)) != NULL &&
      (tetris.color_map = new_tab(tetris.w, tetris.h)) != NULL)
    start_game(&tetris);
  free_tab(tetris.map);
  delete_tetri_tab(tetris.tetriminos);
  return (0);
}

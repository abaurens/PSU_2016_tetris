/*
** rules.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Sun Mar 19 19:35:28 2017 Arthur Baurens
** Last update Sun Mar 19 23:11:32 2017 Arthur Baurens
*/

#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

void	delete_empt_lines(t_tetris *tetris, int line)
{
  char	*tmp;

  while (line > 0)
    {
      tmp = tetris->map[line - 1];
      tetris->map[line - 1] = tetris->map[line];
      tetris->map[line] = tmp;
      tmp = tetris->color_map[line - 1];
      tetris->color_map[line - 1] = tetris->color_map[line];
      tetris->color_map[line] = tmp;
      line--;
    }
}

char	end(t_tetris *tetris)
{
  int	x;

  x = -1;
  while (tetris->map[0][++x])
    {
      if (tetris->map[0][x] == '*')
	{
	  mvprintw(5, tetris->w * 2 + 3, "Game Finiched !");
	  nodelay(stdscr, 0);
	  getch();
          return (0);
	}
    }
  return (1);
}

void	clean_lines(t_tetris *tetris)
{
  int	y;
  int	x;
  char **map;

  y = -1;
  map = tetris->map;
  while (map[++y] && (x = -1) == -1)
    {
      while (map[y][++x] == '*');
      if (x == str_len(map[y]))
	{
	  while (--x >= 0)
	    map[y][x] = ' ';
	  tetris->score++;
	  tetris->level += 0.1;
	  delete_empt_lines(tetris, y);
	}
    }
}

char	is_colliding(t_tetris *tetris, int rot)
{
  int		x;
  int		y;
  int		i;
  int		j;
  char		**map;
  t_tetrimino	*cur;

  i = -1;
  map = tetris->map;
  cur = tetris->pieces[0];
  while (cur->shape[rot].data[++i])
    {
      j = -1;
      while (cur->shape[rot].data[i][++j])
	{
	  if ((int)cur->y + i >= tetris->h)
	    return (1);
	  y = (int)cur->y + i;
	  x = (int)cur->x + j;
	  if (cur->shape[rot].data[i][j] == '*' &&
	      map[y][x] == '*')
	    return (1);
	}
    }
  return (0);
}

void	collide(t_tetris *tetris, t_tetrimino *cur, int *rot)
{
  int	x;
  int	y;

  y = -1;
  while (cur->shape[*rot].data[++y])
    {
      x = -1;
      while (cur->shape[*rot].data[y][++x])
	{
	  if (cur->shape[*rot].data[y][x] != '*' || cur->y + y < 0)
	    continue;
	  tetris->color_map[(int)cur->y + y][(int)cur->x + x] = cur->color;
	  tetris->map[(int)cur->y + y][(int)cur->x + x] =
	  cur->shape[*rot].data[y][x];
	}
    }
  *rot = 0;
  tetris->pieces[0] = tetris->pieces[1];
  tetris->pieces[0]->y = 0;
  tetris->pieces[0]->x = tetris->w / 2 - tetris->pieces[0]->shape[*rot].w / 2;
  tetris->pieces[1] = &tetris->tetriminos[rand() % tetris->tetri_count];
}

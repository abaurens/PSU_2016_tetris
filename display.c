/*
** display.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Mar 17 11:14:05 2017 Arthur Baurens
** Last update Sun Mar 19 23:38:58 2017 Arthur Baurens
*/

#include <ncurses.h>
#include "tetris.h"

void	display_title(t_tetris *tetris)
{
  int	x;
  int	y;
  char	*colors;
  char	*title[6];

  y = -1;
  colors = "143265";
  title[0] = "* * * * * * * * * * * * * * * *";
  title[1] = "  *   *       *   *   *   *    ";
  title[2] = "  *   * *     *   * *   * * * *";
  title[3] = "  *   *       *   *   * *     *";
  title[4] = "  *   * * *   *   *   * * * * *";
  title[5] = NULL;
  move(0, 0);
  while (title[++y] != NULL)
    {
      x = -1;
      while (title[y][++x] != '\0')
	{
	  move(y, tetris->w * 2 + 3 + x);
	  attron(COLOR_PAIR(colors[x < 25 ? x / 6 : 5] - '0'));
	  addch(title[y][x]);
	}
      addch('\n');
    }
}

void	display_borders(t_tetris *tetris)
{
  int	y;
  int	x;

  y = -1;
  while (++y < tetris->h + 2)
    {
      x = -1;
      while (++x < tetris->w * 2 + 2)
	{
	  if (x == 0 || y == 0 || x == tetris->w * 2 + 1 || y == tetris->h + 1)
	    mvaddch(y, x, '*');
	}
    }
}

void		display_game(t_tetris *tetris, int rot)
{
  int		x;
  int		y;

  y = -1;
  while (++y < tetris->h && (x = -1) == -1)
    {
      move(y + 1, 1);
      while (++x < tetris->w)
	{
	  attron(COLOR_PAIR(tetris->color_map[y][x]));
	  printw("%c ", tetris->map[y][x]);
	}
    }
  y = -1;
  while (tetris->pieces[0]->shape[rot].data[++y] && (x = -1) == -1)
    {
      while (tetris->pieces[0]->shape[rot].data[y][++x])
	{
	  move(1 + tetris->pieces[0]->y + y,
	       1 + tetris->pieces[0]->x * 2 + x * 2);
	  attron(COLOR_PAIR(tetris->pieces[0]->color));
	  if (tetris->pieces[0]->shape[rot].data[y][x] == '*')
	    printw("%c ", tetris->pieces[0]->shape[rot].data[y][x]);
	}
    }
}

void	display_next_and_score(t_tetris *tetris)
{
  int	y;
  int	x;

  attron(COLOR_PAIR(1));
  mvprintw(7, tetris->w * 2 + 4, "Level : %d\n", (int)tetris->level);
  mvprintw(8, tetris->w * 2 + 4, "Score : %d\n", tetris->score);
  mvprintw(10, tetris->w * 2 + 6, "* Next piece *");
  y = -2;
  x = tetris->w * 2 + 12 - tetris->pieces[1]->shape->w / 2;
  while (++y < 0 || tetris->pieces[1]->shape->data[y])
    {
      attron(COLOR_PAIR(1));
      mvprintw(11 + y + 1, tetris->w * 2 + 6, "*            *");
      attron(COLOR_PAIR(tetris->pieces[1]->color));
      if (y >= 0)
	mvprintw(12 + y, x, tetris->pieces[1]->shape->data[y]);
    }
  attron(COLOR_PAIR(1));
  while (++y < 6)
    mvprintw(11 + y, tetris->w * 2 + 6, "*            *");
  mvprintw(11 + y, tetris->w * 2 + 6, "**************");
}

void		display(t_tetris *tetris, int rot)
{
  int		w;

  w = tetris->w * 2 + 2;
  if (COLS < w || LINES < MAX(tetris->h + 2, 17))
    {
      mvprintw(LINES / 2, (COLS / 2 - 13) % COLS, "Please, resize the window.");
      return ;
    }
  display_borders(tetris);
  display_game(tetris, rot);
  if (COLS >= 31 + tetris->w * 2 + 4)
    display_title(tetris);
  display_next_and_score(tetris);
  move(LINES - 1, COLS - 1);
}

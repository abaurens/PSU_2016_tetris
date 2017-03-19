/*
** game.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Mar 17 09:28:06 2017 Arthur Baurens
** Last update Sun Mar 19 22:59:32 2017 Arthur Baurens
*/

#include <sys/types.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "tetris.h"

static void	init_game(t_tetris *tetris)
{
  int		i;
  int		j;

  i = -1;
  srand(getpid() * time(NULL) * getppid());
  while (++i < tetris->h)
    {
      j = -1;
      while (++j < tetris->w)
	{
	  tetris->color_map[i][j] = 7;
	  tetris->map[i][j] = ' ';
	}
    }
  tetris->score = 0;
  tetris->pieces[0] = &tetris->tetriminos[rand() % tetris->tetri_count];
  tetris->pieces[1] = &tetris->tetriminos[rand() % tetris->tetri_count];
}

static void	init_ncurses(t_tetris *tetris)
{
  initscr();
  noecho();
  cbreak();
  nodelay(stdscr, 1);
  keypad(stdscr, TRUE);
  if (has_colors() == 0)
    return ;
  start_color();
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void	apply_moves(t_tetris *tetris, int key, int *rot)
{
  if (key == tetris->keys.kt && !is_colliding(tetris, (*rot + 1) % 4))
    *rot = (*rot + 1) % 4;
  if (tetris->pieces[0]->x + tetris->pieces[0]->shape[*rot].w -
      (key == tetris->keys.kt) < tetris->w)
    tetris->pieces[0]->x += (key == tetris->keys.kr);
  else if (key == tetris->keys.kt)
    *rot = (*rot - 1) % 4;
  if (tetris->pieces[0]->x - 1 >= 0)
    tetris->pieces[0]->x -= (key == tetris->keys.kl);
  if (is_colliding(tetris, *rot))
    {
      tetris->pieces[0]->x -= (key == tetris->keys.kr);
      tetris->pieces[0]->x += (key == tetris->keys.kl);
    }
  if (key == tetris->keys.kd)
    tetris->pieces[0]->y = (int)tetris->pieces[0]->y + 1;
  if (key == tetris->keys.kp)
    tetris->is_paused = !tetris->is_paused;
}

void	game_loop(t_tetris *tetris)
{
  int	rot;
  int	c;

  rot = 0;
  tetris->pieces[0]->y = 0;
  tetris->pieces[0]->x = tetris->w / 2 - tetris->pieces[0]->shape[rot].w / 2;
  while (end(tetris))
    {
      erase();
      display(tetris, rot);
      if ((c = getch()) != ERR)
	apply_moves(tetris, c, &rot);
      if (is_colliding(tetris, rot) && tetris->pieces[0]->y--)
	collide(tetris, tetris->pieces[0], &rot);
      if (c != KEY_DOWN)
	tetris->pieces[0]->y += (double)((int)tetris->level * 5) / 50000;
      while (tetris->is_paused && getch() != tetris->keys.kp)
	mvprintw(LINES / 2, COLS / 2 - 6, "Game Paused !");
      tetris->is_paused = 0;
      clean_lines(tetris);
      refresh();
    }
  endwin();
}

void	start_game(t_tetris *tetris)
{
  if (tetris->tetri_count < 1)
    {
      write(2, "There's no tetrimino to play with. Game can not start.\n", 55);
      return ;
    }
  init_game(tetris);
  init_ncurses(tetris);
  game_loop(tetris);

}

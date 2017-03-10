/*
** parse_opt.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/parsing/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed Mar  8 11:32:43 2017 Arthur Baurens
** Last update Fri Mar 10 13:22:41 2017 Arthur Baurens
*/

#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "tetris.h"

char		exec_opt(t_tetris *tetris, t_opt *options, int ac, char **av)
{
  char		i;
  int		index;
  extern int	optind;
  extern char	*optarg;
  char		(*func[index = 11])(t_tetris *, char *);

  func[--index] = debug;
  func[--index] = without_next;
  func[--index] = map_size;
  func[--index] = key_pause;
  func[--index] = key_quit;
  func[--index] = key_drop;
  func[--index] = key_turn;
  func[--index] = key_right;
  func[--index] = key_left;
  func[--index] = level;
  func[--index] = help;
  while ((i = getopt_long_only(ac, av, "", options, &index)) != -1)
    {
      if (i > 10 || (i = func[(int)i](tetris, optarg)) != 0)
	return (i);
    }
  return (i);
}

char		parse_opt(t_tetris *tetris, int ac, char **av)
{
  t_opt	lg_opt[21];

  lg_opt[0] = (t_opt){"help", no_argument, 0, 0};
  lg_opt[1] = (t_opt){"l", required_argument, 0, 1};
  lg_opt[2] = (t_opt){"level", required_argument, 0, 1};
  lg_opt[3] = (t_opt){"kl", required_argument, 0, 2};
  lg_opt[4] = (t_opt){"key-left", required_argument, 0, 2};
  lg_opt[5] = (t_opt){"kr", required_argument, 0, 3};
  lg_opt[6] = (t_opt){"key-right", required_argument, 0, 3};
  lg_opt[7] = (t_opt){"kt", required_argument, 0, 4};
  lg_opt[8] = (t_opt){"key-turn", required_argument, 0, 4};
  lg_opt[9] = (t_opt){"kd", required_argument, 0, 5};
  lg_opt[10] = (t_opt){"key-drop", required_argument, 0, 5};
  lg_opt[11] = (t_opt){"kq", required_argument, 0, 6};
  lg_opt[12] = (t_opt){"key-quit", required_argument, 0, 6};
  lg_opt[13] = (t_opt){"kp", required_argument, 0, 7};
  lg_opt[14] = (t_opt){"key-pause", required_argument, 0, 7};
  lg_opt[15] = (t_opt){"map-size", required_argument, 0, 8};
  lg_opt[16] = (t_opt){"w", no_argument, 0, 9};
  lg_opt[17] = (t_opt){"without-next", no_argument, 0, 9};
  lg_opt[18] = (t_opt){"d", no_argument, 0, 10};
  lg_opt[19] = (t_opt){"debug", no_argument, 0, 10};
  lg_opt[20] = (t_opt){0, 0, 0, 0};
  return (exec_opt(tetris, lg_opt, ac, av));
}

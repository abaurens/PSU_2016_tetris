/*
** tetris.h for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/include/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu Mar  2 16:38:13 2017 Arthur Baurens
** Last update Fri Mar 10 11:08:06 2017 Arthur Baurens
*/

#include <getopt.h>

#ifndef TETRIS_H_
# define TETRIS_H_
# define UNUSED(x) ((void)(x))
# define TETR_DIR "./tetriminos/"
# define FILE_EXTENTION ".tetrimino"
# define F_DEBUG 1
# define F_NONXT 1 << 1

typedef struct option t_opt;

typedef struct
{
  char		*shrt;
  char		*lng;
}		t_arg;

typedef struct
{
  int		w;
  int		h;
  int		level;
  char		flags;
}		t_tetris;

typedef struct
{
  int		x;
  int		y;
}		t_vec;

typedef struct
{
  int		w;
  int		h;
  char		**data;
}		t_unitetr;

typedef struct
{
  int		x;
  int		y;
  int		color;
  t_unitetr	*shape;
}		t_tetrimino;

typedef struct	s_list
{
  struct s_list	*next;
  struct s_list *prev;
  char		*data;
  t_tetrimino	tetri;
}		t_list;

/*
** arg_func
*/
char	help(t_tetris *, char *);
char	debug(t_tetris *, char *);
char	level(t_tetris *, char *);
char	map_size(t_tetris *, char *);
char	key_quit(t_tetris *, char *);
char	key_turn(t_tetris *, char *);
char	key_left(t_tetris *, char *);
char	key_drop(t_tetris *, char *);
char	key_pause(t_tetris *, char *);
char	key_right(t_tetris *, char *);
char	without_next(t_tetris *, char *);

/*
** parse_opt.c
*/
char		parse_opt(t_tetris *tetris, int, char **);

/*
** parsing.c
*/
t_tetrimino	*get_tetriminos();
char		file_to_tetri(int, t_tetrimino *);

/*
** list.c
*/
char		add(t_list **, const char *);
int		list_size(t_list *);
void		delete(t_list **, t_list *);
void		sort_list(t_list **);

/*
** string.c
*/
int		str_len(const char *);
int		my_strcmp(const char *, const char *);
char		end_with(const char *, const char *);
char		start_with(const char *, const char *);
char		*my_strncat(const char *, const char *, int);

/*
** pointers.c
*/
char		**new_tab(int, int);
int		clean_gnl(int, int);
int		multifree(int, int, ...);
void		delete_tetri_tab(t_tetrimino *);

/*
** numbers.c
*/
int		get_nbr(const char *);
int		is_num(const char *);

/*
** file_content.c
*/
char		is_valid_header(const char *, t_tetrimino *);
char		check_line(char *);
char		use_file(t_list *);

#endif /* !TETRIS_H_ */

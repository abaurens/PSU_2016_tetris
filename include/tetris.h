/*
** tetris.h for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/include/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu Mar  2 16:38:13 2017 Arthur Baurens
** Last update Sun Mar 19 22:59:14 2017 Arthur Baurens
*/

#include <ncurses.h>
#include <getopt.h>

#ifndef TETRIS_H_
# define TETRIS_H_
# define UNUSED(x) ((void)(x))
# define TETR_DIR "./tetriminos/"
# define FILE_EXTENTION ".tetrimino"
# define MAX(x, y) ((x) > (y) ? (x) : (y))

# define SCOREBOARD_W 32
# define SCOREBOARD_H 17

# define F_DEBUG 1
# define F_NONXT 1 << 1

typedef struct option t_opt;

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
}		t_shape;

typedef struct
{
  double	x;
  double	y;
  int		color;
  t_shape	*shape;
}		t_tetrimino;

typedef struct
{
  int		kl;
  int		kr;
  int		kt;
  int		kd;
  int		kp;
  int		kq;
}		t_keys;

typedef struct
{
  int		w;
  int		h;
  double	level;
  int		score;
  char		is_paused;
  char		flags;
  char		**map;
  char		**color_map;
  int		tetri_count;
  t_keys	keys;
  t_tetrimino	*pieces[2];
  t_tetrimino	*tetriminos;
}		t_tetris;

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
t_tetrimino	*get_tetriminos(t_tetris *);
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
void		free_tab(void *);
char		**new_tab(int, int);
int		clean_gnl(int, int);
int		multifree(int, int, ...);
void		delete_tetri_tab(t_tetrimino *);

/*
** numbers.c
*/
int		get_nbr(const char *);
int		is_num(const char *);
void		put_nbr(int);

/*
** file_content.c
*/
char		is_valid_header(const char *, t_tetrimino *);
char		check_line(char *);
char		use_file(t_list *);

/*
** debug.c
*/
void		print_tetri_debug(t_list *, char);

/*
** display.c
*/
void		display(t_tetris *, int rot);

/*
** game.c
*/
void	start_game(t_tetris *tetris);
void	game_loop(t_tetris *tetris);

/*
** rules.c
*/
void	clean_lines(t_tetris *tetris);
char	end(t_tetris *tetris);
char	is_colliding(t_tetris *tetris, int rot);
void	collide(t_tetris *tetris, t_tetrimino *cur, int *rot);

#endif /* !TETRIS_H_ */

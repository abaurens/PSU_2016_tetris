/*
** tetris.h for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/include/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu Mar  2 16:38:13 2017 Arthur Baurens
** Last update Tue Mar  7 17:42:00 2017 Arthur Baurens
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# define TETR_DIR "./tetriminos/"
# define FILE_EXTENTION ".tetrimino"

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

t_tetrimino	*get_tetriminos();

int	list_size(t_list *list);
char	add(t_list **list, const char *name);
void	delete(t_list **, t_list *);
void	sort_list(t_list **list);

int	str_len(const char *str);
int	my_strcmp(const char *s1, const char *s2);
char	end_with(const char *name, const char *ref);
char	*my_strncat(const char *s1, const char *s2, int n);

char	**new_tab(int w, int h);
int	clean_gnl(int ret, int fd);
int	multifree(int ret, int nb, ...);

int	get_number(const char *num);
int	is_num(const char *str);

char	file_to_tetri(int fd, t_tetrimino *tetri);

char	is_valid_header(const char *line, t_tetrimino *tetri);
char	check_line(char *line);
char	use_file(t_list *elem);

#endif /* !TETRIS_H_ */

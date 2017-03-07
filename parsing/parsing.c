/*
** parsing.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Mar  3 15:50:49 2017 Arthur Baurens
** Last update Tue Mar  7 17:36:02 2017 Arthur Baurens
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "tetris.h"
#include "get_next_line.h"

static char	get_file_list(t_list **list)
{
  struct dirent	*content;
  DIR		*dir;
  char		*tmp;

  *list = NULL;
  if ((dir = opendir(TETR_DIR)) == NULL)
    return (-1);
  while ((content = readdir(dir)) != NULL)
    {
      if (end_with(content->d_name, FILE_EXTENTION))
	{
	  tmp = my_strncat(TETR_DIR, content->d_name, 0);
	  add(list, tmp);
	  free(tmp);
	}
    }
  closedir(dir);
  return (0);
}

char	file_to_tetri(int fd, t_tetrimino *tetri)
{
  int	i;
  char	*line;

  i = 0;
  if ((tetri->shape = malloc(sizeof(t_unitetr) * 4)) == NULL)
    return (-3);
  if ((tetri->shape[0].data = malloc(sizeof(char *) * (tetri->y + 1))) == NULL)
    return (-3);
  tetri->shape[0].data[tetri->y] = NULL;
  tetri->shape[0].w = tetri->x;
  tetri->shape[0].h = tetri->y;
  while ((line = get_next_line(fd)) != NULL)
    {
      if (i >= tetri->y || check_line(line) < 0)
	return (multifree(clean_gnl(-1, fd) + close(fd), 1, line));
      if (str_len(line) > tetri->x)
	return (multifree(clean_gnl(-1, fd) + close(fd), 1, line));
      tetri->shape[0].data[i++] = line;
    }
  return (0);
}

void		parse_files(t_list **list)
{
  t_list	*cur;
  t_list	*del;

  cur = *list;
  while (cur != NULL)
    {
      del = NULL;
      if (use_file(cur) < 0)
	  del = cur;
      cur = cur->next;
      if (del != NULL)
	delete(list, del);
    }
}

char		rotate(t_tetrimino *t, int i)
{
  char		trig;
  char		c;
  t_vec		c1;

  t->shape[i].w = t->shape[i - 1].h;
  t->shape[i].h = t->shape[i - 1].w;
  if ((t->shape[i].data = new_tab(t->shape[i].w, t->shape[i].h)) == NULL)
    return (-1);
  c1.y = -1;
  while (++c1.y < t->shape[i - 1].h)
    {
      c1.x = -1;
      trig = 0;
      while (++c1.x < t->shape[i - 1].w)
	{
	  if (!trig && t->shape[i - 1].data[c1.y][c1.x] == '\0')
	    trig = 1;
	  c = trig ? ' ' : t->shape[i - 1].data[c1.y][c1.x];
	  t->shape[i].data[c1.x][t->shape[i].w - (c1.y + 1)] = c;
	}
    }
  return (0);
}

t_tetrimino	*get_tetriminos()
{
  int		i;
  int		a;
  t_tetrimino	*res;
  t_list	*lst;

  i = 0;
  if (get_file_list(&lst) < 0)
    return (NULL);
  sort_list(&lst);
  parse_files(&lst);
  if ((res = malloc(sizeof(t_tetrimino) * (list_size(lst) + 1))) == NULL)
    return (NULL);
  while (lst != NULL)
    {
      a = -1;
      while (++a < 4)
	{
	  if (a > 0 && rotate(&lst->tetri, a) < 0)
	    return (NULL);
	}
      res[i++] = lst->tetri;
      delete(&lst, lst);
    }
  res[i].shape = NULL;
  return (res);
}

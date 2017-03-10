/*
** pointers.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/parsing/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Mar  3 20:44:18 2017 Arthur Baurens
** Last update Tue Mar  7 18:04:43 2017 Arthur Baurens
*/

#include <stdarg.h>
#include <stdlib.h>
#include "tetris.h"
#include "get_next_line.h"

int	clean_gnl(int ret, int fd)
{
  char	*line;

  while ((line = get_next_line(fd)))
    free(line);
  return (ret);
}

int		multifree(int ret, int nb, ...)
{
  int		i;
  va_list	lst;
  void		*ptr;

  i = -1;
  if (nb == 0)
    return (ret);
  va_start(lst, nb);
  while (++i < nb)
    {
      ptr = va_arg(lst, void *);
      free(ptr);
    }
  va_end(lst);
  return (ret);
}

char		**new_tab(int w, int h)
{
  int		i;
  char		**res;

  i = -1;
  if ((res = malloc(sizeof(char *) * (h + 1))) == NULL)
    return (NULL);
  res[h] = NULL;
  while (++i < h)
    {
      if ((res[i] = malloc(sizeof(char) * (w + 1))) == NULL)
	{
	  while (--i >= 0)
	    free(res[i]);
	  free(res);
	  return (NULL);
	}
      res[i][w] = '\0';
    }
  return (res);
}

void	delete_tetri_tab(t_tetrimino *tetr)
{
  int	i;
  int	a;
  int	j;

  i = -1;
  while (tetr[++i].shape != 0)
    {
      a = -1;
      while (++a < 4)
	{
	  j = -1;
	  while (++j < tetr[i].shape[a].h)
	    free(tetr[i].shape[a].data[j]);
	  free(tetr[i].shape[a].data);
	}
      free(tetr[i].shape);
    }
  free(tetr);
}

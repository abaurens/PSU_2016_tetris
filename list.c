/*
** list.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Mar  3 16:27:16 2017 Arthur Baurens
** Last update Tue Mar  7 17:13:26 2017 Arthur Baurens
*/

#include <stdlib.h>
#include "tetris.h"

int	list_size(t_list *list)
{
  int	i;

  i = 0;
  while (list != NULL)
    {
      i++;
      list = list->next;
    }
  return (i);
}

char		add(t_list **list, const char *name)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (-1);
  if ((elem->data = my_strncat(name, NULL, 0)) == NULL)
    {
      free(elem);
      return (-1);
    }
  elem->prev = NULL;
  elem->next = *list;
  if (elem->next != NULL)
    elem->next->prev = elem;
  *list = elem;
  return (0);
}

void	delete(t_list **list, t_list *elem)
{
  if (elem == *list)
    *list = elem->next;
  if (elem->next != NULL)
    elem->next->prev = elem->prev;
  if (elem->prev != NULL)
    elem->prev->next = elem->next;
  free(elem->data);
  free(elem);
}

void		sort_list(t_list **list)
{
  t_list	*cur;
  char		trig;
  t_tetrimino	t;
  char		*d;

  trig = 1;
  while (trig)
    {
      trig = 0;
      cur = *list;
      while (cur != NULL && cur->next != NULL)
	{
	  if (my_strcmp(cur->data, cur->next->data) > 0)
	    {
	      d = cur->data;
	      t = cur->tetri;
	      cur->data = cur->next->data;
	      cur->tetri = cur->next->tetri;
	      cur->next->data = d;
	      cur->next->tetri = t;
	      trig = 1;
            }
	  cur = cur->next;
	}
    }
}

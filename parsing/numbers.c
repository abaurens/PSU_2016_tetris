/*
** numbers.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/parsing/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Mar  3 20:22:43 2017 Arthur Baurens
** Last update Fri Mar  3 21:33:05 2017 Arthur Baurens
*/

#include "limits.h"

int	get_number(const char *num)
{
  int	i;
  long	nb;

  i = -1;
  nb = 0;
  while (num[++i] >= '0' && num[i] <= '9')
    {
      nb *= 10;
      nb += num[i] - '0';
      if (nb > INT_MAX)
	return (0);
    }
  return (nb);
}

int	is_num(const char *str)
{
  int	i;

  i = 0;
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  return (i);
}

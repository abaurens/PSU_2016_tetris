/*
** string.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Mar  3 16:48:21 2017 Arthur Baurens
** Last update Tue Mar  7 17:33:16 2017 Arthur Baurens
*/

#include <unistd.h>
#include <stdlib.h>

int	str_len(const char *str)
{
  int	i;

  i = -1;
  while (str && str[++i]);
  return ((str != NULL) * i);
}

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = -1;
  while (s1[++i])
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
    }
  return (s1[i] - s2[i]);
}

char	end_with(const char *name, const char *ref)
{
  int		i;
  int		j;

  i = str_len(name);
  j = str_len(ref);
  while (--i >= 0 && --j >= 0)
    {
      if (name[i] != ref[j])
	return (0);
    }
  return (1);
}

char	*my_strncat(const char *s1, const char *s2, int n)
{
  int	i;
  int	j;
  int	len;
  char	*res;

  i = 0;
  j = -1;
  len = str_len(s1) + str_len(s2);
  if (len > n && n > 0)
    len = n;
  if (len <= 0 || (res = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  res[len] = '\0';
  while (s1 && s1[i] && i < len)
    {
      res[i] = s1[i];
      i++;
    }
  while (s2 && s2[++j] && i + j < len)
    res[i + j] = s2[j];
  return (res);
}

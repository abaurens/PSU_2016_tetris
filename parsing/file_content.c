/*
** file_content.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/parsing/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Tue Mar  7 17:33:55 2017 Arthur Baurens
** Last update Tue Mar  7 17:42:45 2017 Arthur Baurens
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "tetris.h"
#include "get_next_line.h"

char	is_valid_header(const char *line, t_tetrimino *tetri)
{
  int	i;
  int	j;

  j = 0;
  if ((i = is_num(line)) <= 0)
    return (-1);
  tetri->x = get_number(line);
  j += (i + 1);
  if (line[j - 1] != ' ' || (i = is_num(&line[j])) <= 0)
    return (-1);
  tetri->y = get_number(&line[j]);
  j += (i + 1);
  if (line[j - 1] != ' ' || (i = is_num(&line[j])) <= 0)
    return (-1);
  tetri->color = get_number(&line[j]);
  if (line[j + i] != '\0')
    return (-1);
  return (0);
}

char	check_line(char *line)
{
  int	i;
  char	phase;

  phase = 0;
  i = str_len(line);
  while (--i >= 0)
    {
      if (line[i] == '*')
	phase = 1;
      else if (line[i] != ' ')
	return (-1);
      else if (!phase && line[i] == ' ')
	line[i] = '\0';
    }
  return (0);
}

char	use_file(t_list *elem)
{
  int	fd;
  char	*line;

  if ((fd = open(elem->data, O_RDONLY)) < 0)
    return (-1);
  if ((line = get_next_line(fd)) == NULL)
    return (close(fd) - 1);
  if (is_valid_header(line, &elem->tetri) < 0)
    return (multifree(clean_gnl(-1, fd) + close(fd), 1, line));
  free(line);
  return (file_to_tetri(fd, &elem->tetri));
}

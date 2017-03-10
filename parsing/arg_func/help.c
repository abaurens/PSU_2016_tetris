/*
** help.c for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/parsing/arg_func/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed Mar  8 15:10:06 2017 Arthur Baurens
** Last update Thu Mar  9 15:12:27 2017 Arthur Baurens
*/

#include <unistd.h>
#include "tetris.h"

char	help(t_tetris *tetris, char *arg)
{
  UNUSED(arg);
  UNUSED(tetris);
  write(1, "Usage:  ./tetris [options]\n", 27);
  write(1, "Options:\n", 9);
  write(1, "   --help               Display this help\n", 42);
  write(1, "   -l --level={num}     Start Tetris at level num (def: 1)\n", 59);
  write(1, "   -kl --key-left={K}   Move the tetrimino LEFT using the K ", 60);
  write(1, "key (def: left arrow)\n", 22);
  write(1, "   -kr --key-right={K}  Move the tetrimino RIGHT using the K", 60);
  write(1, " key (def: right arrow)\n", 24);
  write(1, "   -kt --key-turn={K}   TURN the tetrimino clockwise 90d ", 57);
  write(1, "using the K key (def: top arrow)\n", 33);
  write(1, "   -kd --key-drop={K}   DROP the tetrimino using the K", 54);
  write(1, " key (def: down arrow)\n", 23);
  write(1, "   -kq --key-quit={K}   QUIT the game using the K ", 50);
  write(1, "key (def: 'Q' key)\n", 19);
  write(1, "   -kp --key-pause={K}  PAUSE/RESTART the game using the K", 58);
  write(1, " key (def: space bar)\n", 22);
  write(1, "   --map-size={row,col} Set the numbers of rows and columns", 59);
  write(1, " of the map (def: 20,10)\n", 25);
  write(1, "   -w --without-next    Hide next tetrimino (def: false)\n", 57);
  write(1, "   -d --debug           Debug mode (def: false)\n", 48);
  return (1);
}

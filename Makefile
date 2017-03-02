##
## Makefile for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Thu Mar  2 16:39:38 2017 Arthur Baurens
## Last update Thu Mar  2 16:43:29 2017 Arthur Baurens
##

CC		=		gcc

NAME	=		tetris

SRC		=		main.c					\
					get_next_line.c

OBJ		=		$(SRC:.c=.o)

INCLUDE	=	-I./include

CFLAGS	+=	$(INCLUDE) -g -W -Wall -Wextra -ansi -pedantic

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

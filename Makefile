##
## Makefile for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Thu Mar  2 16:39:38 2017 Arthur Baurens
## Last update Tue Mar  7 17:39:18 2017 Arthur Baurens
##

CC		=		gcc

NAME	=		tetris

SRC		=		main.c									\
					list.c									\
					get_next_line.c					\
					parsing/string.c				\
					parsing/numbers.c				\
					parsing/parsing.c				\
					parsing/pointers.c			\
					parsing/file_content.c

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

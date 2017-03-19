##
## Makefile for tetris in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_tetris/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Thu Mar  2 16:39:38 2017 Arthur Baurens
## Last update Sun Mar 19 19:36:31 2017 Arthur Baurens
##

CC		=		gcc

NAME	=		tetris

SRC		=		main.c									              \
					list.c									              \
					game.c																\
					rules.c																\
					display.c															\
					get_next_line.c					              \
					parsing/debug.c												\
					parsing/string.c				              \
					parsing/numbers.c				              \
					parsing/parsing.c				              \
					parsing/pointers.c			              \
					parsing/parse_opt.c			              \
					parsing/file_content.c								\
					parsing/arg_func/debug.c							\
					parsing/arg_func/help.c								\
					parsing/arg_func/level.c              \
					parsing/arg_func/key_left.c           \
					parsing/arg_func/key_turn.c           \
					parsing/arg_func/key_drop.c           \
					parsing/arg_func/key_quit.c           \
					parsing/arg_func/map_size.c           \
					parsing/arg_func/key_right.c          \
					parsing/arg_func/key_pause.c					\
					parsing/arg_func/without_next.c


OBJ		=		$(SRC:.c=.o)

INCLUDE	=	-I./include

CFLAGS	+=	$(INCLUDE) -g -W -Wall -Wextra -pedantic

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

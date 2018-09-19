##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## My_Cook
##

SRC	=	src/event.c	\
		src/init.c	\
		src/main.c	\
		src/map.c	\
		src/utils.c	\
		src/utils2.c

OBJ	=	$(SRC:.c=.o)

NAME	=	map_editor

CFLAGS	=	-W -Wall -Wextra -Iinc

LDFLAGS	=	-l c_graph_prog 

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re

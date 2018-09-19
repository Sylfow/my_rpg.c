##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CFLAGS	+=	-I./include/ -I./include/inc_map/ -I./include/inc_fight/ -W -Wall -Wextra

SRC	=	source/animation.c				\
		source/create.c					\
		source/destroy.c				\
		source/display.c				\
		source/get_next_line.c				\
		source/event.c					\
		source/hunter.c					\
		source/info.c					\
		source/init.c					\
		source/init_stats.c				\
		source/main.c					\
		source/mouse.c					\
		source/str.c					\
		source/time_move.c				\
		source/utils.c					\
		source/verif_save.c				\
		source/str2.c					\
		source/src_map/animation.c			\
		source/src_map/change_zone.c			\
		source/src_map/check_dialog.c			\
		source/src_map/collision.c			\
		source/src_map/destroy.c			\
		source/src_map/dialog.c				\
		source/src_map/event.c				\
		source/src_map/event_dialog.c			\
		source/src_map/event_game.c			\
		source/src_map/init.c				\
		source/src_map/init2.c				\
		source/src_map/load.c				\
		source/src_map/my_rpg.c				\
		source/src_map/move.c				\
		source/src_map/mouse_menu.c			\
		source/src_map/map.c				\
		source/src_map/pause.c				\
		source/src_map/quest.c				\
		source/src_map/utils.c				\
		source/src_fight/mouse_fight_switch.c		\
		source/src_fight/mouse_fight.c			\
		source/src_fight/init_boss.c			\
		source/src_fight/init.c				\
		source/src_fight/finish.c			\
		source/src_fight/fight_boss.c			\
		source/src_fight/fight.c			\
		source/src_fight/event.c			\
		source/src_fight/display.c			\
		source/src_fight/damage2.c			\
		source/src_fight/damage.c			\
		source/src_fight/animations.c			\
		source/src_fight/all_attack.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lc_graph_prog
	make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur

.PHONY:	all clean fclean re

/*
** EPITECH PROJECT, 2018
** event.c
** File description:
** event
*/

#include "my_rpg.h"

int p_move = 5;

void event_all(window_t *win, player_t *player, map_t *map, dialog_t *dialog)
{
	while (sfRenderWindow_pollEvent(win->win, &win->event)) {
		if (win->event.type == sfEvtKeyPressed) {
			if (win->event.key.code == sfKeyLShift) {
				p_move = 10;
				player->time_max = 0.1;
			}
			switch_key(win, player, map, dialog);
		}
		if (win->event.type == sfEvtKeyReleased) {
			if (win->event.key.code == sfKeyLShift) {
				p_move = 5;
				player->time_max = 0.2;
			}
		}
		if (win->num_scene > 0)
			event_button_menu(win, player);
	}
}

void switch_key(window_t *win, player_t *player, map_t *map, dialog_t *dialog)
{
	switch (win->event.key.code) {
	case sfKeyEscape:
		if (win->num_scene == 0) {
			set_pos_pause(win);
			win->num_scene = 1;
		} else if (win->num_scene == 1)
			win->num_scene = 0;
		break;
	case sfKeyQ:
		get_quest(win, player, dialog);
		break;
	default:
		if (win->num_scene == 0)
			event_key_game(win, player, map);
		break;
	}
}

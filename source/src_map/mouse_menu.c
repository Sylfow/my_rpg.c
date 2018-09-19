/*
** EPITECH PROJECT, 2018
** mouse_menu.c
** File description:
** mouse_menu
*/

#include "main.h"

void action_pause(window_t *win, player_t *player, int i)
{
	switch (i) {
	case 0:
		win->num_scene = 0;
		break;
	case 2:
		win->save = 1;
		save(player);
		break;
	case 3:
		win->nb_scene = 0;
		break;
	}
}

void switch_rect(button_t *pause, int left)
{
	pause->rect = set_rect(
		pause->rect.top, left, pause->rect.width, pause->rect.height);
	sfRectangleShape_setTextureRect(pause->rect_s, pause->rect);
}

void event_button_menu(window_t *win, player_t *player)
{
	sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(win->win);

	pos_mouse.x += win->pos_screen.x;
	pos_mouse.y += win->pos_screen.y;
	for (int i = 0; i < 4; i++) {
		if (button_is_clicked(&win->pause.buttons[i], pos_mouse)) {
			switch_rect(&win->pause.buttons[i], 200);
			if (win->event.type == sfEvtMouseButtonPressed)
				action_pause(win, player, i);
		} else
			switch_rect(&win->pause.buttons[i], 0);
	}
}

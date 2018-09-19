/*
** EPITECH PROJECT, 2018
** event.c
** File description:
** event
*/

#include "main.h"

int event_main_menu(window_t *win, scene_t *scene, player_t *player)
{
	int button = 0;

	while (sfRenderWindow_pollEvent(win->win, &win->event)) {
		if (win->event.type == sfEvtKeyPressed)
			event_key_main_menu(win, scene, player);
		else if (win->nb_scene == 5 && win->event.type == sfEvtMouseButtonPressed)
			win->nb_scene = 0;
		else {
			if (win->nb_scene == 0 || win->nb_scene == 4)
				button = event_button_main_menu(
					win, scene->buttons, scene->nb_buttons);
		}
	}
	return (button);
}

void event_key_main_menu(window_t *win, scene_t *scene, player_t *player)
{
	if (win->event.key.code == sfKeyEscape)
		sfRenderWindow_close(win->win);
	else if (win->event.key.code == sfKeyReturn && win->nb_scene == 3) {
		sfSprite_setColor(scene->obj[1].sprite, sfWhite);
		scene->obj[2].pos.y = 602;
		sfSprite_setPosition(
			scene->obj[2].sprite, scene->obj[2].pos);
		my_rpg(win, player);
	}
}

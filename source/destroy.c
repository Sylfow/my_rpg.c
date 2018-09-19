/*
** EPITECH PROJECT, 2018
** destroy.c
** File description:
** destroy
*/

#include "main.h"

void destroy_rect_shape(button_t *buttons, int nb_buttons)
{
	for (int i = 0; i < nb_buttons; i++)
		sfRectangleShape_destroy(buttons[i].rect_s);
}

void destroy_objs(game_objs_t *objs, int nb_objs)
{
	for (int i = 0; i < nb_objs; i++) {
		sfSprite_destroy(objs[i].sprite);
		sfClock_destroy(objs[i].clock);
	}
}

void destroy(window_t *win, scene_t *scene)
{
	for (int i = 0; i < 5; i++) {
		destroy_rect_shape(scene[i].buttons, scene[i].nb_buttons);
		destroy_objs(scene[i].obj, scene[i].nb_objs);
	}
	sfView_destroy(win->view);
	sfMusic_destroy(win->music);
	sfRenderWindow_destroy(win->win);
}

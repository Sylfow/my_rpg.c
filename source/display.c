/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** display
*/

#include "main.h"

void display_rect_shape(window_t *win, button_t *buttons, int nb_buttons)
{
	for (int i = 0; i < nb_buttons; i++)
		sfRenderWindow_drawRectangleShape(
			win->win, buttons[i].rect_s, NULL);
}

void display_objs(window_t *win, game_objs_t *objs, int nb_objs)
{
	for (int i = 0; i < nb_objs; i++)
		sfRenderWindow_drawSprite(
			win->win, objs[i].sprite, NULL);
}

void display(window_t *win, scene_t *scene)
{
	sfRenderWindow_clear(win->win, sfBlack);
	sfRenderWindow_setView(win->win, win->view);
	display_objs(win, scene->obj, scene->nb_objs);
	display_rect_shape(win, scene->buttons, scene->nb_buttons);
	sfRenderWindow_display(win->win);
}

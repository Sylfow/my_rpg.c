/*
** EPITECH PROJECT, 2018
** hunter
** File description:
** hunter for rpg scenario
*/

#include "main.h"

void move_ducky(game_objs_t *obj, int x, int y, int max_x)
{
	sfVector2f vector = {x, y};
	sfVector2f origin = {-110, 190};

	if (sfSprite_getPosition(obj->sprite).x >= max_x)
		sfSprite_setPosition(obj->sprite, origin);
	sfSprite_move(obj->sprite, vector);
}

void handle_events(window_t *win, game_objs_t *ducky, sfVector2f size)
{
	while (sfRenderWindow_pollEvent(win->win, &win->event)) {
		if (win->event.type == sfEvtClosed)
			sfRenderWindow_close(win->win);
		if (win->event.type == sfEvtMouseButtonPressed)
			if (zone_is_clicked(sfSprite_getPosition(ducky->sprite),
					size, sfMouse_getPositionRenderWindow(win->win))) {
				win->nb_scene = 3;
			}
	}
}

void mini_hunter(window_t *win, scene_t *scene)
{
	handle_events(win, &scene->obj[1], (sfVector2f) {110, 110});
	move_ducky(&scene->obj[1], 5, 0, 1000);
	animate(&scene->obj[1], 0.15, 220, 110);
}

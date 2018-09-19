/*
** EPITECH PROJECT, 2018
** event.c
** File description:
** event
*/

#include "fight_boss.h"

void event_fight(window_t *win, scene_t *scene, fight_t *fight, game_objs_t *obj)
{
	while (sfRenderWindow_pollEvent(win->win, &win->event))
		mouse_menu_fight(win, scene, fight, obj);
}

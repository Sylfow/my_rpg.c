/*
** EPITECH PROJECT, 2018
** mouse_fight_switch.c
** File description:
** mouse_fight_switch
*/

#include "fight_boss.h"

void deselect_all_buttons(scene_t *scene)
{
	for (int i = 0; i < scene->nb_buttons; i++) {
		scene->buttons[i].rect.left = 0;
		sfRectangleShape_setTextureRect(
			scene->buttons[i].rect_s, scene->buttons[i].rect);
	}
}

void deselect_all_mobs(game_objs_t *obj, fight_t *fight)
{
	for (int i = 0; i < fight->nb_mobs; i++)
		sfSprite_setColor(obj[i].sprite, sfWhite);
}

void switch_color(window_t *win, scene_t *scene, game_objs_t *obj, int on)
{
	for (int i = 0; i < scene->nb_buttons; i++) {
		if (scene->buttons[i].rect.left == 200 && win->fight_scene == 1) {
			if (on == 0)
				sfSprite_setColor(obj->sprite, sfWhite);
			else
				sfSprite_setColor(obj->sprite, sfYellow);
		}
	}
}

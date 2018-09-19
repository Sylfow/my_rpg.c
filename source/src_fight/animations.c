/*
** EPITECH PROJECT, 2018
** animation.c
** File description:
** animation
*/

#include "fight_boss.h"

void animate_spe(game_objs_t *obj, float sec_max, int max_left, int left)
{
	sfTime time = sfClock_getElapsedTime(obj->clock);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > sec_max) {
		if (obj->rect.left >= max_left) {
			obj->rect.left = 0;
			obj->rect.top += 400;
		} else
			obj->rect.left += left;
		sfSprite_setTextureRect(obj->sprite, obj->rect);
		sfClock_restart(obj->clock);
	}
}

void animate_duck(game_objs_t *obj, float sec_max, int left)
{
	sfTime time = sfClock_getElapsedTime(obj->clock);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > sec_max) {
		obj->rect.left += left;
		sfSprite_setTextureRect(obj->sprite, obj->rect);
		sfClock_restart(obj->clock);
	}
}

void time_clock(sfClock *clock, float sec_max)
{
	sfTime time;
	float seconds = 0;

	sfClock_restart(clock);
	while (seconds < sec_max) {
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 1000000.0;
	}
}

/*
** EPITECH PROJECT, 2018
** time_move.c
** File description:
** time_move
*/

#include "main.h"

void time_move_up(game_objs_t *obj, float sec, int move)
{
	sfTime time = sfClock_getElapsedTime(obj->clock);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > sec) {
		obj->pos.y -= move;
		sfSprite_setPosition(obj->sprite, obj->pos);
		sfClock_restart(obj->clock);
	}

}

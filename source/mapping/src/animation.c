/*
** EPITECH PROJECT, 2018
** animation.c
** File description:
** animation
*/

#include "main.h"

void animate_player(player_t *player)
{
	sfTime time = sfClock_getElapsedTime(player->clock);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > player->time_max) {
		if (player->rect.left >= 434)
			player->rect.left = 0;
		else
			player->rect.left += 62;
		sfSprite_setTextureRect(player->sprite, player->rect);
		sfClock_restart(player->clock);
	}
}

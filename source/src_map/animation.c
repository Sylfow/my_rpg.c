/*
** EPITECH PROJECT, 2018
** animation.c
** File description:
** animation
*/

#include "my_rpg.h"

int get_rect_left(int top, int left)
{
	if (top < 74)
		left += 49;
	else
		left += 37;
	return (left);
}

void animate_player(player_t *player)
{
	sfTime time = sfClock_getElapsedTime(player->clock);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > player->time_max) {
		if (player->rect.left >= 196 && player->rect.top <= 37)
			player->rect.left = 0;
		else if (player->rect.left >= 148 && player->rect.top >= 74)
			player->rect.left = 0;
		else {
			player->rect.left = get_rect_left(
				player->rect.top, player->rect.left);
		}
		sfSprite_setTextureRect(player->sprite, player->rect);
		sfClock_restart(player->clock);
	}
}

void set_new_rect(player_t *player, int top, int width, int height)
{
	if (player->rect.top != top)
		player->rect.left = 0;
	player->rect.top = top;
	player->rect.width = width;
	player->rect.height = height;
	sfSprite_setTextureRect(player->sprite, player->rect);
}

void clock_start_fight(window_t *win)
{
	sfTime time = sfClock_getElapsedTime(win->clock);
	float seconds = time.microseconds / 1000000.0;
	sfVector2f pos_v = {-win->pos_screen.x, -win->pos_screen.y};

	if (seconds > 5) {
		sfView_move(win->view, pos_v);
		win->num_scene = 2;
		sfClock_restart(win->clock);
	}
}

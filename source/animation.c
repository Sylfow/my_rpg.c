/*
** EPITECH PROJECT, 2018
** animation.c
** File description:
** animation
*/

#include "main.h"

void animate(game_objs_t *obj, float sec_max, int max_left, int left)
{
	sfTime time = sfClock_getElapsedTime(obj->clock);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > sec_max) {
		if (obj->rect.left >= max_left)
			obj->rect.left = 0;
		else
			obj->rect.left += left;
		sfSprite_setTextureRect(obj->sprite, obj->rect);
		sfClock_restart(obj->clock);
	}
}

void animate_height(game_objs_t *obj, float sec_max, int min_height, int height)
{
	sfTime time = sfClock_getElapsedTime(obj->clock);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > sec_max && obj->rect.height > min_height) {
		obj->rect.height -= height;
		sfSprite_setTextureRect(obj->sprite, obj->rect);
		sfClock_restart(obj->clock);
	}
}

void animate_all(game_objs_t *obj, float sec_max, int move)
{
	sfTime time = sfClock_getElapsedTime(obj->clock);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > sec_max && obj->pos.x > 0 && obj->pos.y > 0) {
		obj->pos.x -= 1;
		obj->pos.y -= 1;
		if (obj->rect.width < 1000)
			obj->rect.width += move + 1;
		if (obj->rect.height < 600)
			obj->rect.height += move + 1;
		sfSprite_setTextureRect(obj->sprite, obj->rect);
		sfSprite_setPosition(obj->sprite, obj->pos);
		sfClock_restart(obj->clock);
	}
}

void set_opacity(game_objs_t *obj, float sec_max)
{
	sfTime time = sfClock_getElapsedTime(obj->clock);
	float seconds = time.microseconds / 1000000.0;
	sfColor color = {255, 255, 255, 255};

	if (seconds > sec_max && sfSprite_getColor(obj->sprite).a > 0) {
		color.a = sfSprite_getColor(obj->sprite).a;
		color.a -= 5;
		sfSprite_setColor(obj->sprite, color);
		sfClock_restart(obj->clock);
	}
}

void animate_rainbow(game_objs_t *obj, float sec_max)
{
	sfTime time = sfClock_getElapsedTime(obj->clock);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > sec_max && obj->rect.width < 1000) {
		obj->rect.width += 10;
		sfSprite_setTextureRect(obj->sprite, obj->rect);
		sfClock_restart(obj->clock);
	}
}

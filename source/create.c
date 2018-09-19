/*
** EPITECH PROJECT, 2018
** create.c
** File description:
** create
*/

#include "main.h"

void create_rect_shape(button_t *rectShape, char *path, int x, int y)
{
	sfTexture *texture = sfTexture_createFromFile(path, NULL);

	rectShape->rect_s = sfRectangleShape_create();
	sfRectangleShape_setTexture(rectShape->rect_s, texture, sfTrue);
	rectShape->pos = set_vector(x, y);
	sfRectangleShape_setPosition(rectShape->rect_s, rectShape->pos);
}

void create_obj(game_objs_t *obj, char *path, int x, int y)
{
	sfTexture *texture = sfTexture_createFromFile(path, NULL);

	obj->sprite = sfSprite_create();
	sfSprite_setTexture(obj->sprite, texture, sfTrue);
	obj->pos = set_vector(x, y);
	sfSprite_setPosition(obj->sprite, obj->pos);
	obj->clock = sfClock_create();
}

sfVector2f set_vector(int x, int y)
{
	sfVector2f vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

sfIntRect set_rect(int top, int left, int width, int height)
{
	sfIntRect rect;

	rect.top = top;
	rect.left = left;
	rect.width = width;
	rect.height = height;
	return (rect);
}

void set_size(button_t *button, int width, int height)
{
	sfRectangleShape_setSize(
		button->rect_s, (sfVector2f) {width, height});
}

/*
** EPITECH PROJECT, 2018
** destroy.c
** File description:
** destroy
*/

#include "my_rpg.h"

void destroy_all(window_t *win, map_t *map, player_t *player)
{
	free(map->name_map);
	free(map->map_file);
	sfRectangleShape_destroy(win->load.rect_s);
	sfText_destroy(win->load.text);
	for (int i = 0; i < 4; i++)
		sfRectangleShape_destroy(win->pause.buttons[i].rect_s);
	sfTexture_destroy(player->texture);
	sfSprite_destroy(player->sprite);
	sfClock_destroy(player->clock);
	sfSprite_destroy(map->layer.sprite);
}

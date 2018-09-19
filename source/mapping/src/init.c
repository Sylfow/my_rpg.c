/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** init
*/

#include "main.h"

void init_objs(screen_t *screen, game_objs_t *obj, int x, int y)
{
	obj->sprite = sfSprite_create();
	sfSprite_setTexture(obj->sprite, screen->texture, sfTrue);
	sfSprite_setTextureRect(obj->sprite, screen->rect);
	obj->pos.x = x;
	obj->pos.y = y;
	sfSprite_setPosition(obj->sprite, obj->pos);
}

void init_all_objs(screen_t *screen, game_objs_t *objs, int *map)
{
	int nb = 0;

	for (int j = 0; j < NB_OHEIGHT; j++)
		for (int i = 0; i < NB_OWIDTH; i++) {
                        screen->rect.left = map[nb] * O_SIZE;
                        init_objs(screen, &objs[nb], O_SIZE * i, O_SIZE * j);
                        nb++;
                }
}

void init_screen(screen_t *screen)
{
	sfVector2f vec = {WIDTH, HEIGHT};
	sfVector2f vec2 = {WIDTH / 2, HEIGHT / 2};

	screen->win = create_window("Map");
	screen->pos_screen.x = 0;
	screen->pos_screen.y = 0;
	screen->texture = sfTexture_createFromFile(
		"utils/img/spritesheet2.png", NULL);
	screen->rect.top = 0;
	screen->rect.width = O_SIZE;
	screen->rect.height = O_SIZE;
	screen->view = sfView_create();
	sfView_setSize(screen->view, vec);
	sfView_setCenter(screen->view, vec2);
}

void init_player(player_t *player)
{
	player->texture = sfTexture_createFromFile(
		"utils/img/luffy_spritesheet.png", NULL);
	player->sprite = sfSprite_create();
	sfSprite_setTexture(player->sprite, player->texture, sfTrue);
	player->rect.left = 0;
	player->rect.top = 0;
	player->rect.width = 62;
	player->rect.height = 55;
	sfSprite_setTextureRect(player->sprite, player->rect);
	player->pos.x = WIDTH / 2;
	player->pos.y = HEIGHT / 2;
	sfSprite_setPosition(player->sprite, player->pos);
	player->clock = sfClock_create();
	player->time_max = 0.2;
	player->can_move = 1;
}

void init_all(screen_t *screen, game_objs_t *objs, int *map, player_t *player)
{
	init_screen(screen);
	init_player(player);
	init_all_objs(screen, objs, map);
}

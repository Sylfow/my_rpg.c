/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** init
*/

#include "my_rpg.h"

void set_block_pixel(sfImage *img, sfImage *img2, int *map, int x, int y)
{
	sfColor color;

	for (int j = 0; j < O_SIZE; j++)
		for (int i = 0; i < O_SIZE; i++) {
			color = sfImage_getPixel(
				img2, i + O_SIZE * (map[x + y * NB_OWIDTH] % 8), j + O_SIZE * (map[x + y * NB_OWIDTH] / 8));
			sfImage_setPixel(
				img, i + x * O_SIZE, j + y * O_SIZE, color);
		}
}

sfSprite *init_img(int *map, window_t *win)
{
	sfImage *img = sfImage_create(WIDTH_MAP, HEIGHT_MAP);
	sfImage *img2 = sfImage_createFromFile("utils/img/spritesheet2.png");
	sfTexture *texture;
	sfSprite *sprite = sfSprite_create();
	static int first = 0;

	for (int y = 0; y < NB_OHEIGHT; y++) {
		if (y % 5 == 0 && first == 0) {
			load_bar(&win->load);
			display_load(win);
		}
		for (int x = 0; x < NB_OWIDTH; x++)
			set_block_pixel(img, img2, map, x, y);
	}
	texture = sfTexture_createFromImage(img, NULL);
	sfImage_destroy(img);
	sfImage_destroy(img2);
	sfSprite_setTexture(sprite, texture, sfTrue);
	win->load.size.x = 5;
	if (first == 0)
		first = 1;
	return (sprite);
}

void init_screen(window_t *win)
{
	sfVector2f vec = {WIDTH, HEIGHT};
	sfVector2f vec2 = {WIDTH / 2, HEIGHT / 2};

	win->num_scene = 0;
	sfView_setSize(win->view, vec);
	sfView_setCenter(win->view, vec2);
	init_pause(&win->pause);
	win->name = malloc(sizeof(char) * 12);
	init_load(&win->load);
}

void init_player(player_t *player, int *stats)
{
	player->texture = sfTexture_createFromFile(
		"utils/img/persoduck.png", NULL);
	player->sprite = sfSprite_create();
	sfSprite_setTexture(player->sprite, player->texture, sfTrue);
	player->rect = set_rect(0, 0, 49, 37);
	sfSprite_setTextureRect(player->sprite, player->rect);
	player->pos = set_vector(stats[14], stats[15]);
	sfSprite_setPosition(player->sprite, player->pos);
	player->clock = sfClock_create();
	player->hp = malloc(sizeof(button_t) * 2);
	create_rect_shape_color(&player->hp[0], sfRed, WIDTH - 250, 10);
	create_rect_shape_color(&player->hp[1], sfBlack, WIDTH - 255, 5);
	player->hp[0].size.x = 220 - (stats[2] - stats[3]) * (220 / stats[2]);
	player->hp[0].size.y = 20;
	sfRectangleShape_setSize(player->hp[0].rect_s, player->hp[0].size);
	player->hp[1].size.x = 230;
	player->hp[1].size.y = 30;
	sfRectangleShape_setSize(player->hp[1].rect_s, player->hp[1].size);
	player->time_max = 0.2;
	player->can_move = 1;
}

void init_all(map_t *map, player_t *player, window_t *win, int *stats)
{
	init_player(player, stats);
	map->layer.sprite = init_img(map->map_file, win);
	map->layer.pos = set_vector(0, 0);
}

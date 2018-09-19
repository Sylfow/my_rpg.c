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

void init_screen(screen_t *screen)
{
	sfVector2f vec = {WIDTH, HEIGHT};
	sfVector2f vec2 = {WIDTH / 2, HEIGHT / 2};

	screen->win = create_window("Map_Editor");
	screen->pos_screen.x = 0;
	screen->pos_screen.y = 0;
	screen->texture = sfTexture_createFromFile("img/spritesheet2.png", NULL);
	screen->rect.top = 0;
	screen->rect.width = O_SIZE;
	screen->rect.height = O_SIZE;
	screen->view = sfView_create();
        sfView_setSize(screen->view, vec);
        sfView_setCenter(screen->view, vec2);
}

void init_all(screen_t *screen, game_objs_t *objs, int *map)
{
	int nb = 0;

	init_screen(screen);
	for (int j = 0; j < NB_OHEIGHT; j++)
		for (int i = 0; i < NB_OWIDTH; i++) {
			screen->rect.left = map[nb] * O_SIZE;
			init_objs(screen, &objs[nb], O_SIZE * i, O_SIZE * j);
			nb++;
		}
	screen->rect.left = 50;
}

void set_texture(screen_t *screen, game_objs_t *objs, int *map)
{
	sfVector2i clickPos = sfMouse_getPositionRenderWindow(screen->win);

	clickPos.x += screen->pos_screen.x;
	clickPos.y += screen->pos_screen.y;
	for (int i = 0; i < NB_OBJS; i++)
		if (obj_is_clicked(&objs[i], clickPos)) {
			sfSprite_setTextureRect(objs[i].sprite, screen->rect);
			map[i] = screen->rect.left / O_SIZE;
		}
}

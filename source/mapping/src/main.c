/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "main.h"

sfRenderWindow *create_window(char *name)
{
	sfVideoMode mode = {WIDTH, HEIGHT, 32};
	sfRenderWindow *win;

	win = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(win, 60);
	return (win);
}

void display_all(screen_t *screen, game_objs_t *objs, player_t *player)
{
	sfRenderWindow_clear(screen->win, sfBlack);
	sfRenderWindow_setView(screen->win, screen->view);
	for (int i = 0; i < NB_OBJS; i++)
		sfRenderWindow_drawSprite(screen->win, objs[i].sprite, NULL);
	sfRenderWindow_drawSprite(screen->win, player->sprite, NULL);
	sfRenderWindow_display(screen->win);
}

void destroy_all(screen_t *screen, game_objs_t *objs)
{
	sfTexture_destroy(screen->texture);
	for (int i = 0; i < NB_OBJS; i++)
		sfSprite_destroy(objs[i].sprite);
	sfRenderWindow_destroy(screen->win);
}

int main(int ac, char **av)
{
	screen_t screen;
	game_objs_t *objs = malloc(sizeof(game_objs_t) * NB_OBJS);
	player_t player;
	int *map;

	if (ac != 2)
		return (84);
	map = create_map(av[1]);
	all_game(&screen, objs, map, &player);
	free(map);
	free(objs);
	return (0);
}

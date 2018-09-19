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

void display_all(screen_t *screen, game_objs_t *objs)
{
	sfRenderWindow_clear(screen->win, sfBlack);
	sfRenderWindow_setView(screen->win, screen->view);
	for (int i = 0; i < NB_OBJS; i++)
		sfRenderWindow_drawSprite(screen->win, objs[i].sprite, NULL);
	sfRenderWindow_display(screen->win);
}

void destroy_all(screen_t *screen, game_objs_t *objs)
{
	sfTexture_destroy(screen->texture);
	for (int i = 0; i < NB_OBJS; i++)
		sfSprite_destroy(objs[i].sprite);
	sfRenderWindow_destroy(screen->win);
}

int obj_is_clicked(game_objs_t *obj, sfVector2i clickPos)
{
	return (clickPos.x < sfSprite_getPosition(obj->sprite).x + O_SIZE &&
		clickPos.x > sfSprite_getPosition(obj->sprite).x &&
		clickPos.y < sfSprite_getPosition(obj->sprite).y + O_SIZE &&
		clickPos.y > sfSprite_getPosition(obj->sprite).y);
}

int main(int ac, char **av)
{
	screen_t screen;
	game_objs_t *objs = malloc(sizeof(game_objs_t) * NB_OBJS);
	int *map;

	if (ac != 3) {
		display_help();
		return (84);
	}
	if (char_to_int(av[2]) == 0)
		map = create_map();
	else if (char_to_int(av[2]) == 1)
		map = test(av[1]);
	else {
		display_help();
		return (84);
	}
	all_game(&screen, objs, map, av[1]);
	return (0);
}

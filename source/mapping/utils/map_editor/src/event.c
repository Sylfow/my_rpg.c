/*
** EPITECH PROJECT, 2018
** event.c
** File description:
** event
*/

#include "main.h"

void all_game(screen_t *screen, game_objs_t *objs, int *map, char *name)
{
	init_all(screen, objs, map);
	while (sfRenderWindow_isOpen(screen->win)) {
		display_all(screen, objs);
		event_all(screen, objs, map);
	}
	set_map_in_file(map, name);
	destroy_all(screen, objs);
}

void event_all(screen_t *screen, game_objs_t *objs, int *map)
{
	while (sfRenderWindow_pollEvent(screen->win, &screen->event)) {
		if (screen->event.type == sfEvtKeyPressed) {
			switch_key(screen);
		} else if (screen->event.type == sfEvtMouseButtonPressed)
			set_texture(screen, objs, map);
	}
}

void switch_key(screen_t *screen)
{
	switch (screen->event.key.code) {
	case sfKeyEscape:
		sfRenderWindow_close(screen->win);
		break;
	case sfKeyA:
		screen->rect.left = 0;
		break;
	case sfKeyZ:
		screen->rect.left = 50;
		break;
	case sfKeyE:
		screen->rect.left = 100;
		break;
	default:
		switch_move(screen);
		switch_move2(screen);
		break;
	}
}

void switch_move(screen_t *screen)
{
	sfVector2f up = {0, -O_SIZE};
	sfVector2f down = {0, O_SIZE};

	switch (screen->event.key.code) {
	case sfKeyUp:
		if (screen->pos_screen.y > 0) {
			sfView_move(screen->view, up);
			screen->pos_screen.y -= O_SIZE;
		}
		break;
	case sfKeyDown:
		if (screen->pos_screen.y + O_SIZE + HEIGHT <= HEIGHT_MAP) {
			sfView_move(screen->view, down);
			screen->pos_screen.y += O_SIZE;
		}
		break;
	default:
		break;
	}
}

void switch_move2(screen_t *screen)
{
	sfVector2f left = {-O_SIZE, 0};
	sfVector2f right = {O_SIZE, 0};

	switch (screen->event.key.code) {
	case sfKeyLeft:
		if (screen->pos_screen.x > 0) {
			sfView_move(screen->view, left);
			screen->pos_screen.x -= O_SIZE;
		}
		break;
	case sfKeyRight:
		if (screen->pos_screen.x + O_SIZE + WIDTH <= WIDTH_MAP) {
			sfView_move(screen->view, right);
			screen->pos_screen.x += O_SIZE;
		}
		break;
	default:
		break;
	}
}

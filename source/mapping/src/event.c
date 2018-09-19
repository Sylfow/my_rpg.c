/*
** EPITECH PROJECT, 2018
** event.c
** File description:
** event
*/

#include "main.h"

int p_move = 5;

void all_game(screen_t *screen, game_objs_t *objs, int *map, player_t *player)
{
	init_all(screen, objs, map, player);
	while (sfRenderWindow_isOpen(screen->win)) {
		display_all(screen, objs, player);
		event_all(screen, player, objs, map);
		animate_player(player);
		player->can_move = 1;
	}
	destroy_all(screen, objs);
}

void event_all(screen_t *screen, player_t *player, game_objs_t *objs, int *map)
{
	while (sfRenderWindow_pollEvent(screen->win, &screen->event)) {
		if (screen->event.type == sfEvtKeyPressed) {
			if (screen->event.key.code == sfKeyLShift) {
				p_move = 10;
				player->time_max = 0.1;
			}
			switch_key(screen, player, objs, map);
		}
		if (screen->event.type == sfEvtKeyReleased) {
			if (screen->event.key.code == sfKeyLShift) {
				p_move = 5;
				player->time_max = 0.2;
			}
		}
	}
}

void switch_key(screen_t *screen, player_t *player, game_objs_t *objs, int *map)
{
	switch (screen->event.key.code) {
	case sfKeyEscape:
		sfRenderWindow_close(screen->win);
		break;
	case sfKeyI:
		if (interact(map, (int) player->pos.x / O_SIZE +
			     (int) player->pos.y / O_SIZE * NB_OHEIGHT) == 1)
			my_putstr("Interact\n");
		break;
	case sfKeyM:
		free(map);
		map = create_map("map");
		init_all_objs(screen, objs, map);
		break;
	default:
		switch_move(screen, player, objs, map);
		switch_move2(screen, player, objs, map);
		sfSprite_setPosition(player->sprite, player->pos);
		break;
	}
}

void switch_move(screen_t *screen, player_t *player, game_objs_t *objs, int *map)
{
	switch (screen->event.key.code) {
	case sfKeyUp:
		if (player->pos.y > 0 && player->can_move == 1
		    && collision(map, player->pos.x / O_SIZE +
				 (player->pos.y / O_SIZE - 1) * NB_OHEIGHT) == 1) {
			player->can_move = 0;
			move_up(player, screen, objs);
		}
		break;
	case sfKeyDown:
		if (player->pos.y + O_SIZE < HEIGHT_MAP
		    && player->can_move == 1
		    && collision(map, player->pos.x / O_SIZE +
				 (player->pos.y / O_SIZE + 1) * NB_OHEIGHT) == 1) {
			player->can_move = 0;
			move_down(player, screen, objs);
		}
		break;
	default:
		break;
	}
}

void switch_move2(screen_t *screen, player_t *player, game_objs_t *objs, int *map)
{
	switch (screen->event.key.code) {
	case sfKeyLeft:
		if (player->pos.x > 0 && player->can_move == 1
		    && collision(map, player->pos.x / O_SIZE - 1 +
				 player->pos.y / O_SIZE * NB_OHEIGHT) == 1) {
			player->can_move = 0;
			move_left(player, screen, objs);
		}
		break;
	case sfKeyRight:
		if (player->pos.x < WIDTH_MAP - O_SIZE
		    && player->can_move == 1
		    && collision(map, player->pos.x / O_SIZE + 1 +
				 player->pos.y / O_SIZE * NB_OHEIGHT) == 1) {
			player->can_move = 0;
			move_right(player, screen, objs);
		}
		break;
	default:
		break;
	}
}

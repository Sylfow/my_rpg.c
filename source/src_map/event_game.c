/*
** EPITECH PROJECT, 2018
** event_game.c
** File description:
** event_game
*/

#include "my_rpg.h"

void event_key_game(window_t *win, player_t *player, map_t *map)
{
	switch (win->event.key.code) {
	case sfKeyI:
		if (interact(map, (int) player->pos.x / O_SIZE +
			     (int) player->pos.y / O_SIZE * NB_OHEIGHT) == 1)
			my_putstr("Interact\n");
		break;
	default:
		switch_move_up(win, player, map);
		sfSprite_setPosition(player->sprite, player->pos);
		break;
	}
}

void switch_move_up(window_t *win, player_t *p, map_t *map)
{
	switch (win->event.key.code) {
	case sfKeyUp:
		set_new_rect(p, 0, 49, 37);
		if (p->pos.y > 0 && p->can_move == 1
		    && collision(map, p, p->pos.x / O_SIZE +
				 (p->pos.y / O_SIZE - 1) * NB_OHEIGHT) == 1) {
			p->can_move = 0;
			move_up(p, win, &map->layer);
		}
		break;
	default:
		switch_move_down(win, p, map);
		break;
	}
}

void switch_move_down(window_t *win, player_t *p, map_t *map)
{
	switch (win->event.key.code) {
	case sfKeyDown:
		set_new_rect(p, 37, 49, 37);
		if (p->pos.y + O_SIZE < HEIGHT_MAP && p->can_move == 1
		    && collision(map, p, p->pos.x / O_SIZE +
				 (p->pos.y / O_SIZE + 1) * NB_OHEIGHT) == 1) {
			p->can_move = 0;
			move_down(p, win, &map->layer);
		}
		break;
	default:
		switch_move_left(win, p, map);
		break;
	}
}

void switch_move_left(window_t *win, player_t *p, map_t *map)
{
	switch (win->event.key.code) {
	case sfKeyLeft:
		set_new_rect(p, 123, 37, 49);
		if (p->pos.x > 0 && p->can_move == 1
		    && collision(map, p, p->pos.x / O_SIZE - 1 +
				 p->pos.y / O_SIZE * NB_OHEIGHT) == 1) {
			p->can_move = 0;
			move_left(p, win, &map->layer);
		}
		break;
	default:
		switch_move_right(win, p, map);
		break;
	}
}

void switch_move_right(window_t *win, player_t *p, map_t *map)
{
	switch (win->event.key.code) {
	case sfKeyRight:
		set_new_rect(p, 74, 37, 49);
		if (p->pos.x < WIDTH_MAP - O_SIZE && p->can_move == 1
		    && collision(map, p, p->pos.x / O_SIZE + 1 +
				 p->pos.y / O_SIZE * NB_OHEIGHT) == 1) {
			p->can_move = 0;
			move_right(p, win, &map->layer);
		}
		break;
	default:
		break;
	}
}

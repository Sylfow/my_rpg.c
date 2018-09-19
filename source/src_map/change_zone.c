/*
** EPITECH PROJECT, 2018
** change_zone.c
** File description:
** change_zone
*/

#include "my_rpg.h"

int set_stats_num_map2(int n_map, sfVector2f pos)
{
	switch (n_map) {
	case 2:
		if (pos.x == 1100 && pos.y == 700)
			return (1);
		else if (pos.x == 3400 && pos.y == 2350)
			return (3);
		break;
	case 3:
		if (pos.x == 650 && pos.y == 1000)
			return (2);
		break;
	}
	return (-1);
}

int set_stats_num_map(int n_map, sfVector2f pos)
{
	switch (n_map) {
	case 0:
		if (pos.x == 1200 && pos.y == 400)
			return (2);
		else if (pos.x == 550 && pos.y == 500)
			return (1);
		break;
	case 1:
		if (pos.x == 1450 && pos.y == 500)
			return (0);
		break;
	default:
		return (set_stats_num_map2(n_map, pos));
	}
	return (-1);
}

void set_new_pos_player2(player_t *p, int n_map)
{
	switch (n_map) {
	case 2:
		if (p->pos.x == 1100 && p->pos.y == 700)
			p->pos = set_vector(1050, 1000);
		else if (p->pos.x == 3400 && p->pos.y == 2350)
			p->pos = set_vector(650, 900);
		break;
	case 3:
		if (p->pos.x == 650 && p->pos.y == 1000)
			p->pos = set_vector(3400, 2400);
		break;
	}
}

void set_new_pos_player(player_t *p, int n_map)
{
	switch (n_map) {
	case 0:
		if (p->pos.x == 1200 && p->pos.y == 400)
			p->pos = set_vector(1800, 800);
		else if (p->pos.x == 550 && p->pos.y == 500)
			p->pos = set_vector(1450, 550);
		break;
	case 1:
		if (p->pos.x == 1450 && p->pos.y == 500)
			p->pos = set_vector(550, 450);
		break;
	default:
		set_new_pos_player2(p, n_map);
		break;
	}
	sfSprite_setPosition(p->sprite, p->pos);
}

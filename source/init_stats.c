/*
** EPITECH PROJECT, 2018
** init_stats.c
** File description:
** init_stats
*/

#include "main.h"

void init_stats2(player_t *player)
{
	for (int i = 17; i < 27; i++)
		player->stats[i] = 0;
}

void init_stats(player_t *player)
{
	player->stats[0] = 1;
	player->stats[1] = 0;
	player->stats[2] = 55;
	player->stats[3] = 55;
	player->stats[4] = 20;
	player->stats[5] = 20;
	player->stats[6] = 15;
	player->stats[7] = 15;
	player->stats[8] = 30;
	player->stats[9] = 30;
	player->stats[10] = 15;
	player->stats[11] = 15;
	player->stats[12] = 0;
	player->stats[13] = 0;
	player->stats[14] = 550;
	player->stats[15] = 450;
	player->stats[16] = 1;
	init_stats2(player);
}

/*
** EPITECH PROJECT, 2018
** init_boss.c
** File description:
** init_boss
*/

#include "fight_boss.h"

void set_up_boss(carac_t *mob)
{
	spell_initialize(&mob->tackle, 50, 50, 0);
	spell_initialize(&mob->shoot, 35, 35, 0);
	spell_initialize(&mob->fireball, 10, 20, 15);
}

void setup_boss(carac_t *enemy)
{
	enemy->stats[0] = 5;
	enemy->stats[1] = my_rand(1 * enemy->stats[0], 10 * enemy->stats[0]);
	enemy->stats[2] = 60;
	enemy->stats[3] = enemy->stats[2];
	enemy->stats[4] = 15;
	enemy->stats[5] = enemy->stats[4];
	enemy->stats[6] = 20;
	enemy->stats[7] = enemy->stats[6];
	enemy->stats[8] = 20;
	enemy->stats[9] = enemy->stats[8];
	enemy->stats[10] = 15;
	enemy->stats[11] = enemy->stats[10];
	enemy->stats[12] = my_rand(1 + enemy->stats[0], 20 + enemy->stats[0]);
	set_up_boss(enemy);
}

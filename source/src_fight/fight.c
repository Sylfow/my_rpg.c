/*
** EPITECH PROJECT, 2018
** fight.c
** File description:
** fight
*/

#include "fight_boss.h"

void set_up_player(carac_t *mob)
{
	spell_initialize(&mob->tackle, 90, 50, 0);
	spell_initialize(&mob->shoot, 85, 65, 0);
	spell_initialize(&mob->fireball, 70, 100, 15);
}

void set_up_enemy(carac_t *mob)
{
	spell_initialize(&mob->tackle, 20, 15, 0);
	spell_initialize(&mob->shoot, 35, 35, 0);
	spell_initialize(&mob->fireball, 10, 20, 15);
}

void setup_player(carac_t *player, int *stats)
{
	player->name = malloc(sizeof(char) * 4);
	player->name = my_strcpy(player->name, "Inspecteur Magret");
	player->stats = malloc(sizeof(int) * NB_STATS);
	player->stats[0] = stats[0];
	player->stats[1] = stats[1];
	player->stats[2] = stats[2];
	player->stats[3] = stats[3];
	player->stats[4] = stats[4];
	player->stats[5] = stats[5];
	player->stats[6] = stats[6];
	player->stats[7] = stats[7];
	player->stats[8] = stats[8];
	player->stats[9] = stats[9];
	player->stats[10] = stats[10];
	player->stats[11] = stats[11];
	player->stats[12] = stats[12];
	set_up_player(player);
}

void setup_enemy(carac_t *enemy)
{
	enemy->name = malloc(sizeof(char) * 4);
	enemy->name = my_strcpy(enemy->name, "Dog");
	enemy->stats = malloc(sizeof(int) * NB_STATS);
	enemy->stats[0] = my_rand(1, 5);
	enemy->stats[1] = my_rand(1 * enemy->stats[0], 10 * enemy->stats[0]);
	enemy->stats[2] = my_rand(35, 55);
	enemy->stats[3] = enemy->stats[2];
	enemy->stats[4] = my_rand(10, 20);
	enemy->stats[5] = enemy->stats[4];
	enemy->stats[6] = my_rand(15, 25);
	enemy->stats[7] = enemy->stats[6];
	enemy->stats[8] = my_rand(20, 30);
	enemy->stats[9] = enemy->stats[8];
	enemy->stats[10] = my_rand(5, 15);
	enemy->stats[11] = enemy->stats[10];
	enemy->stats[12] = my_rand(1 + enemy->stats[0], 20 + enemy->stats[0]);
	set_up_enemy(enemy);
}

void basic_fight(window_t *win, player_t *player, map_t *map)
{
	scene_t *scene = malloc(sizeof(scene_t) * 2);
	game_objs_t *obj;
	fight_t fight;

	fight.nb_mobs = rand() % 3 + 1;
	obj = malloc(sizeof(game_objs_t) * (fight.nb_mobs + 2));
	all_setup_fight(win, scene, &fight, obj);
	setup_player(&fight.player, player->stats);
	setup_enemy(&fight.enemy);
	while (win->num_scene == 2) {
		display_fight(win, obj, &scene[win->fight_scene], &fight);
		play_fight_boss(win, scene, &fight, obj);
		test_finish_fight(win, &fight, player, map);
	}
	set_new_stats(&fight.player, player);
	destroy_fight(win, obj);
}

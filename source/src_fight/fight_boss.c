/*
** EPITECH PROJECT, 2018
** fight_boss.c
** File description:
** fight_boss
*/

#include "fight_boss.h"

void switch_boss(window_t *win, game_objs_t *obj, scene_t *scene, fight_t *fight)
{
	while (obj[2].rect.top != 1377) {
		if (obj[2].rect.top == 0) {
			obj[2].rect = set_rect(177, 0, 367, 400);
			sfSprite_setTextureRect(obj[2].sprite, obj[2].rect);
			obj[2].pos = set_vector(50, 50);
			sfSprite_setPosition(obj[2].sprite, obj[2].pos);
		}
		if (obj[2].rect.top == 177)
			animate_spe(&obj[2], 0.2, 1835, 367);
		if (obj[2].rect.top == 577)
			animate_spe(&obj[2], 0.2, 734, 367);
		if (obj[2].rect.top == 977) {
			animate_spe(&obj[2], 0.2, 2202, 367);
		}
		fight->pv_bar[1].size.x += 2;
		sfRectangleShape_setSize(
			fight->pv_bar[1].rect_s, fight->pv_bar[1].size);
		display_fight(win, obj, scene, fight);
	}
}

void boss_attack(window_t *win, scene_t *scene, fight_t *fight, game_objs_t *obj, int i)
{
	obj[i].pos.x += 200;
	sfSprite_setPosition(obj[i].sprite, obj[i].pos);
	display_fight(win, obj, scene, fight);
	time_clock(obj[i].clock, 0.5);
	obj[i].pos.x -= 200;
	sfSprite_setPosition(obj[i].sprite, obj[i].pos);
	display_fight(win, obj, scene, fight);
	time_clock(obj[i].clock, 0.5);
}

void spell_initialize(spell_b *spell, int miss, int damage, int mana)
{
	spell->precision = miss;
	spell->power = damage;
	spell->mana = mana;
}

void play_fight_boss(window_t *win, scene_t *scene, fight_t *fight, game_objs_t *obj)
{
	if (fight->turn == 0)
		event_fight(win, &scene[win->fight_scene], fight, obj);
	else {
		for (int i = 2; i < fight->nb_mobs; i++) {
			time_clock(obj[i].clock, 0.3);
			fight->spell = 1;
			boss_attack(win, &scene[win->fight_scene], fight, obj, i);
			if (obj[1].rect.top != 552)
				player_take_damage(win, scene, fight, obj);
			else
				animate(&obj[1], 0.2, 278, 278);
			time_clock(obj[i].clock, 0.3);
			obj[1].rect = set_rect(0, 140, 255, 170);
			sfSprite_setTextureRect(obj[1].sprite, obj[1].rect);
		}
		fight->turn = 0;
	}
}

void boss_change(window_t *win, scene_t *scene, fight_t *fight, game_objs_t *obj)
{
	if (fight->pv_bar[1].size.x <= 0) {
		switch_boss(win, obj, scene, fight);
		fight->pv_bar[0].size.x = fight->pv_bar[1].size.x;
		sfRectangleShape_setSize(
			fight->pv_bar[0].rect_s, fight->pv_bar[0].size);
		setup_boss(&fight->enemy);
	} else if (obj[2].rect.top == 1377)
		animate(&obj[2], 0.3, 748, 374);
}

void fight_boss(window_t *win, player_t *player, map_t *map)
{
	scene_t *scene = malloc(sizeof(scene_t) * 2);
	game_objs_t *obj = malloc(sizeof(game_objs_t) * 3);
	fight_t fight;
	sfVector2f pos_v = {-win->pos_screen.x, -win->pos_screen.y};

	sfView_move(win->view, pos_v);
	all_setup_boss(win, scene, &fight, obj);
	setup_player(&fight.player, player->stats);
	setup_enemy(&fight.enemy);
	while (win->num_scene == 4) {
		display_fight(win, obj, &scene[win->fight_scene], &fight);
		play_fight_boss(win, scene, &fight, obj);
		boss_change(win, scene, &fight, obj);
		test_finish_fight(win, &fight, player, map);
	}
	set_new_stats(&fight.player, player);
	destroy_fight(win, obj);
	player->stats[24] = 1;
}

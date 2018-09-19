/*
** EPITECH PROJECT, 2018
** all_attack.c
** File description:
** all_attack
*/

#include "fight_boss.h"

void attack1(window_t *win, scene_t *scene, fight_t *fight, game_objs_t *obj)
{
	obj[1].rect = set_rect(170, -260, 370, 205);
	sfSprite_setTextureRect(obj[1].sprite, obj[1].rect);
	while (obj[1].rect.left <= 850) {
		display_fight(win, obj, scene, fight);
		animate_duck(&obj[1], 0.2, 370);
	}
	obj[1].rect = set_rect(0, 140, 255, 170);
	sfSprite_setTextureRect(obj[1].sprite, obj[1].rect);
	fight->spell = 1;
	if (fight->who_take_dmg == 1)
		player_take_damage(win, scene, fight, obj);
	else
		boss_take_damage(win, scene, fight, obj);
	fight->turn = 1;
}

void attack2(window_t *win, scene_t *scene, fight_t *fight, game_objs_t *obj)
{
	obj[1].rect = set_rect(380, -390, 390, 175);
	sfSprite_setTextureRect(obj[1].sprite, obj[1].rect);
	while (obj[1].rect.left <= 780) {
		display_fight(win, obj, scene, fight);
		animate_duck(&obj[1], 0.2, 390);
	}
	obj[1].rect = set_rect(0, 140, 255, 170);
	sfSprite_setTextureRect(obj[1].sprite, obj[1].rect);
	fight->spell = 2;
	if (fight->who_take_dmg == 1)
		player_take_damage(win, scene, fight, obj);
	else
		boss_take_damage(win, scene, fight, obj);
	fight->turn = 1;
}

void attack3(fight_t *fight, game_objs_t *obj)
{
	obj->rect = set_rect(552, 0, 278, 182);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	fight->turn = 1;
}

void attack4(window_t *win, scene_t *scene, fight_t *fight, game_objs_t *obj)
{
	obj[0].pos = set_vector(100, 0);
	sfSprite_setPosition(obj[0].sprite, obj[0].pos);
	obj[0].rect = set_rect(0, 0, 500, 400);
	sfSprite_setTextureRect(obj[0].sprite, obj[0].rect);
	while (obj[0].rect.top <= 800) {
		display_fight(win, obj, scene, fight);
		animate_duck(&obj[0], 0.2, 500);
		if (obj[0].rect.left >= 2000) {
			obj[0].rect.left = 0;
			obj[0].rect.top += 400;
			sfSprite_setTextureRect(obj[0].sprite, obj[0].rect);
		}
	}
	obj[0].pos = set_vector(1100, 0);
	sfSprite_setPosition(obj[0].sprite, obj[0].pos);
	fight->spell = 3;
	if (fight->who_take_dmg == 2)
		boss_take_damage(win, scene, fight, obj);
	else
		player_take_damage(win, scene, fight, obj);
	fight->turn = 1;
}

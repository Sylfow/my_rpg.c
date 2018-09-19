/*
** EPITECH PROJECT, 2018
** damage.c
** File description:
** damage
*/

#include "fight_boss.h"

int critical_hit(void)
{
	int a = my_rand(1, 16);

	if (a == 1) {
		return (2);
	} else
		return (1);
}

int my_rand(int min, int max)
{
	return (rand() % (max - min) + min);
}

int calcul_damage(carac_t *cast, carac_t *target, spell_b spell, button_t *pv_bar)
{
	int damage;

	if (my_rand(0, 100) < spell.precision) {
		damage = (((((cast->stats[2] * 40 + 2) * cast->stats[7]
			* spell.power) / (target->stats[9] * 50))+ 2)
			* my_rand(85, 100) * critical_hit()) / 10000;
		target->stats[3] = target->stats[3] - damage;
		pv_bar->size.x -= pv_bar->size.x - 200 *
			((float)target->stats[3]
			/ (float) target->stats[2]);
		if (target->stats[3] < 0) {
			target->stats[3] = 0;
			pv_bar->size.x = 0;
		}
		sfRectangleShape_setSize(
			pv_bar->rect_s, pv_bar->size);
		return (1);
	} else
		return (0);
}

void boss_take_damage(window_t *win, scene_t *scene, fight_t *fight, game_objs_t *obj)
{
	int touch = 0;

	touch = set_damage(
		&fight->player, &fight->enemy, &fight->pv_bar[1], fight->spell);
	if (touch == 1) {
		for (int i = 0; i < 2; i++) {
			sfSprite_setColor(obj[fight->who_take_dmg].sprite, sfRed);
			display_fight(win, obj, scene, fight);
			time_clock(obj[fight->who_take_dmg].clock, 0.1);
			sfSprite_setColor(obj[fight->who_take_dmg].sprite, sfWhite);
			display_fight(win, obj, scene, fight);
			time_clock(obj[fight->who_take_dmg].clock, 0.1);
		}
		
	}
}

void player_take_damage(window_t *win, scene_t *scene, fight_t *fight, game_objs_t *obj)
{
	int touch = 0;

	touch = set_damage(
		&fight->enemy, &fight->player, &fight->pv_bar[3], fight->spell);
	if (touch == 1) {
		obj[1].rect = set_rect(903, 165, 240, 235);
		sfSprite_setTextureRect(obj[1].sprite, obj[1].rect);
		display_fight(win, obj, scene, fight);
	}
}

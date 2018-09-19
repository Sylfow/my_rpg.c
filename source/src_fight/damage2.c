/*
** EPITECH PROJECT, 2018
** damage2.c
** File description:
** damage2
*/

#include "fight_boss.h"

int set_damage(carac_t *cast, carac_t *target, button_t *pv_bar, int spell)
{
	int touch = 0;

	switch (spell) {
	case 1:
		touch = calcul_damage(cast, target, cast->tackle, pv_bar);
		break;
	case 2:
		touch = calcul_damage(cast, target, cast->shoot, pv_bar);
		break;
	case 3:
		touch = calcul_damage(cast, target, cast->fireball, pv_bar);
		break;
	}
	return (touch);
}

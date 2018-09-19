/*
** EPITECH PROJECT, 2018
** init_attack
** File description:
** init attack
*/

#include "main.h"

void init_attack(player_s *player)
{
	int a_f = open("attack.dns", O_RDONLY);

	if (a_f == -1) {
		a_f = open("attacK.dns", O_CREAT | O_TRUNC | O_RDWR, S_IRUSR |
			S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	}
	putstr_fd("1|40|90|0|1|75|80|5|0|120|20", a_f);
}

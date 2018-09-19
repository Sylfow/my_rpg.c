/*
** EPITECH PROJECT, 2018
** collision.c
** File description:
** collision
*/

#include "main.h"

int collision(int *map, int nb)
{
	if (map[nb] == 1)
		return (0);
	else
		return (1);
}

int check_interact(int *map, int nb)
{
	if (nb < 0)
		nb = 0;
	else if (nb > NB_OWIDTH * NB_OHEIGHT - 1)
		nb = NB_OWIDTH * NB_OHEIGHT - 1;
	if (map[nb] == 2)
		return (1);
	else
		return (0);
}

int interact(int *map, int nb)
{
	int nb_case[5];

	nb_case[0] = nb - 1;
	nb_case[1] = nb + 1;
	nb_case[2] = nb - NB_OWIDTH;
	nb_case[3] = nb + NB_OWIDTH;
	nb_case[4] = -1;

	for (int i = 0; nb_case[i] != -1; i++)
		if (check_interact(map, nb_case[i]) == 1)
			return (1);
	return (0);
}

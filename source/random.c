/*
** EPITECH PROJECT, 2018
** random
** File description:
** random number
*/

#include "main.h"

unsigned int my_time(void)
{
	int *temp = malloc(sizeof(int) * 3);
	unsigned long size = 0;

	size = (unsigned long) temp;
	free(temp);
	return ((unsigned int) size / 1000000);
}

int my_rand(int min, int max)
{
	return (rand() % (max - min) + min);
}

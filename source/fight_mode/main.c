/*
** EPITECH PROJECT, 2018
** main
** File description:
** main test for fight mode
*/

#include "my_fight.h"

unsigned int my_time(void)
{
	int *temp = malloc(sizeof(int) * 3);
	unsigned long size = 0;

	size = (unsigned long) temp;
	free(temp);
	return ((unsigned int) size / 1000000);
}

int random_number(int min, int max)
{
	return (rand() % (max - min) + min);
}

int main(void)
{
	fight ft;

	creat_window(&ft, "fight_mode", 1920, 1080);
	creat_sprite(&ft);
	start_music(&ft);
	srand(my_time());
	ft.clock = sfClock_create();
	if (!ft.window) {
		return (84);
	}
	open_window(&ft);
	destroy(&ft);
	return (0);
}

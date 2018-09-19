/*
** EPITECH PROJECT, 2018
** start_music
** File description:
** playing music for fighting mode
*/

#include "my_fight.h"

void start_music(fight *ft)
{
	ft->music = sfMusic_createFromFile("Stuff/Battle.ogg");
	sfMusic_play(ft->music);
	sfMusic_setLoop(ft->music, sfTrue);
	sfMusic_setVolume(ft->music, 50);
}

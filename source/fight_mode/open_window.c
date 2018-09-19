/*
** EPITECH PROJECT, 2018
** open_window
** File description:
** open_window of fighting mode
*/

#include "my_fight.h"

void draw_sprite(fight *ft)
{
	if (sfRenderWindow_isOpen(ft->window)) {
		sfRenderWindow_drawSprite(ft->window, ft->bg->sprite, NULL);
		sfRenderWindow_display(ft->window);
	}
}

void open_window(fight *ft)
{
	while (sfRenderWindow_isOpen(ft->window)) {
		pollevent(ft);
		draw_sprite(ft);
	}
}

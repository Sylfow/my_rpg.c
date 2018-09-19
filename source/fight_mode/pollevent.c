/*
** EPITECH PROJECT, 2018
** pollevent
** File description:
** event in fight mode
*/

#include "my_fight.h"

void pollevent(fight *ft)
{
	while (sfRenderWindow_pollEvent(ft->window, &ft->event)) {
		if (ft->event.key.code == sfKeyEscape
		    || ft->event.type == sfEvtClosed)
			sfRenderWindow_close(ft->window);
	}
}

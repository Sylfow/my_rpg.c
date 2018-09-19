/*
** EPITECH PROJECT, 2018
** check_dialog.c
** File description:
** check_dialog
*/

#include "my_rpg.h"

void start_dialog(window_t *win, dialog_t *dialog, int *talk, char *name)
{
	if (*talk == 0) {
		dialog->name = my_strcpy_map(name);
		set_text_dialog(win, dialog);
		win->num_scene = 3;
		*talk = 1;
	}
}

void check_dialog2(window_t *win, player_t *p, dialog_t *dialog)
{
	switch (p->stats[13]) {
	case 2:
		if (p->pos.x == 1800 && p->pos.y == 800)
			start_dialog(win, dialog, &p->stats[21], "dialog5");
		break;
	case 3:
		if (p->pos.x == 650 && p->pos.y == 900)
			start_dialog(win, dialog, &p->stats[22], "dialog6");
		else if (p->pos.x == 650 && p->pos.y == 400)
			start_dialog(win, dialog, &p->stats[23], "dialog7");
		else if (p->stats[24] == 1 && p->stats[25] == 0)
			start_dialog(win, dialog, &p->stats[25], "dialog8");
	}
}

void check_dialog(window_t *win, player_t *p, dialog_t *dialog)
{
	switch (p->stats[13]) {
	case 0:
		if (p->pos.x == 550 && p->pos.y == 450)
			start_dialog(win, dialog, &p->stats[17], "dialog1");
		else if (p->pos.x == 1200 && p->pos.y == 400)
			start_dialog(win, dialog, &p->stats[20], "dialog4");
		break;
	case 1:
		if (p->pos.x == 1450 && p->pos.y == 550)
			start_dialog(win, dialog, &p->stats[18], "dialog2");
		else if ((p->pos.x == 1050 || p->pos.x == 1100)
		  && p->pos.y == 1150)
			start_dialog(win, dialog, &p->stats[19], "dialog3");
		break;
	default:
		check_dialog2(win, p, dialog);
		break;
	}
}

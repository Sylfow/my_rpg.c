/*
** EPITECH PROJECT, 2018
** quest.c
** File description:
** quest
*/

#include "my_rpg.h"

void set_dialog_quest(window_t *win, dialog_t *dialog, char *name)
{
	dialog->name = my_strcpy_map(name);
	set_text_dialog(win, dialog);
	win->num_scene = 3;
}

void quest(window_t *win, dialog_t *dialog, int nb_quest)
{
	switch(nb_quest) {
	case 0:
		set_dialog_quest(win, dialog, "quest1");
		break;
	case 1:
		set_dialog_quest(win, dialog, "quest2");
		break;
	case 2:
		set_dialog_quest(win, dialog, "quest3");
		break;
	case 4:
		set_dialog_quest(win, dialog, "quest4");
		break;
	case 5:
		set_dialog_quest(win, dialog, "quest5");
		break;
	case 6:
		set_dialog_quest(win, dialog, "quest6");
		break;
	}
}

void get_quest(window_t *win, player_t *p, dialog_t *dialog)
{
	int nb_quest = 0;

	for (int i = 18; i < 24; i++) {
		if (p->stats[i] == 0)
			break;
		nb_quest++;
	}
	quest(win, dialog, nb_quest);
}

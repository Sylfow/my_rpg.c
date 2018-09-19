/*
** EPITECH PROJECT, 2018
** mouse.c
** File description:
** mouse
*/

#include "main.h"

int event_button_main_menu(window_t *win, button_t *buttons, int nb_buttons)
{
	sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(win->win);
	int button = 0;

	pos_mouse.x += win->pos_screen.x;
	pos_mouse.y += win->pos_screen.y;
	for (int i = 0; i < nb_buttons; i++) {
		if (button_is_clicked(&buttons[i], pos_mouse)) {
			buttons[i].rect = set_rect(
				buttons[i].rect.top, 250, 250, 50);
			if (win->event.type == sfEvtMouseButtonPressed)
				button = action_mouse(win, &buttons[i]);
		} else
			buttons[i].rect = set_rect(
				buttons[i].rect.top, 0, 250, 50);
		sfRectangleShape_setTextureRect(
			buttons[i].rect_s, buttons[i].rect);
	}
	return (button);
}

int action_mouse(window_t *win, button_t *button)
{
	switch (button->id) {
	case 0:
		win->nb_scene = 1;
		return (1);
	case 1:
		return (2);
	case 2:
		return (3);
	case 3:
		sfRenderWindow_close(win->win);
		break;
	}
	return (0);
}

void do_action(window_t *win, scene_t *scene, player_t *player, int new)
{
	switch (new) {
	case 3:
		win->nb_scene = 5;
		break;
	case 2:
		sfSprite_setTexture(scene[1].obj[1].sprite, sfTexture_createFromImage(sfRenderWindow_capture(win->win), NULL), sfTrue);
		init_stats(player);
		win->nb_scene = 1;
		break;
	case 1:
		my_rpg(win, player);
	}
}

int button_is_clicked(button_t *button, sfVector2i clickPos)
{
	return (clickPos.x < sfRectangleShape_getPosition(button->rect_s).x +
		sfRectangleShape_getSize(button->rect_s).x &&
		clickPos.x > sfRectangleShape_getPosition(button->rect_s).x &&
		clickPos.y < sfRectangleShape_getPosition(button->rect_s).y +
		sfRectangleShape_getSize(button->rect_s).y &&
		clickPos.y > sfRectangleShape_getPosition(button->rect_s).y);
}

int zone_is_clicked(sfVector2f pos, sfVector2f size, sfVector2i clickPos)
{
	return (clickPos.x < pos.x + size.x && clickPos.x > pos.x &&
		clickPos.y < pos.y + size.y && clickPos.y > pos.y);
}

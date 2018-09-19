/*
** EPITECH PROJECT, 2018
** mouse_fight.c
** File description:
** mouse_fight
*/

#include "fight_boss.h"

void action_fight(window_t *win, scene_t *scene, fight_t *fight, game_objs_t *obj)
{
	for (int i = 0; i < scene->nb_buttons; i++) {
		if (scene->buttons[i].rect.left == 200) {
			switch (scene->buttons[i].id) {
			case 0:
				attack1(win, scene, fight, obj);
				break;
			case 1:
				attack2(win, scene, fight, obj);
				break;
			case 2:
				attack3(fight, &obj[1]);
				break;
			case 3:
				attack4(win, scene, fight, obj);
				break;
			}
			win->fight_scene = 0;
		}
	}
}

void action_menu_fight(window_t *win, button_t *button)
{
	switch (button->id) {
	case 0:
		win->fight_scene = 1;
		break;
	case 1:
		win->num_scene = 0;
		break;
	}
}

void mouse_scene_fight(window_t *win, button_t *button)
{
	if (win->fight_scene == 1) {
		button->rect.left = 200;
		sfRectangleShape_setTextureRect(
			button->rect_s, button->rect);
	} else
		action_menu_fight(win, button);
}

void mouse_fight_buttons(window_t *win, scene_t *scene, sfVector2i pos_mouse)
{
	for (int i = 0; i < scene->nb_buttons; i++) {
		if (button_is_clicked(&scene->buttons[i], pos_mouse)) {
			if (win->event.type == sfEvtMouseButtonPressed) {
				deselect_all_buttons(scene);
				mouse_scene_fight(win, &scene->buttons[i]);
			}
		}
	}
}

void mouse_menu_fight(window_t *win, scene_t *scene, fight_t *fight, game_objs_t *obj)
{
	sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(win->win);
	sfVector2f size;

	mouse_fight_buttons(win, scene, pos_mouse);
	for (int i = 0; i < fight->nb_mobs; i++) {
		size.x = obj[i].rect.width;
		size.y = obj[i].rect.height;
		if (zone_is_clicked(obj[i].pos, size, pos_mouse)) {
			switch_color(win, scene, &obj[i], 1);
			if (win->event.type == sfEvtMouseButtonPressed) {
				deselect_all_mobs(obj, fight);
				fight->who_take_dmg = i;
				action_fight(win, scene, fight, obj);
			}
		} else
			switch_color(win, scene, &obj[i], 0);
	}
}

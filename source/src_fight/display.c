/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** display
*/

#include "fight_boss.h"

void display_fight(window_t *win, game_objs_t *obj, scene_t *scene, fight_t *fight)
{
	sfRenderWindow_clear(win->win, sfBlack);
	sfRenderWindow_setView(win->win, win->view);
	display_objs(win, scene->obj, 1);
	display_objs(win, obj, fight->nb_mobs);
	display_rect_shape(
		win, scene->buttons, scene->nb_buttons);
	display_rect_shape(win, fight->pv_bar, 4);
	sfRenderWindow_display(win->win);
}

void destroy_fight(window_t *win, game_objs_t *obj)
{
	sfSprite_destroy(obj[0].sprite);
	sfSprite_destroy(obj[1].sprite);
	sfSprite_destroy(obj[2].sprite);
	sfMusic_destroy(win->music);
	sfView_move(
		win->view, (sfVector2f) {win->pos_screen.x, win->pos_screen.y});
	sfClock_restart(win->clock);
}

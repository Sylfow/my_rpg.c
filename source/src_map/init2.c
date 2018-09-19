/*
** EPITECH PROJECT, 2018
** init3.c
** File description:
** init3
*/

#include "my_rpg.h"

void switch_view(sfView *view, int x, int y)
{
	sfView_move(view, (sfVector2f) {x, y});
}

void init_view(window_t *win, int *stats)
{
	sfVector2f vec2 = {stats[14], stats[15]};

	if (stats[14] <= WIDTH / 2) {
		win->pos_screen.x = 0;
		vec2.x = WIDTH / 2;
	} else if (stats[14] >= WIDTH_MAP - WIDTH / 2) {
		win->pos_screen.x = WIDTH_MAP - WIDTH;
		vec2.x = WIDTH_MAP - WIDTH / 2;
	} else
		win->pos_screen.x = stats[14] - WIDTH / 2;
	if (stats[15] <= HEIGHT / 2) {
		win->pos_screen.y = 0;
		vec2.y = HEIGHT / 2;
	} else if (stats[15] >= HEIGHT_MAP - HEIGHT / 2) {
		win->pos_screen.y = HEIGHT_MAP - HEIGHT;
		vec2.y = HEIGHT_MAP - HEIGHT / 2;
	} else
		win->pos_screen.y = stats[15] - HEIGHT / 2;
	sfView_setCenter(win->view, vec2);
}

void create_rect_shape_color(button_t *rectShape, sfColor color, int x, int y)
{
	rectShape->rect_s = sfRectangleShape_create();
	sfRectangleShape_setFillColor(rectShape->rect_s, color);
	rectShape->pos = set_vector(x, y);
	sfRectangleShape_setPosition(rectShape->rect_s, rectShape->pos);
}

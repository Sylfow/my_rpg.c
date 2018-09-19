/*
** EPITECH PROJECT, 2018
** init2.c
** File description:
** init2
*/

#include "my_rpg.h"

void init_load(load_t *load)
{
	sfFont *font = sfFont_createFromFile("utils/police/arial.ttf");

	load->text = sfText_create();
	sfText_setFont(load->text, font);
	sfText_setCharacterSize(load->text, 75);
	sfText_setColor(load->text, sfWhite);
	sfText_setString(load->text, "Loading");
	sfText_setPosition(
		load->text, (sfVector2f) {WIDTH / 2 - 140, HEIGHT / 2 - 100});
	load->rect_s = sfRectangleShape_create();
	sfRectangleShape_setFillColor(
		load->rect_s, (sfColor) {255, 0, 0, 255});
	sfRectangleShape_setPosition(
		load->rect_s, (sfVector2f) {WIDTH / 2 - 150, HEIGHT / 2 + 100});
	load->size.x = 5;
	load->size.y = 20;
	sfRectangleShape_setSize(load->rect_s, load->size);
}

void load_bar(load_t *load)
{
	if (load->size.x > 280)
		load->size.x = 0;
	else
		load->size.x += 10;
	sfRectangleShape_setSize(load->rect_s, load->size);
}

void display_load(window_t *win)
{
	sfRenderWindow_clear(win->win, sfBlack);
	sfRenderWindow_setView(win->win, win->view);
	sfRenderWindow_drawRectangleShape(
		win->win, win->load.rect_s, NULL);
	sfRenderWindow_drawText(
		win->win, win->load.text, NULL);
	sfRenderWindow_display(win->win);
}

/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** init
*/

#include "main.h"

void setup_window(window_t *win, char *name, int width, int height)
{
	sfVideoMode mode = {width, height, 32};

	win->win = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(win->win, 60);
	win->pos_screen = set_vector(0, 0);
	win->nb_scene = 0;
	win->view = sfView_create();
	sfView_setCenter(win->view, (sfVector2f) {WIDTH / 2, HEIGHT / 2});
	sfView_setSize(win->view, (sfVector2f) {WIDTH, HEIGHT});
	win->save = 0;
	win->music = sfMusic_createFromFile(
		"utils/music/driftveil.ogg");
	sfMusic_setLoop(win->music, 1);
	sfMusic_play(win->music);
}

void init_main_menu(scene_t *scene, int nb_scene, int new)
{
	create_scene(scene, nb_scene);
	if (new == 0)
		scene->nb_buttons--;
	for (int i = 0; i < scene->nb_buttons; i++) {
		if (scene->nb_buttons == 3) {
			scene->buttons[i].id = i + 1;
			scene->buttons[i].rect = set_rect(
				50 * (i + 1), 0, 250, 50);
		} else {
			scene->buttons[i].id = i;
			scene->buttons[i].rect = set_rect(
				50 * i, 0, 250, 50);
		}
		sfRectangleShape_setTextureRect(
			scene->buttons[i].rect_s, scene->buttons[i].rect);
	}
}

void all_init_menu(window_t *win, scene_t *scene)
{
	setup_window(win, "My Hunter III - Rainbow Duck is unstoppable",
		WIDTH, HEIGHT);
	init_main_menu(&scene[0], win->nb_scene, 0);
	create_scene(&scene[1], 1);
	create_scene(&scene[2], 2);
	create_scene(&scene[3], 3);
	init_main_menu(&scene[4], win->nb_scene, 1);
	create_scene(&scene[5], 6);
	create_scene(&scene[6], 7);
}

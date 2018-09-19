/*
** EPITECH PROJECT, 2018
** main
** File description:
** main of rpg
*/

#include "main.h"

void start_game(window_t *win, scene_t *scene, player_t *player)
{
	int new = 0;

	switch (win->nb_scene) {
	case 0:
		if (player->stats[16] == 1)
			win->nb_scene = 4;
		animate(&scene[win->nb_scene].obj[3], 0.08, 1106, 553);
		animate_rainbow(&scene[win->nb_scene].obj[1], 0.01);
		new = event_main_menu(win, &scene[win->nb_scene], player);
		do_action(win, scene, player, new);
		break;
	default:
		start_game2(win, scene);
		start_game3(win, scene, player, &new);
		break;
	}
	display(win, &scene[win->nb_scene]);
	if (win->nb_scene == 4)
		win->nb_scene = 0;
}

void start_game2(window_t *win, scene_t *scene)
{
	switch (win->nb_scene) {
	case 1:
		if (sfSprite_getColor(scene[1].obj[0].sprite).a <= 0) {
			scene[1].obj[1].rect.height = 600;
			sfSprite_setColor(scene[1].obj[0].sprite, sfWhite);
			win->nb_scene = 2;
		} else if (scene[1].obj[1].rect.height <= 0)
			set_opacity(&scene[1].obj[0], 0.08);
		else
			animate_height(&scene[1].obj[1], 0.01, 0, 5);
		break;
	case 2:
		mini_hunter(win, &scene[2]);
		break;
	}
}

void start_game3(window_t *win, scene_t *scene, player_t *player, int *new)
{
	switch (win->nb_scene) {
	case 3:
		set_opacity(&scene[3].obj[1], 0.08);
		if (scene[3].obj[2].pos.y + 1000 <= 0) {
			sfSprite_setColor(scene[3].obj[1].sprite, sfWhite);
			scene[3].obj[2].pos.y = 602;
			sfSprite_setPosition(
				scene[3].obj[2].sprite, scene[3].obj[2].pos);
			my_rpg(win, player);
		}
		if (sfSprite_getColor(scene[3].obj[1].sprite).a <= 0)
			time_move_up(&scene[3].obj[2], 0.03, 1);
		*new = event_main_menu(win, &scene[3], player);
		break;
	case 5:
		event_main_menu(win, scene, player);
		break;
	default:
		start_game4(win, scene);
	}
}

void start_game4(window_t *win, scene_t *scene)
{
	switch (win->nb_scene) {
	case 6:
		set_opacity(&scene[6].obj[0], 0.3);
		if (sfSprite_getColor(scene[6].obj[0].sprite).a <= 0) {
			sfMusic_stop(win->music);
			sfMusic_destroy(win->music);
			win->music = sfMusic_createFromFile(
				"utils/music/driftveil.ogg");
			sfMusic_setLoop(win->music, 1);
			sfMusic_play(win->music);
			sfSprite_setColor(scene[6].obj[0].sprite, sfWhite);
			win->nb_scene = 0;
		}
	}
}

int main(int ac, char **av)
{
	scene_t *scene = malloc(sizeof(scene_t) * 7);
	window_t win;
	player_t player;

	if (ac != 1) {
		my_putstr(av[0]);
		my_putstr(" without any option\n");
		return (84);
	}
	verif_save(&player, 0);
	all_init_menu(&win, scene);
	while (sfRenderWindow_isOpen(win.win)) {
		start_game(&win, scene, &player);
	}
	destroy(&win, scene);
	return (0);
}

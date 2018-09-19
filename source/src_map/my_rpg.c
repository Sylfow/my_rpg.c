/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my_rpg.h"

void display_all(window_t *win, game_objs_t *layer, player_t *player)
{
	sfRenderWindow_clear(win->win, sfBlack);
	sfRenderWindow_setView(win->win, win->view);
	sfRenderWindow_drawSprite(win->win, layer->sprite, NULL);
	sfRenderWindow_drawSprite(win->win, player->sprite, NULL);
	if (win->num_scene == 1) {
		sfSprite_setPosition(win->pause.obj->sprite, win->pos_screen);
		sfRenderWindow_drawSprite(win->win, win->pause.obj->sprite, NULL);
		display_rect_shape(win, win->pause.buttons, 4);
		disp_stats(player, win);
		if (win->save == 1)
			sfRenderWindow_drawSprite(
				win->win, win->pause.obj[1].sprite, NULL);
	}
	sfRenderWindow_display(win->win);
	if (win->save == 1) {
		time_clock(win->pause.obj[1].clock, 1);
		win->save = 0;
	}
}

void test_switch_map(window_t *win, dialog_t *dialog, player_t *p)
{
	if (set_stats_num_map(p->stats[13], p->pos) != -1) {
		dialog->name = my_strcpy_map("dialog_tp");
		set_text_dialog(win, dialog);
		win->num_scene = 3;
	}
}

void all_game(window_t *win, map_t *map, player_t *player)
{
	dialog_t dialog = init_dialog();

	while (win->nb_scene != 0 && win->nb_scene != 6) {
		if (win->num_scene == 2) {
			basic_fight(win, player, map);
		} else if (win->num_scene == 3) {
			event_dialog(win, player, map, &dialog);
			display_dialog(win, map, player, &dialog);
		} else if (win->num_scene == 4) {
			fight_boss(win, player, map);
		} else {
			if (player->stats[23] == 1 && player->stats[24] != 1)
				win->num_scene = 4;
			else if (player->stats[25] == 1 && player->stats[26] == 0)
				win->nb_scene = 6;
			display_all(win, &map->layer, player);
			event_all(win, player, map, &dialog);
			player->can_move = 1;
			animate_player(player);
			test_switch_map(win, &dialog, player);
			check_dialog(win, player, &dialog);
			if (player->stats[13] == 2 && win->num_scene != 1)
				clock_start_fight(win);
		}
	}
	destroy_all(win, map, player);
}

void my_rpg(window_t *win, player_t *player)
{
	map_t map;

	sfMusic_stop(win->music);
	sfMusic_destroy(win->music);
	srand(time(NULL));
	init_screen(win);
	win->clock = sfClock_create();
	map.name_map = set_new_map_name(player->stats[13]);
	map.map_file = create_map(map.name_map, win);
	init_all(&map, player, win, player->stats);
	init_view(win, player->stats);
	all_game(win, &map, player);
	sfView_setCenter(win->view, (sfVector2f) {WIDTH / 2, HEIGHT / 2});
	win->pos_screen.x = 0;
	win->pos_screen.y = 0;
	if (win->nb_scene == 6)
		win->music = sfMusic_createFromFile(
			"utils/music/to_be_continued.ogg");
	else
		win->music = sfMusic_createFromFile(
			"utils/music/driftveil.ogg");
	sfMusic_setLoop(win->music, 1);
	sfMusic_play(win->music);
}

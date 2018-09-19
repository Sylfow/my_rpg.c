/*
** EPITECH PROJECT, 2018
** pause.c
** File description:
** pause
*/

#include "my_rpg.h"

char *get_stats(player_t *player)
{
	char *results = NULL;

	results = int_to_char(player->stats[0]);
	results = my_strcat_map(results, "\n\n");
	results = my_strcat_map(results, int_to_char(player->stats[1]));
	results = my_strcat_map(results, "\n\n");
	results = my_strcat_map(results, int_to_char(player->stats[3]));
	results = my_strcat_map(results, " / ");	
	results = my_strcat_map(results, int_to_char(player->stats[2]));
	results = my_strcat_map(results, "\n\n");
	results = my_strcat_map(results, int_to_char(player->stats[5]));
	results = my_strcat_map(results, " / ");
	results = my_strcat_map(results, int_to_char(player->stats[4]));
	results = my_strcat_map(results, "\n\n");	
	results = my_strcat_map(results, int_to_char(player->stats[7]));
	results = my_strcat_map(results, "\n\n");
	results = my_strcat_map(results, int_to_char(player->stats[9]));
	results = my_strcat_map(results, "\n\n");
	results = my_strcat_map(results, int_to_char(player->stats[11]));
	results = my_strcat_map(results, "\n\n");
	results = my_strcat_map(results, int_to_char(player->stats[12]));
	return (results);
}

void disp_stats(player_t *player, window_t *win)
{
	char *values = get_stats(player);
	char *names = malloc(sizeof(char) * 80);
	sfText *stats_name = NULL;
	sfText *stats_value = NULL;
	sfVector2f pos_name = {500 + win->pos_screen.x, 80 + win->pos_screen.y};
	sfVector2f pos_value = {800 + win->pos_screen.x, 80 + win->pos_screen.y};
	sfFont *font = sfFont_createFromFile("utils/police/arial.ttf");

	names = "Level :\n\nExperience points :\n\nHP :\n\nMP :\n\nAttack :\n\nDefense :\n\nSpeed :\n\nGold :\n\n";
	stats_name = sfText_create();
	sfText_setFont(stats_name, font);
	sfText_setColor(stats_name, sfWhite);
	sfText_setCharacterSize(stats_name, 25);
	sfText_setStyle(stats_name, sfTextBold);
	sfText_setPosition(stats_name, pos_name);
	sfText_setString(stats_name, names);
	stats_value = sfText_create();
	sfText_setFont(stats_value, font);
	sfText_setColor(stats_value, sfWhite);
	sfText_setCharacterSize(stats_value, 25);
	sfText_setStyle(stats_value, sfTextBold);
	sfText_setPosition(stats_value, pos_value);
	sfText_setString(stats_value, values);
	sfRenderWindow_drawText(win->win, stats_name, NULL);
	sfRenderWindow_drawText(win->win, stats_value, NULL);
	sfText_destroy(stats_name);
	sfText_destroy(stats_value);
}

void init_pause(scene_t *pause)
{
	pause->buttons = malloc(sizeof(button_t) * 4);
	pause->obj = malloc(sizeof(game_objs_t) * 2);
	create_obj(&pause->obj[0], "utils/img/menu_bg.jpg", 0, 0);
	create_obj(&pause->obj[1], "utils/img/have_save.png", 300, 520);
	for (int i = 0; i < 4; i++) {
		create_rect_shape(
			&pause->buttons[i], "utils/img/pause.png", 0, 0);
		sfRectangleShape_setSize(
			pause->buttons[i].rect_s, (sfVector2f) {200, 82});
		pause->buttons[i].rect = set_rect(60 + i * 85, 0, 200, 85);
		sfRectangleShape_setTextureRect(
			pause->buttons[i].rect_s, pause->buttons[i].rect);
	}
}

void set_pos_pause(window_t *win)
{
	win->pause.obj[1].pos.x = win->pos_screen.x + 300;
	win->pause.obj[1].pos.y = win->pos_screen.y + 520;
	sfSprite_setPosition(
		win->pause.obj[1].sprite, win->pause.obj[1].pos);
	for (int i = 0; i < 4; i++) {
		win->pause.buttons[i].pos.x = win->pos_screen.x + 5;
		win->pause.buttons[i].pos.y = 100 * i + 5 + win->pos_screen.y;
		sfRectangleShape_setPosition(
			win->pause.buttons[i].rect_s, win->pause.buttons[i].pos);
	}

}

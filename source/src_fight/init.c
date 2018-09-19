/*
** EPITECH PROJECT, 2018
** init_boss.c
** File description:
** init_boss
*/

#include "fight_boss.h"

void setup_win(window_t *win)
{
	win->music = sfMusic_createFromFile(
		"utils/music/boss_fight_1.ogg");
	sfMusic_setLoop(win->music, 1);
	sfMusic_play(win->music);
}

void setup_scene(scene_t *scene, int y)
{
	for (int i = 0; i < scene->nb_buttons; i++) {
		scene->buttons[i].rect = set_rect(50 * i + y, 0, 200, 50);
		sfRectangleShape_setTextureRect(
			scene->buttons[i].rect_s, scene->buttons[i].rect);
	}
}

void setup_fight(fight_t *fight)
{
	fight->pv_bar = malloc(sizeof(button_t) * 4);
	for (int i = 0; i < 4; i += 2) {
		create_rect_shape_color(
			&fight->pv_bar[i], sfBlack, 300 * i + 100, 5);
		fight->pv_bar[i].size = set_vector(200, 30);
		sfRectangleShape_setSize(
			fight->pv_bar[i].rect_s, fight->pv_bar[i].size);
		create_rect_shape_color(
			&fight->pv_bar[i + 1], sfRed, 300 * i + 100, 5);
		fight->pv_bar[i + 1].size = set_vector(200, 30);
		sfRectangleShape_setSize(
			fight->pv_bar[i + 1].rect_s, fight->pv_bar[i + 1].size);
	}
}

void all_setup_fight(window_t *win, scene_t *scene, fight_t *fight, game_objs_t *obj)
{
	setup_win(win);
	win->fight_scene = 0;
	create_obj(&obj[0], "utils/img/attaq_spe.png", 1100, 0);
	obj[0].rect = set_rect(0, 0, 500, 400);
	sfSprite_setTextureRect(obj[0].sprite, obj[0].rect);
	create_obj(&obj[1], "utils/img/DuckT.png", 600, 200);
	obj[1].rect = set_rect(0, 140, 255, 170);
	sfSprite_setTextureRect(obj[1].sprite, obj[1].rect);
	for (int i = 0; i < fight->nb_mobs; i++) {
		create_obj(&obj[2 + i], "utils/img/enemy.png",
			100 + i * 80, 100 + i * 50);
		obj[2 + i].rect = set_rect(0, 0, 172, 248);
		sfSprite_setTextureRect(obj[2 + i].sprite, obj[2 + i].rect);
	}
	create_scene(&scene[0], 4);
	setup_scene(&scene[0], 0);
	create_scene(&scene[1], 5);
	setup_scene(&scene[1], 100);
	setup_fight(fight);
	fight->nb_mobs += 2;
}

void all_setup_boss(window_t *win, scene_t *scene, fight_t *fight, game_objs_t *obj)
{
	setup_win(win);
	win->fight_scene = 0;
	create_obj(&obj[0], "utils/img/attaq_spe.png", 1100, 0);
	obj[0].rect = set_rect(0, 0, 500, 400);
	sfSprite_setTextureRect(obj[0].sprite, obj[0].rect);
	create_obj(&obj[1], "utils/img/DuckT.png", 600, 200);
	obj[1].rect = set_rect(0, 140, 255, 170);
	sfSprite_setTextureRect(obj[1].sprite, obj[1].rect);
	create_obj(&obj[2], "utils/img/Sprite_boss_rpg.png", 100, 200);
	obj[2].rect = set_rect(0, 0, 200, 177);
	sfSprite_setTextureRect(obj[2].sprite, obj[2].rect);
	create_scene(&scene[0], 4);
	setup_scene(&scene[0], 0);
	create_scene(&scene[1], 5);
	setup_scene(&scene[1], 100);
	setup_fight(fight);
	fight->nb_mobs = 3;
}

/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct header
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct game_objs_s {
	sfSprite *sprite;
	sfVector2f pos;
	sfIntRect rect;
	sfClock *clock;
} game_objs_t;

typedef struct button_s {
	sfRectangleShape *rect_s;
	sfVector2f pos;
	sfVector2f size;
	sfIntRect rect;
	int id;
} button_t;

typedef struct scene_s {
        game_objs_t *obj;
        int nb_objs;
	button_t *buttons;
        int nb_buttons;
} scene_t;

typedef struct fight_s {
	int turn;
	int who_take_dmg;
	int pv_boss;
	int pv_player;
	button_t *pv_bar;
} fight_t;

typedef struct window_struct {
	sfRenderWindow *win;
	sfVector2f pos_screen;
	sfMusic *music;
	sfEvent event;
	int nb_scene;
	int num_scene;
	int fight_scene;
} window_t;

#endif

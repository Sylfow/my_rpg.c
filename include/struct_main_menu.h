/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct header
*/

#ifndef STRUCT_MAIN_MENU_H_
#define STRUCT_MAIN_MENU_H_

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

typedef struct map_s {
	game_objs_t layer;
	int *map_file;
	char *name_map;
} map_t;

typedef struct player_s {
	sfIntRect rect;
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos;
	sfClock *clock;
	button_t *hp;
	float time_max;
	int can_move;
	char *name;
	int *stats;
} player_t;

typedef struct load_s {
	sfRectangleShape *rect_s;
	sfVector2f size;
	sfText *text;
} load_t;

typedef struct attack_type {
	int power;
	int precision;
	int mana;
} spell_b;

typedef struct carac {
	char *name;
	int *stats;
	spell_b tackle;
	spell_b shoot;
	spell_b fireball;
} carac_t;

typedef struct fight_s {
	int turn;
	int who_take_dmg;
	int nb_mobs;
	button_t *pv_bar;
	carac_t player;
	carac_t enemy;
	int spell;
} fight_t;

typedef struct dialog_s {
	game_objs_t box;
	sfText *text;
	int line;
	char *name;
} dialog_t;

typedef struct window_struct {
	sfRenderWindow *win;
	sfClock *clock;
	sfVector2f pos_screen;
	sfEvent event;
	sfMusic *music;
	sfView *view;
	int nb_scene;
	int num_scene;
	int fight_scene;
	load_t load;
	scene_t pause;
	int save;
	fight_t *fight;
	char *name;
} window_t;

#endif

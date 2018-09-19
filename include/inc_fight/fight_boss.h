/*
** EPITECH PROJECT, 2018
** fight_boss.h
** File description:
** fight_boss header
*/

#ifndef NB_STATS
#define NB_STATS (27)
#endif

#ifndef FIGHT_BOSS_H_
#define FIGHT_BOSS_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "struct_main_menu.h"
#include "animation.h"
#include "attack.h"
#include "display_fight.h"
#include "event_boss.h"
#include "init_boss.h"
#include "str.h"

void create_rect_shape_color(button_t *, sfColor, int, int);
void create_scene(scene_t *, int);
void create_obj(game_objs_t *, char *, int, int);
sfVector2f set_vector(int, int);
sfIntRect set_rect(int, int, int, int);

void switch_boss(window_t *, game_objs_t *, scene_t *, fight_t *);
void boss_attack(window_t *, scene_t *, fight_t *, game_objs_t *, int);
void play_fight_boss(window_t *, scene_t *, fight_t *, game_objs_t *);
void boss_change(window_t *, scene_t *, fight_t *, game_objs_t *);
void fight_boss(window_t *, player_t *, map_t *);
void basic_fight(window_t *, player_t *, map_t *);

#endif

/*
** EPITECH PROJECT, 2018
** init_boss.h
** File description:
** init_boss header
*/

#ifndef INIT_BOSS_H_
#define INIT_BOSS_H_

void setup_win(window_t *);
void setup_scene(scene_t *, int);
void setup_fight(fight_t *);
void all_setup_fight(window_t *, scene_t *, fight_t *, game_objs_t *);
void all_setup_boss(window_t *, scene_t *, fight_t *, game_objs_t *);

void set_up_boss(carac_t *);
void setup_boss(carac_t *);
void set_up_player(carac_t *);
void set_up_enemy(carac_t *);
void setup_player(carac_t *, int *);
void setup_enemy(carac_t *);
void spell_initialize(spell_b *, int, int, int);

#endif

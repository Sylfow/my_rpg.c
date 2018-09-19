/*
** EPITECH PROJECT, 2018
** attack.h
** File description:
** attack header
*/

#ifndef ATTACK_H_
#define ATTACK_H_

void set_new_stats(carac_t *, player_t *);
void test_finish_fight(window_t *, fight_t *, player_t *, map_t *);
void win_fight(carac_t *, carac_t *);
void lose_fight(carac_t *, window_t *, map_t *, player_t *);

int critical_hit(void);
int my_rand(int, int);
int calcul_damage(carac_t *, carac_t *, spell_b, button_t *);
void boss_take_damage(window_t *, scene_t *, fight_t *, game_objs_t *);
void player_take_damage(window_t *, scene_t *, fight_t *, game_objs_t *);
int set_damage(carac_t *, carac_t *, button_t *, int);

void attack1(window_t *, scene_t *, fight_t *, game_objs_t *);
void attack2(window_t *, scene_t *, fight_t *, game_objs_t *);
void attack3(fight_t *, game_objs_t *);
void attack4(window_t *, scene_t *, fight_t *, game_objs_t *);

#endif

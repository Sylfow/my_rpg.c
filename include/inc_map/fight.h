/*
** EPITECH PROJECT, 2018
** fight.h
** File description:
** fight header
*/

#ifndef FIGHT_H_
#define FIGHT_H_

void create_mob(fight_t *, int, int, int);
void init_all_mobs(fight_t *, int);
fight_t init_fight(void);
void set_hp_gauge(fight_t *, int);
void reset_fight(window_t *, fight_t *, int);

void display_fight(window_t *, fight_t *);
void switch_color(window_t *, fight_t *, sfColor, sfVector2i);
int display_one_hp_gauge(window_t *, fight_t *, sfVector2i, int);
void take_damage(window_t *, fight_t *);
void destroy_mobs(fight_t *);

#endif

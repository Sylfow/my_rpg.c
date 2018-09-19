/*
** EPITECH PROJECT, 2018
** display_fight.h
** File description:
** display_fight
*/

#ifndef DISPLAY_FIGHT_H_
#define DISPLAY_FIGHT_H_

void display_rect_shape(window_t *, button_t *, int);
void display_objs(window_t *, game_objs_t *, int);
void display_fight(window_t *, game_objs_t *, scene_t *, fight_t *);

void destroy_fight(window_t *, game_objs_t *);

#endif

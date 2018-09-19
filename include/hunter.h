/*
** EPITECH PROJECT, 2018
** hunter.h
** File description:
** hunter header
*/

#ifndef HUNTER_H_
#define HUNTER_H_

void move_ducky(game_objs_t *, int, int, int);
void handle_events(window_t *, game_objs_t *, sfVector2f);
void mini_hunter(window_t *, scene_t *);

#endif

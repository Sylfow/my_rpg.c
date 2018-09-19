/*
** EPITECH PROJECT, 2018
** create.h
** File description:
** create header
*/

#ifndef CREATE_H_
#define CREATE_H_

sfIntRect set_rect(int, int, int, int);
sfVector2f set_vector(int, int);
void create_rect_shape(button_t *, char *, int, int);
void create_obj(game_objs_t *, char *, int, int);
void set_size(button_t *, int, int);

#endif

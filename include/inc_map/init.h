/*
** EPITECH PROJECT, 2018
** init.h
** File description:
** init header
*/

#ifndef INIT_H_
#define INIT_H_

void set_block_pixel(sfImage *, sfImage *, int *, int, int);
sfSprite *init_img(int *, window_t *);
void init_screen(window_t *);
void init_player(player_t *, int *);
void init_all(map_t *, player_t *, window_t *, int *);

sfIntRect set_rect(int, int, int, int);
sfVector2f set_vector(int, int);
void create_rect_shape_color(button_t *, sfColor, int, int);

void switch_view(sfView *, int, int);
void init_view(window_t *, int *);

#endif

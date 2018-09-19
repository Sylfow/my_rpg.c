/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct header
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct game_objs {
	sfSprite *sprite;
	sfVector2f pos;
} game_objs_t;

typedef struct screen {
	sfRenderWindow *win;
	sfEvent event;
	sfView *view;
	sfTexture *texture;
	sfIntRect rect;
	sfVector2f pos_screen;
} screen_t;

#endif

/*
** EPITECH PROJECT, 2018
** main.h
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"
#include "init.h"
#include "macro.h"
#include "utils.h"

sfRenderWindow *create_window(char *);
void display_all(screen_t *, game_objs_t *);
void destroy_all(screen_t *, game_objs_t *);
int obj_is_clicked(game_objs_t *, sfVector2i);

void all_game(screen_t *, game_objs_t *, int *, char *);
void event_all(screen_t *, game_objs_t *, int *);
void switch_key(screen_t *);
void switch_move(screen_t *);
void switch_move2(screen_t *);
void set_texture(screen_t *, game_objs_t *, int *);

void display_help();
int *create_map();
int *recup_map(char *);
int *test(char *);
void set_map_in_file(int *, char *);

#endif

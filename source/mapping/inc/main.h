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
#include "move.h"
#include "utils.h"

int p_move;

sfRenderWindow *create_window(char *);
void display_all(screen_t *, game_objs_t *, player_t *);
void destroy_all(screen_t *, game_objs_t *);

void all_game(screen_t *, game_objs_t *, int *, player_t *);
void event_all(screen_t *, player_t *, game_objs_t *, int *);
void switch_key(screen_t *, player_t *, game_objs_t *, int *);
void switch_move(screen_t *, player_t *, game_objs_t *, int *);
void switch_move2(screen_t *, player_t *, game_objs_t *, int *);

void display_help();
int *create_map(char *);

void animate_player(player_t *);

int collision(int *, int);
int check_interact(int *, int);
int interact(int *, int);

#endif

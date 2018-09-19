/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** headers of rpg
*/

#ifndef READ_SIZE
#define READ_SIZE (100)

#endif

#ifndef NB_STATS
#define NB_STATS (27)

#endif

#ifndef MAIN_H_
#define MAIN_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "struct_main_menu.h"
#include "destroy.h"
#include "event.h"
#include "hunter.h"
#include "info.h"
#include "init.h"
#include "macro.h"
#include "my_rpg.h"
#include "save.h"
#include "str.h"

#include "main.h"

void animate(game_objs_t *, float, int, int);
void animate_height(game_objs_t *, float, int, int);
void animate_all(game_objs_t *, float, int);
void set_opacity(game_objs_t *, float);
void animate_rainbow(game_objs_t *, float);
void time_move_up(game_objs_t *, float, int);

void init_stats(player_t *);
void start_game(window_t *, scene_t *, player_t *);
void start_game2(window_t *, scene_t *);
void start_game3(window_t *, scene_t *, player_t *, int *);
void start_game4(window_t *, scene_t *);

#endif /* MAIN */

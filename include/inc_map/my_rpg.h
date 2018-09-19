/*
** EPITECH PROJECT, 2018
** main.h
** File description:
** main
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "struct_main_menu.h"
#include "change_zone.h"
#include "create.h"
#include "collision.h"
#include "dialog.h"
#include "display.h"
#include "event.h"
#include "fight.h"
#include "init.h"
#include "load.h"
#include "macro.h"
#include "move.h"
#include "pause.h"
#include "str.h"
#include "utils.h"
#include "zone.h"

int p_move;

sfRenderWindow *create_window(char *);
void display_all(window_t *, game_objs_t *, player_t *);
void destroy_all(window_t *, map_t *, player_t *);

void test_switch_map(window_t *, dialog_t *, player_t *);
void all_game(window_t *, map_t *, player_t *);
void fight_boss(window_t *, player_t *, map_t *);
void basic_fight(window_t *, player_t *, map_t *);
void my_rpg(window_t *, player_t *);

int set_nb_map(char *, int *, int, int);
int create_line(int *, int, int, char *);
int *create_map(char *, window_t *);
char *set_new_map_name(int);
char *get_new_map_name(char *);

int get_rect_left(int, int);
void animate_player(player_t *);
void set_new_rect(player_t *, int, int, int);
void clock_start_fight(window_t *);

#endif

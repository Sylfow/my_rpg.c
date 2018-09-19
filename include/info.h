/*
** EPITECH PROJECT, 2018
** info.h
** File description:
** info header
*/

#ifndef INFO_H_
#define INFO_H_

char *get_info_scene(char *, int);
void set_objs_rect(game_objs_t *, char *);
void set_objs(scene_t *, FILE *);
void set_buttons(scene_t *, FILE *);
void create_scene(scene_t *, int);

#endif

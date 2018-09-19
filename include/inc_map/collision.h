/*
** EPITECH PROJECT, 2018
** collision.h
** File description:
** collision header
*/

#ifndef COLLISION_H_
#define COLLISION_H_

int set_stats_num_map(int, sfVector2f);
int collision(map_t *, player_t *, int);
int check_interact(map_t *, int);
int interact(map_t *, int);

#endif

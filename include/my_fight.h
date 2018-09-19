/*
** EPITECH PROJECT, 2018
** my_fight
** File description:
** fight mode for my_rpg
*/

#ifndef MY_FIGHT_
#define MY_FIGHT_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct sprite_s {
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f vect;
	sfIntRect rect;
} sprite_t;

typedef struct attack_type {
        int power;
        int precision;
        int mana;
} spell_b;

typedef struct carac_t {
        char *name;
	int lvl;
        int max_hp;
        int hp;
        int att;
        int def;
        int spe;
	
} carac;

typedef struct fight_mode {
	sfRenderWindow *window;
	sfEvent event;
	sfVideoMode video;
	sfClock *clock;
	sfTime time;
	float seconds;
	sfMusic *music;
	sprite_t *bg;
} fight;

int main(void);
void creat_window(fight *, char *, int, int);
void creat_sprite(fight *);
void start_music(fight *);
void draw_sprite(fight *);
void open_window(fight *);
void destroy(fight *);
void pollevent(fight *);

#endif /* MY_FIGHT */

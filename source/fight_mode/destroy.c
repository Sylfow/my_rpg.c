/*
** EPITECH PROJECT, 2018
** destroy
** File description:
** destroy at the end of program 
*/

#include "my_fight.h"

void destroy_sprite(sprite_t *sp)
{
        sfTexture_destroy(sp->texture);
        sfSprite_destroy(sp->sprite);
        free(sp);
}

void destroy(fight *ft)
{
        sfMusic_destroy(ft->music);
        destroy_sprite(ft->bg);
        sfRenderWindow_destroy(ft->window);
}

/*
** EPITECH PROJECT, 2018
** creat
** File description:
** create sprite and window for fight
*/

#include "my_fight.h"

sprite_t *create_sprite(char *path)
{
	sprite_t *sp = malloc(sizeof(sprite_t));

	sp->texture = sfTexture_createFromFile(path, NULL);
	sp->sprite = sfSprite_create();
	sfSprite_setTexture(sp->sprite, sp->texture, sfTrue);
	return (sp);
}

void creat_sprite(fight *ft)
{
	ft->bg = create_sprite("Stuff/sprites/background_fight.png");
}

void creat_window(fight *ft, char *name, int width, int height)
{
	ft->video.width = width;
	ft->video.height = height;
	ft->video.bitsPerPixel = 32;
	ft->window = sfRenderWindow_create(ft->video, name,
                                           sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(ft->window, 60);
}

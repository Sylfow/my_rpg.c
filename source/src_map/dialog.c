/*
** EPITECH PROJECT, 2018
** dialog.c
** File description:
** dialog
*/

#include "my_rpg.h"

dialog_t init_dialog(void)
{
	sfTexture *texture = sfTexture_createFromFile(
		"utils/img/Dialog.png", NULL);
	sfFont *font = sfFont_createFromFile("utils/police/arial.ttf");
	dialog_t dialog;

	dialog.line = 1;
	dialog.text = sfText_create();
	sfText_setFont(dialog.text, font);
	sfText_setCharacterSize(dialog.text, 25);
	sfText_setColor(dialog.text, sfWhite);
	sfText_setStyle(dialog.text, sfTextBold);
	sfText_setString(dialog.text, "");
	sfText_setPosition(dialog.text, (sfVector2f) {0, 0});
	dialog.box.sprite = sfSprite_create();
	sfSprite_setTexture(dialog.box.sprite, texture, sfTrue);
	dialog.box.pos = set_vector(-2, HEIGHT - 102);
	sfSprite_setPosition(dialog.box.sprite, dialog.box.pos);
	dialog.box.rect = set_rect(0, 0, 1000, 102);
	sfSprite_setTextureRect(dialog.box.sprite, dialog.box.rect);
	return (dialog);
}

void display_dialog(window_t *win, map_t *map, player_t *p, dialog_t *dialog)
{
	int nb = p->pos.x / O_SIZE + p->pos.y / O_SIZE * NB_OHEIGHT;
	int pos_x = win->pos_screen.x - 2;
	int pos_y = win->pos_screen.y + HEIGHT - 102;

	if (map->map_file[nb] == 4) {
		map->map_file[nb] = 3;
		map->layer.sprite = init_img(map->map_file, win);
		dialog->box.pos = set_vector(pos_x, pos_y);
		sfSprite_setPosition(dialog->box.sprite, dialog->box.pos);
	}
	sfRenderWindow_clear(win->win, sfBlack);
	sfRenderWindow_setView(win->win, win->view);
	sfRenderWindow_drawSprite(win->win, map->layer.sprite, NULL);
	sfRenderWindow_drawSprite(win->win, p->sprite, NULL);
	sfRenderWindow_drawSprite(win->win, dialog->box.sprite, NULL);
	sfRenderWindow_drawText(win->win, dialog->text, NULL);
	sfRenderWindow_display(win->win);
}

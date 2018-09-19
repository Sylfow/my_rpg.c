/*
** EPITECH PROJECT, 2018
** move.c
** File description:
** move
*/

#include "my_rpg.h"

void move_right(player_t *player, window_t *win, game_objs_t *objs)
{
	int pos = player->pos.x + O_SIZE;

	while (pos > player->pos.x) {
		if (win->pos_screen.x + WIDTH < WIDTH_MAP
		    && player->pos.x >= WIDTH / 2) {
			sfView_move(win->view, (sfVector2f) {p_move, 0});
			win->pos_screen.x += p_move;
		}
		player->pos.x += p_move;
		sfSprite_setPosition(player->sprite, player->pos);
		display_all(win, objs, player);
	}
}

void move_left(player_t *player, window_t *win, game_objs_t *objs)
{
	int pos = player->pos.x - O_SIZE;

	while (pos < player->pos.x) {
		if (win->pos_screen.x > 2
		    && player->pos.x <= WIDTH_MAP - WIDTH / 2) {
			sfView_move(win->view, (sfVector2f) {-p_move, 0});
			win->pos_screen.x -= p_move;
		}
		player->pos.x -= p_move;
		sfSprite_setPosition(player->sprite, player->pos);
		display_all(win, objs, player);
	}
}

void move_up(player_t *player, window_t *win, game_objs_t *objs)
{
	int pos = player->pos.y - O_SIZE;

	while (pos < player->pos.y) {
		if (win->pos_screen.y > 0
		    && player->pos.y <= HEIGHT_MAP - HEIGHT / 2) {
			sfView_move(win->view, (sfVector2f) {0, -p_move});
			win->pos_screen.y -= p_move;
                }
		player->pos.y -= p_move;
		sfSprite_setPosition(player->sprite, player->pos);
		display_all(win, objs, player);
	}
}

void move_down(player_t *player, window_t *win, game_objs_t *objs)
{
	int pos = player->pos.y + O_SIZE;

	while (pos > player->pos.y) {
		if (win->pos_screen.y + p_move + HEIGHT <= HEIGHT_MAP
		    && player->pos.y >= HEIGHT / 2) {
			sfView_move(win->view, (sfVector2f) {0, p_move});
			win->pos_screen.y += p_move;
		}
		player->pos.y += p_move;
		sfSprite_setPosition(player->sprite, player->pos);
		display_all(win, objs, player);
	}
}

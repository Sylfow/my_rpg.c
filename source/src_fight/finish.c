/*
** EPITECH PROJECT, 2018
** finish.c
** File description:
** finish
*/

#include "my_rpg.h"

void set_new_stats(carac_t *play, player_t *player)
{
	player->stats[0] = play->stats[0];
	player->stats[1] = play->stats[1];
	player->stats[2] = play->stats[2];
	player->stats[3] = play->stats[3];
	player->stats[4] = play->stats[4];
	player->stats[5] = play->stats[5];
	player->stats[6] = play->stats[6];
	player->stats[7] = play->stats[7];
	player->stats[8] = play->stats[8];
	player->stats[9] = play->stats[9];
	player->stats[10] = play->stats[10];
	player->stats[11] = play->stats[11];
	player->stats[12] = play->stats[12];
}

void win_fight(carac_t *play, carac_t *boss)
{
	play->stats[1] = play->stats[1] + boss->stats[1];
	if (play->stats[1] >= (1000 * play->stats[0] / 20)) {
		play->stats[0] = play->stats[0] + 1;
		play->stats[1] = play->stats[1] - (1000 * play->stats[0] / 20);
	}
	play->stats[12] = play->stats[12] + boss->stats[12];
}

void lose_fight(carac_t *play, window_t *win, map_t *map, player_t *p)
{
	play->stats[3] = play->stats[2];
	play->stats[12] = (play->stats[12] / 3);
	p->stats[13] = 0;
	p->pos = set_vector(450, 150);
	sfSprite_setPosition(p->sprite, p->pos);
	free(map->map_file);
	map->name_map = set_new_map_name(p->stats[13]);
	map->map_file = create_map(map->name_map, win);
	map->layer.sprite = init_img(map->map_file, win);
	win->num_scene = 0;
	sfView_setCenter(win->view, (sfVector2f) {WIDTH / 2, HEIGHT / 2});
	win->pos_screen = set_vector(
		p->pos.x - WIDTH / 2, p->pos.y - HEIGHT / 2);
}

void test_finish_fight(window_t *win, fight_t *fight, player_t *p, map_t *map)
{
	if (fight->pv_bar[1].size.x <= 0) {
		win_fight(&fight->player, &fight->enemy);
		win->num_scene = 0;
	} else if (fight->pv_bar[3].size.x <= 0){
		lose_fight(&fight->player, win, map, p);
		win->num_scene = 0;
	}
}

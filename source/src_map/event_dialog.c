/*
** EPITECH PROJECT, 2018
** event_dialog.c
** File description:
** event_dialog
*/

#include "my_rpg.h"

void event_dialog(window_t *win, player_t *p, map_t *map, dialog_t *dialog)
{
	int pos_x = win->pos_screen.x - 2;
	int pos_y = win->pos_screen.y + HEIGHT - 102;
	sfVector2f pos = {pos_x + 302, pos_y + 40};

	dialog->box.pos = set_vector(pos_x, pos_y);
	sfSprite_setPosition(dialog->box.sprite, dialog->box.pos);
	sfText_setPosition(dialog->text, pos);
	while (sfRenderWindow_pollEvent(win->win, &win->event))
		if (win->event.type == sfEvtKeyPressed)
			event_key_dialog(win, p, map, dialog);
}

void event_key_dialog(window_t *win, player_t *p, map_t *map, dialog_t *dialog)
{
	int nb = p->pos.x / O_SIZE + p->pos.y / O_SIZE * NB_OHEIGHT;
	int n_map = p->stats[13];

	switch (win->event.key.code) {
	case sfKeyA:
		free(map->map_file);
		p->stats[13] = set_stats_num_map(p->stats[13], p->pos);
		set_new_pos_player(p, n_map);
		map->name_map = set_new_map_name(p->stats[13]);
		map->map_file = create_map(map->name_map, win);
		map->layer.sprite = init_img(map->map_file, win);
		dialog->line = 1;
		win->num_scene = 0;
		sfView_setCenter(win->view, (sfVector2f) {p->pos.x, p->pos.y});
		win->pos_screen = set_vector(
			p->pos.x - WIDTH / 2, p->pos.y - HEIGHT / 2);
		sfClock_restart(win->clock);
		break;
	case sfKeyZ:
		if (p->stats[13] == 0 || p->stats[13] == 3)
			move_up(p, win, &map->layer);
		else
			move_down(p, win, &map->layer);
		sfText_setString(dialog->text, "");
		if (map->map_file[nb] == 3) {
			map->map_file[nb] = 4;
			map->layer.sprite = init_img(map->map_file, win);
		}
		dialog->line = 1;
		win->num_scene = 0;
		break;
	case sfKeyReturn:
		set_text_dialog(win, dialog);
		break;
	default:
		break;
	}
}

char *read_only(int fd)
{
	char *s = malloc(sizeof(char));
	int i = 1;

	read(fd, &s[0], 1);
	while (s[i - 1] != '\n') {
		s = realloc(s, i + 2);
		read(fd, &s[i], 1);
		i++;
	}
	s[i - 1] = '\0';
	return (s);
}

void set_text_dialog(window_t *win, dialog_t *dialog)
{
	int fd = open("utils/dialog", O_RDONLY);
	char *s = NULL;

	while (my_strcmp(s, dialog->name) != 1) {
		s = read_only(fd);
	}
	for (int i = 0; i < dialog->line * 2; i++) {
		s = read_only(fd);
		if (i == dialog->line * 2 - 2) {
			s = get_info(s, 1);
			dialog->box.rect.top = char_to_int(s);
			sfSprite_setTextureRect(dialog->box.sprite, dialog->box.rect);
		}
	}
	set_text2_dialog(win, dialog, s);
	close(fd);
}

void set_text2_dialog(window_t *win, dialog_t *dialog, char *s)
{
	if (my_strcmp(s, "") == 1) {
		sfText_setString(dialog->text, "");
		win->num_scene = 0;
		dialog->line = 1;
	} else {
		sfText_setString(dialog->text, s);
		dialog->line++;
	}
}

char *get_info(char *line, int nb_info)
{
	int i;
	int j = 0;
	int check = 0;
	char *name = NULL;

	for (i = 0; line[i] && check < nb_info; i++)
		if (line[i] == '=')
			check += 1;
	if (check < nb_info)
		return (NULL);
	check = i;
	for (i = i + 1; line[i] != '\"'; i++)
		j++;
	name = malloc(sizeof(char) * (j + 1));
	j = 0;
	for (i = check + 1; line[i] != '\"'; i++) {
		name[j] = line[i];
		j++;
	}
	name[j] = '\0';
	return (name);
}

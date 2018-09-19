/*
** EPITECH PROJECT, 2018
** map.c
** File description:
** map
*/

#include "my_rpg.h"

int set_nb_map(char *s, int *map, int nb, int j)
{
	s[j] = '\0';
	map[nb] = char_to_int(s);
	nb++;
	return (nb);
}

int create_line(int *map, int fd, int nb, char *s)
{
	int j;

	for (j = 0; read(fd, &s[j], 1); j++) {
		if (s[j] == '\n')
			break;
		else if (s[j] == ' ') {
			nb = set_nb_map(s, map, nb, j);
			j = 0;
			s[j] = '0';
		}
	}
	nb = set_nb_map(s, map, nb, j);
	return (nb);
}

int *create_map(char *name, window_t *win)
{
	int *map = malloc(sizeof(int) * (NB_OBJS + 1));
	int nb = 0;
	char *s = malloc(sizeof(char) * 10);
	int fd = open(name, O_RDONLY);

	switch_view(win->view, -win->pos_screen.x, -win->pos_screen.y);
	for (int i = 0; i < NB_OHEIGHT; i++) {
		if (i % 2 == 0) {
			load_bar(&win->load);
			display_load(win);
		}
		nb = create_line(map, fd, nb, s);
	}
	close(fd);
	switch_view(win->view, win->pos_screen.x, win->pos_screen.y);
	return (map);
}

char *set_new_map_name(int nb)
{
	char *s = my_strcpy_map("utils/map/map");

	s = my_strcat_map(s, int_to_char(nb));
	return (s);
}

char *get_new_map_name(char *name)
{
	char *new_name = malloc(sizeof(char) * (my_strlen(name) + 1));
	char *nb = malloc(sizeof(char) * (my_strlen(name) + 1));
	int i;
	int j = 0;

	for (i = 0; name[i]; i++) {
		new_name[i] = name[i];
		new_name[i + 1] = '\0';
		if (my_strcmp(new_name, "utils/map/map") == 1)
			break;
	}
	for (i = i + 1; name[i]; i++) {
		nb[j] = name[i];
		j++;
	}
	nb[j] = '\0';
	nb = int_to_char(char_to_int(nb) + 1);
	new_name = my_strcat(new_name, nb);
	return (new_name);
}

/*
** EPITECH PROJECT, 2018
** map.c
** File description:
** map
*/

#include "main.h"

void display_help()
{
	FILE *file = fopen("help", "r");
	size_t n;
	char *s = NULL;

	while (getline(&s, &n, file) != -1)
		my_putstr(s);
	my_putchar('\n');
	fclose(file);
}

int *create_map()
{
	int *map = malloc(sizeof(int) * (NB_OBJS + 1));
	int i;

	for (i = 0; i < NB_OBJS; i++)
		map[i] = 0;
	map[i] = -1;
	return (map);
}

int *recup_map(char *name)
{
	int *map = malloc(sizeof(int) * (NB_OBJS + 1));
	int i;
	int j;
	int nb = 0;
	char c;
	int fd = open(name, O_RDONLY);

	for (i = 0; i < NB_OHEIGHT; i++) {
		for (j = 0; read(fd, &c, 1); j++) {
			if (c == '\n')
				break;
			else if (c != ' ') {
				map[nb] = c - 48;
				nb++;
			}
		}
	}
	map[nb] = -1;
	close(fd);
	return (map);
}


int set_nb_map(char *s, int *map, int nb, int j)
{
	s[j] = '\0';
	map[nb] = char_to_int(s);
	nb++;
	return (nb);
}


int *test(char *name)
{
	int *map = malloc(sizeof(int) * (NB_OBJS + 1));
	int nb = 0;
	int j = 0;
	char *s = malloc(sizeof(char) * 10);
	int fd = open(name, O_RDONLY);

	for (int i = 0; i < NB_OHEIGHT; i++) {
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
	}
	close(fd);
	return (map);
}

void set_map_in_file(int *map, char *name)
{
	int fd = open(name, O_WRONLY | O_TRUNC | O_CREAT);
	int len;

	for (int j = 0; j < NB_OHEIGHT; j++) {
		for (int i = 0; i < NB_OWIDTH; i++) {
			len = my_strlen(int_to_char(map[i + NB_OWIDTH * j]));
			write(fd, int_to_char(map[i + NB_OWIDTH * j]), len);
			if (i < NB_OWIDTH - 1)
				write(fd, " ", 1);
		}
		if (j < NB_OHEIGHT - 1)
			write(fd, "\n", 1);
	}
	close(fd);
}

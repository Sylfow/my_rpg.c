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

int set_nb_map(char *s, int *map, int nb, int j)
{
	s[j] = '\0';
	map[nb] = char_to_int(s);
	nb++;
	return (nb);
}


int *create_map(char *name)
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

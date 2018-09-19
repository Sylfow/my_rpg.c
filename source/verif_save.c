/*
** EPITECH PROJECT, 2018
** verif_save
** File description:
** verif save
*/

#include "main.h"

char *next_flag(char *save, char *flag)
{
	static int pipe = 0;
	int cpy = 0;
	static int end = 0;

	if (end == 1)
		return (NULL);
	while (save[pipe] != '|' && save[pipe] != '\0') {
		flag[cpy] = save[pipe];
		cpy = cpy + 1;
		pipe = pipe + 1;
	}
	if (save[pipe] == '\0')
		end = 1;
	pipe = pipe + 1;
	flag[cpy] = '\0';
	return (flag);
}

void initialize(char *save, player_t *player)
{
	char *flag = malloc(sizeof(char) * 6);
	int i = 0;

	player->stats = malloc(sizeof(int) * NB_STATS);
	while ((flag = next_flag(save, flag)) != NULL) {
		player->stats[i] = my_getnbr(flag);
		i = i + 1;
	}
	player->name = malloc(sizeof(char) * 18);
	player->name = my_strcpy(player->name, "Inspecteur Magret");
	free(flag);
}

char *put_at_end(char *str, char *put)
{
	int i = 0;
	int at = 0;

	while (str[i] != '\0')
		i = i + 1;
	while (put[at] != '\0') {
		str[i] = put[at];
		i = i + 1;
		at = at + 1;
	}
	str[i] = '\0';
	return (str);
}

char *titos(int *stats, char *str)
{
	int i = 0;

	while (i <= NB_STATS - 1) {
		put_at_end(str, my_itoa(stats[i]));
		if (i < NB_STATS - 1)
			put_at_end(str, "|");
		i = i + 1;
	}
	return (str);
}

void verif_save(player_t *player, int new)
{
	int save = open("my_rpg.dns", O_RDONLY);

	if (save == -1 || new == 2) {
		save = open("my_rpg.dns", O_CREAT | O_TRUNC | O_RDWR, S_IRUSR |
			    S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
		putstr_fd("1|0|55|55|20|20|15|15|30|30|15|15|0|0|550|450|0|0|0|0|0|0|0|0|0|0",
			save);
		close(save);
	}
	save = open("my_rpg.dns", O_RDONLY);
	initialize(get_next_line(save), player);
	close(save);
}

void save(player_t *player)
{
	char *str = malloc(sizeof(char) * (6 * NB_STATS + NB_STATS));
	int save;

	str[0] = '\0';
	player->stats[14] = player->pos.x;
	player->stats[15] = player->pos.y;
	if ((save = open("my_rpg.dns", O_RDWR)) == -1) {
		close(save);
		verif_save(player, 0);
	}
	str = titos(player->stats, str);
	write(save, str, my_strlen(str));
	save = close(save);
}

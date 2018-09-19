/*
** EPITECH PROJECT, 2018
** attack
** File description:
** spells for main character
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#ifndef READ_SIZE
#define READ_SIZE (100)

#endif

typedef struct attack_type {
	int power;
	int precision;
	int mana;
} spell_b;

/*
  0 = lvl;
  1 = xp;
  2 = max_hp;
  3 = hp;
  4 = max_mana;
  5 = mana;
  6 = max_att;
  7 = att;
  8 = max_def;
  9 = def;
  10 = max_spe;
  11 = spe;
  12 = gold;
*/

typedef struct carac_t {
	char *name;
	int *stats;
} carac;

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i = i + 1;
	}
}

int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i = i + 1;
	return (i);
}
/*
void putchar_fd(char c, int *fd)
{
	write(*fd, &c, 1);
}

void write_file(char *str, int fd, int end, int i)
{
	int c = 0;

	while (str[c] != '\0') {
		putchar_fd(str[c], &fd);
		c = c + 1;
	}
	if (i < end)
		putchar_fd('|', &fd);
	else
		putchar_fd('\0', &fd);
}
*/
char *my_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i]) {
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}

int my_getnbr(char *str)
{
	int i = 0;
	int n = 0;

	if (str[0] == '-' && str[1] != '\0')
		i = i + 1;
	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9')
			exit(84);
		n = n + str[i] - 48;
		n = n * 10;
		i = i + 1;
	}
	n /= 10;
	if (str[0] == '-')
		return (-1 * n);
	else
		return (n);
}

int my_put_nbr(int nb)
{
	if (nb < 0) {
		nb = -nb;
		my_putchar('-');
	}
	if (nb > 9) {
		my_put_nbr(nb / 10);
		my_put_nbr(nb % 10);
	} else
		my_putchar(nb + 48);
	return (0);
}

char *my_itoa(int nb)
{
	int len = 0;
	char *str;
	int tmp = nb;

	while (tmp > 0) {
		tmp /= 10;
		len++;
	}
	str = malloc(sizeof(*str) * (len + 1));
	str[len] = '\0';
	while (len--) {
		str[len] = nb % 10  + '0';
		nb /= 10;
	}
	return (str);
}

char *get_string(char *s, char *s2)
{
	int i;
	int j = 0;
	int line = 0;
	int check = 0;

	for (i = 0; s[i]; i++) {
		if (check == 1) {
			s2[j] = s[i];
			j++;
		}
		else if (s[i] == '\n') {
			line = i;
			check = 1;
		}
	}
	if (line > 0)
		s[line] = '\0';
	s2[j] = '\0';
	return (s);
}

void get_string2(char *s2, int fd)
{
	int check = 0;
	int i;
	int j = 0;
	char *s3 = malloc(sizeof(char) * (READ_SIZE + 1));

	while (check == 0) {
		read(fd, s3, READ_SIZE);
		for (i = 0; s3[i]; i++) {
			if (check == 1) {
				s2[j] = s3[i];
				j++;
			}
			if (s3[i] == '\n')
				check = 1;
		}
	}
	s2[j] = '\0';
}

char *my_strcat(char *s2, char *s)
{
	char *new_s = malloc(sizeof(char) * (READ_SIZE + 1));
	int i;
	int j;

	for (i = 0; s2[i]; i++)
		new_s[i] = s2[i];
	for (j = 0; s[j]; j++) {
		new_s[i] = s[j];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

char *get_next_line(int fd)
{
	char *s = malloc(sizeof(char) * (READ_SIZE + 1));
	static char s2[READ_SIZE + 1];
	static int size = 0;

	if (size != my_strlen(s2) && size > 0)
		return (NULL);
	if (s == NULL)
		return (NULL);
	if (read(fd, s, READ_SIZE - my_strlen(s2)) == 0)
		if (s2[0] == '\0')
			return (NULL);
	s = my_strcat(s2, s);
	s = get_string(s, s2);
	if (my_strlen(s) == READ_SIZE)
		get_string2(s2, fd);
	size = my_strlen(s2);
	return (s);
}

unsigned int my_time(void)
{
	int *temp = malloc(sizeof(int) * 3);
	unsigned long size = 0;
	
	size = (unsigned long) temp;
	free(temp);
	return ((unsigned int) size / 1000000);
}

int random_number(int min, int max)
{
	return (rand() % (max - min) + min);
}

int critical_hit(int lvl)
{
	int a = random_number(1, 16);

	if (a == 1) {
		printf("Critical Hit!\n");
		return (2);
	} else
		return (1);
}
/*
void calcul_damage(carac *cast, carac *target, spell_b spell)
{
	int damage;

	printf("\n\n%s attack %s :\n", cast->name, target->name);
	if (random_number(0, 100) < spell.precision) {
		damage = (((((cast->max_hp * 40 + 2) * cast->att * spell.power) / (target->def * 50)) + 2) * random_number(85, 100) * critical_hit(cast->lvl)) / 10000;
		printf("deal %i damages\n", damage);
		target->hp = target->hp - damage;
		if (target->hp < 0)
			target->hp = 0;
		printf("%s have %i max hp and now he is at %i hp\n", target->name, target->max_hp, target->hp);
		if (target->hp <= 0)
			printf("%s is dead\n", target->name);
		else
			printf("Next turn\n");
	} else
		printf("\n%s dodged the attack\n", target->name);
}
*/
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

void initialize(char *save, carac *player)
{
	char *flag = malloc(sizeof(char) * 6);
	int i = 0;

	player->stats = malloc(sizeof(int) * 13);
	while ((flag = next_flag(save, flag)) != NULL) {
		player->stats[i] = my_getnbr(flag);
		i = i + 1;
	}
	free(flag);
	player->name = malloc(sizeof(char) * 18);
	player->name = my_strcpy(player->name, "Inspecteur Magret");
}

void new_game(carac *player)
{
	int save = open("my_rpg.dns", O_RDONLY);

	if (save == -1) {
		save = open("my_rpg.dns", O_CREAT | O_RDWR);
		write(save, "01|00000|055|055|020|020|015|015|030|030|015|015|00000", 54);
	}
	initialize(get_next_line(save), player);
	close(save);
}
/*
void save_mode(carac player)
{
	int save = open("my_rpg.dns", O_WRONLY | O_TRUNC);
	char *save_mode = malloc(sizeof(char) * 6);
	int i = 0;

	if (save == -1) {
		save = open("my_rpg.dns", O_CREAT | O_RDWR);
	}
	while (i <= 13) {
		save_mode = my_itoa(player.stats[i]);
		write_file(save_mode, save, 13, i);
	}
}
*/
int main(void)
{
	carac player;
	int i = 0;

	new_game(&player);
	srand(my_time());
	/*while (player.hp > 0 && enemy.hp > 0) {
		if (player.hp > 0)
			calcul_damage(&player, &enemy, tackle);
		if (enemy.hp > 0)
			calcul_damage(&enemy, &player, tackle);
			}*/
	save_mode(player);
}

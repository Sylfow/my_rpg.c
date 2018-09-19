/*
** EPITECH PROJECT, 2018
** utils2.c
** File description:
** utils2
*/

#include "my_rpg.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char *s)
{
	for (int i = 0; s[i]; i++)
		my_putchar(s[i]);
}

char *my_strcpy_map(char *s)
{
	char *s2 = malloc(sizeof(char) * (my_strlen(s) + 1));
	int i;

	for (i = 0; s[i]; i++)
		s2[i] = s[i];
	s2[i] = '\0';
	return (s2);
}

int my_strcmp_map(char *s1, char *s2)
{
	int len1 = my_strlen(s1);
	int len2 = my_strlen(s2);

	if (len1 != len2)
		return (0);
	for (int i = 0; s1[i]; i++)
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

char *my_strcat_map(char *s1, char *s2)
{
	char *new_s = malloc(
		sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
	int i;
	int j = 0;

	for (i = 0; s1[i]; i++)
		new_s[i] = s1[i];
	for (j = 0; s2[j]; j++) {
		new_s[i] = s2[j];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get next line
*/

#include "main.h"

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

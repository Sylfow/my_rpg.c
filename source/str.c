/*
** EPITECH PROJECT, 2018
** str
** File description:
** str function
*/

#include "main.h"

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
			return (0);
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

void putstr_fd(char *str, int fd)
{
	write(fd, str, my_strlen(str));
}

int my_strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	for (i = 0; str[i]; i++);
	return (i);
}

int my_strcmp(char *s1, char *s2)
{
	int len1 = my_strlen(s1);
	int len2 = my_strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (len1 != len2)
		return (0);
	for (int i = 0; s1[i]; i++)
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

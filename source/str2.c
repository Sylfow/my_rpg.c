/*
** EPITECH PROJECT, 2018
** str2
** File description:
** str function
*/

#include "str.h"
#include "main.h"

char *my_itoa(int nb)
{
	int len = 0;
	char *str;
	int tmp = nb;

	if (nb == 0) {
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
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

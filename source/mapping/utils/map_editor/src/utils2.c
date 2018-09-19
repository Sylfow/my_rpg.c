/*
** EPITECH PROJECT, 2018
** utils2.c
** File description:
** utils2
*/

#include "main.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char *s)
{
	for (int i = 0; s[i]; i++)
		my_putchar(s[i]);
}

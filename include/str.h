/*
** EPITECH PROJECT, 2018
** str.h
** File description:
** str header
*/

#ifndef STR_H_
#define STR_H_

char *my_strcpy(char *, char *);
int my_getnbr(char *);
void putstr_fd(char *, int);
int my_strlen(char *);
int my_strcmp(char *, char *);

char *get_string(char *, char *);
void get_string2(char *, int);
char *my_strcat(char *, char *);
char *get_next_line(int);

char *set_char(char *, char *);
char *int_to_char(int);
int char_to_int(char *);

char *my_itoa(int);

#endif

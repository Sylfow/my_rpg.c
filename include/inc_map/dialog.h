/*
** EPITECH PROJECT, 2018
** dialog.h
** File description:
** dialog header
*/

#ifndef DIALOG_H_
#define DIALOG_H_

dialog_t init_dialog(void);
void display_dialog(window_t *, map_t *, player_t *, dialog_t *);
void set_text_dialog(window_t *, dialog_t *);
void set_text2_dialog(window_t *, dialog_t *, char *);
char *get_info(char *, int);

void start_dialog(window_t *, dialog_t *, int *, char *);
void check_dialog2(window_t *, player_t *, dialog_t *);
void check_dialog(window_t *, player_t *, dialog_t *);

//Quest
void set_dialog_quest(window_t *, dialog_t *, char *);
void quest(window_t *, dialog_t *, int);
void get_quest(window_t *, player_t *, dialog_t *);

#endif

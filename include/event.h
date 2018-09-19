/*
** EPITECH PROJECT, 2018
** event.h
** File description:
** event header
*/

#ifndef EVENT_H_
#define EVENT_H_

//Event Mouse
int event_button_main_menu(window_t *, button_t *, int);
int action_mouse(window_t *, button_t *);
void do_action(window_t *, scene_t *, player_t *, int);

//Event
int event_main_menu(window_t *, scene_t *, player_t *);
void event_key_main_menu(window_t *, scene_t *, player_t *);

#endif

/*
** EPITECH PROJECT, 2018
** event.h
** File description:
** event header
*/

#ifndef EVENT_H_
#define EVENT_H_

//Key Event
void event_all(window_t *, player_t *, map_t *, dialog_t *);
void switch_key(window_t *, player_t *, map_t *, dialog_t *);

//Game Event
void event_key_game(window_t *, player_t *, map_t *);
void switch_move_up(window_t *, player_t *, map_t *);
void switch_move_down(window_t *, player_t *, map_t *);
void switch_move_left(window_t *, player_t *, map_t *);
void switch_move_right(window_t *, player_t *, map_t *);

//Fight Event
void event_fight(window_t *, fight_t *);

//Dialog Event
void event_dialog(window_t *, player_t *, map_t *, dialog_t *);
void event_key_dialog(window_t *, player_t *, map_t *, dialog_t *);

//Mouse Event
void set_hit(window_t *, fight_t *, sfVector2i);
void event_button_fight(window_t *, fight_t *);

//Pause
void action_pause(window_t *, player_t *, int);
void switch_rect(button_t *, int);
void event_button_menu(window_t *, player_t *);

#endif

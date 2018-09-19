/*
** EPITECH PROJECT, 2018
** event_boss.h
** File description:
** event_boss header
*/

#ifndef EVENT_BOSS_H_
#define EVENT_BOSS_H_

int button_is_clicked(button_t *, sfVector2i);
int zone_is_clicked(sfVector2f, sfVector2f, sfVector2i);
void set_size(button_t *, int, int);
void event_fight(window_t *, scene_t *, fight_t *, game_objs_t *);

void action_fight(window_t *, scene_t *, fight_t *, game_objs_t *);
void action_menu_fight(window_t *, button_t *);
void mouse_scene_fight(window_t *, button_t *);
void mouse_fight_buttons(window_t *, scene_t *, sfVector2i);
void mouse_menu_fight(window_t *, scene_t *, fight_t *, game_objs_t *);

void deselect_all_buttons(scene_t *);
void deselect_all_mobs(game_objs_t *, fight_t *);
void switch_color(window_t *, scene_t *, game_objs_t *, int);

#endif

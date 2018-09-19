/*
** EPITECH PROJECT, 2018
** test.c
** File description:
** test
*/

#include "main.h"

char *get_info_scene(char *line, int nb_info)
{
	char *s = malloc(sizeof(char) * (my_strlen(line) + 1));
	int nb_space = 1;
	int i = 0;
	int j = 0;

	for (i = 0; nb_space < nb_info; i++) {
		if (line[i] == ' ')
			nb_space++;
	}
	for (; s[j - 1] != ' ' && s[j - 1] != '\n'; j++) {
		s[j] = line[i];
		i++;
	}
	s[j - 1] = '\0';
	return (s);
}

void set_objs_rect(game_objs_t *obj, char *line)
{
	int left;
	int top;
	int width;
	int height;

	top = char_to_int(get_info_scene(line, 4));
	left = char_to_int(get_info_scene(line, 5));
	width = char_to_int(get_info_scene(line, 6));
	height = char_to_int(get_info_scene(line, 7));
	obj->rect = set_rect(top, left, width, height);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
}

void set_objs(scene_t *scene, FILE *file)
{
	char *line = NULL;
	size_t n;
	int x;
	int y;

	getline(&line, &n, file);
	getline(&line, &n, file);
	scene->nb_objs = char_to_int(get_info_scene(line, 1));
	scene->obj = malloc(sizeof(game_objs_t) * scene->nb_objs);
	for (int i = 0; i < scene->nb_objs; i++) {
		getline(&line, &n, file);
		x = char_to_int(get_info_scene(line, 2));
		y = char_to_int(get_info_scene(line, 3));
		create_obj(&scene->obj[i], get_info_scene(line, 1), x, y);
		set_objs_rect(&scene->obj[i], line);
	}
}

void set_buttons(scene_t *scene, FILE *file)
{
	char *line = NULL;
	size_t n;
	int x;
	int y;

	getline(&line, &n, file);
	getline(&line, &n, file);
	scene->nb_buttons = char_to_int(get_info_scene(line, 1));
	scene->buttons = malloc(sizeof(button_t) * scene->nb_buttons);
	for (int i = 0; i < scene->nb_buttons; i++) {
		getline(&line, &n, file);
		x = char_to_int(get_info_scene(line, 2));
		y = char_to_int(get_info_scene(line, 3));
		create_rect_shape(&scene->buttons[i],
				get_info_scene(line, 1), x, y);
		scene->buttons[i].id = char_to_int(get_info_scene(line, 4));
		x = char_to_int(get_info_scene(line, 5));
		set_size(&scene->buttons[i], x,
			char_to_int(get_info_scene(line, 6)));
	}
}

void create_scene(scene_t *scene, int nb_scene)
{
	FILE *file = fopen("utils/path", "r");
	char *line = NULL;
	char *title = NULL;
	size_t n;

	for (int j = 0; my_strcmp(int_to_char(nb_scene), title) != 1; j = 0) {
		do
			getline(&line, &n, file);
		while (line[0] != '-');
		title = malloc(sizeof(char) * my_strlen(line));
		for (int i = 1; line[i] != '=' && line[i]; i++) {
			title[j] = line[i];
			j++;
		}
		title[j] = '\0';
	}
	set_objs(scene, file);
	set_buttons(scene, file);
	fclose(file);
}

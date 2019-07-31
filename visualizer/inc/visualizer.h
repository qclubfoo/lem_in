/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:37:50 by ilya              #+#    #+#             */
/*   Updated: 2019/07/31 17:38:03 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H
# include <stdbool.h>
# include <SDL.h>
# include <math.h>
# include <stdlib.h>
# define WINX 1024
# define WINY 1024
# define SPHERE 1
# define LIGHT 0
# define FOV 90 * ((2 * 3.1415) / 360)
# define BUFF_SIZE 128;

typedef struct			s_map
{
	int					ants;
	struct s_rooms		*rooms;
	struct s_bonds		*bonds;
	struct s_steps		*steps;
}						t_map;


typedef struct			s_rooms
{
	char				*name;
	int					x;
	int					y;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_bonds
{
	int					x_1;
	int					y_1;
	int					x_2;
	int					y_2;
	struct s_bonds		*next;
}						t_bonds;

typedef struct			s_step
{
	int					ant_num;
	int					x;
	int					y;
	struct s_step		*next;
}						t_step;

typedef struct			s_steps
{
	struct s_step		*step;
	struct s_steps		*next;
}						t_steps;

typedef struct			s_sdl
{
	SDL_Window			*win;
	SDL_Renderer		*render;
	SDL_Texture			*fillscreen;
	SDL_Surface			*surf;
	SDL_Event			event;
}						t_sdl;

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct			s_camera
{
	t_vector			direct;
	t_vector			pos;
	t_vector			norm;
	double				dist;
}						t_camera;

typedef struct			s_screen
{
	t_vector			left;
	t_vector			right;
	t_vector			up;
	t_vector			down;
	t_vector			borders_x;
	t_vector			borders_y;
}						t_screen;

typedef struct			s_object
{
	int					type;
	t_vector			center;
	double				radius;
	struct s_object		*next;
	int					color;
}						t_object;

typedef struct			s_objects
{
	t_object			*light;
	t_object			*bodies;
}						t_objects;


t_map					*adding_data(void);
char					*ft_read(void);
char					**ft_split_input(char *input, t_map *map);

void					ft_make_map(t_rooms **rooms, t_bonds **bonds, t_steps **steps, char **str);
int						ft_make_hash(char **str, int i);
void					ft_return(char **str);

void					ft_make_room(char *str, int *check_type, t_rooms **rooms);
t_rooms					*add_first_room(void);
void					add_new_room(t_rooms *rooms);
void					ft_write_room(t_rooms *rooms, char **make_room);

void					ft_make_bond(char *str, int *check_type, t_bonds **bonds, t_rooms *rooms);
t_bonds					*add_first_bond(void);
void					add_new_bond(t_bonds *bonds);
void					write_new_bond(t_bonds *bonds, t_rooms *rooms, char **str);

void					ft_make_step(char *str, t_steps **steps, t_rooms *rooms);
void					ft_remove_l(char **make_step);
void					ft_find_step(t_step **step, t_rooms *rooms, char *str);
t_steps					*add_first_steps(void);
void					add_new_steps(t_steps *steps);
t_step					*add_first_separate_step(void);
void					add_new_separate_step(t_step **step);

void					ft_free_map(t_map *map);
void					ft_free_rooms(t_rooms *rooms);
void					ft_free_bonds(t_bonds *bonds);
void					ft_free_steps(t_steps *steps);
#endif
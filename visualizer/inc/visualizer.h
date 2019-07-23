/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:37:50 by ilya              #+#    #+#             */
/*   Updated: 2019/07/23 13:46:16 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdbool.h>
# include </usr/include/SDL2/SDL.h>
# include <math.h>
# define WINX 1024
# define WINY 1024
# define SPHERE 1
# define LIGHT 0
# define FOV 90 * ((2 * 3.1415) / 360)

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

// t_vector				cross_product(t_vector one, t_vector two);
// double					scalar_product(t_vector one, t_vector two);
// void					rotate_horizontal(t_camera *camera, double angle);
// void					rotate_vertical(t_camera *camera, double angle);
// t_vector				rotate(t_vector axis, t_vector vector, double angle);
// t_vector				vector_summ(t_vector one, t_vector two);
// t_vector				vector_diff(t_vector one, t_vector two);
// t_vector				vector_multiply(t_vector vector, double number);
// double					distance(t_vector one, t_vector two);
// void					init_camera(t_camera *cam);
// void					init_sdl(t_sdl *sdl);
// void					init_objects(t_objects *objects);
// int						trace_ray(t_vector direction, t_objects *objects, t_vector point, int is_light);
// void					print_vec(t_vector direction);
// t_vector				normalize(t_vector vector);
// int						vector_equal(t_vector one, t_vector two);

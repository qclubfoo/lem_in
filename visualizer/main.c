/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:37:46 by ilya              #+#    #+#             */
/*   Updated: 2019/07/23 13:48:11 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int				key(t_sdl *sdl, t_camera *camera, int *i)
{
	const Uint8	*key;

	key = SDL_GetKeyboardState(NULL);
	// *i = sdl->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE ?
	// 	0 : 1;
	// if (*i == 0)
	// 	return (0);
	// if (key[SDL_SCANCODE_UP])
	// 	camera->pos.y += 0.1;
	// else if (key[SDL_SCANCODE_DOWN])
	// 	camera->pos.y -= 0.1;
	// else if (key[SDL_SCANCODE_LEFT])
	// 	camera->pos.x -= 0.1;
	// else if (key[SDL_SCANCODE_RIGHT])
	// 	camera->pos.x += 0.1;
	// else if (key[SDL_SCANCODE_W])
	// 	camera->pos = vector_summ(camera->pos, camera->direct);
	// else if (key[SDL_SCANCODE_S])
	// 	camera->pos = vector_summ(camera->pos, vector_multiply(camera->direct, -1));
	// else
	// 	return (0);
	return (1);
}

void			update_screen(t_camera *camera, t_sdl *sdl, t_objects *objects)
{
	int			x;
	int			y;
	t_vector	direction;
	t_screen	screen;

	x = 0;
	while (x < WINX)
	{
		y = 0;
		while (y < WINY)
		{
			((int *)(sdl->surf->pixels))[x + y * WINX] = 0xFF0000;
			y++;
		}
		x++;
	}
}

int				mouse(t_sdl *sdl, t_camera *camera)
{
	return (1);
}

int				main()
{
	t_sdl		sdl;
	t_camera	camera;
	t_objects	objects;
	int			i;
	int			happened;
	int			drag;

	init_sdl(&sdl);
	init_camera(&camera);
	init_objects(&objects);
	i = 1;
	happened = 1;
	drag = 0;
	while (i)
	{
		while (SDL_PollEvent(&sdl.event) != 0)
		{
			if (sdl.event.type == SDL_QUIT)
				i = 0;
			else if (sdl.event.type == SDL_KEYDOWN)
				happened = key(&sdl, &camera, &i);
			else if (sdl.event.type == SDL_MOUSEBUTTONDOWN || sdl.event.type == SDL_MOUSEBUTTONUP)
				drag = !drag;
			else if (sdl.event.type == SDL_MOUSEMOTION && drag == 1)
				happened = mouse(&sdl, &camera);
		}
		if (happened)
		{
			happened = 0;
			update_screen(&camera, &sdl, &objects);
		}
		SDL_UpdateWindowSurface(sdl.win);
	}
	SDL_DestroyWindow(sdl.win);
	SDL_Quit();
	return (0);
}

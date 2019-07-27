/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:10:34 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/27 21:03:38 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_room	*find_exit(t_map *map)
{
	t_room		*room;

	room = map->rooms;
	while (room != NULL && room->se != 2)
		room = room->next;
	return (room);
}

void	set_labels_and_dist(t_map *map)
{
	t_room		*room;

	room = map->rooms;
	while (room)
	{
		room->label = 0;
		room->distance = __INT_MAX__;
		room = room->next;
	}
}

void	set_actual_dist(t_map *map)
{
	t_room		*room;

	room = map->rooms;
	while (room)
	{
		room->actual_dist = room->distance;
		room = room->next;
	}
}

t_queue	*get_minimal_path(t_lemin *lemin)
{
	t_room		*path;
	t_room		*next;
	t_bond		*bond;
	t_queue		*min;
	t_queue		*last;
	int			distance;

	min = NULL;
	last = NULL;
	path = lemin->begin;
	while (path->distance != 0)
	{
		bond = path->bonds;
		while (bond)
		{
			if (bond->bond->distance < distance)
			{
				next = bond->bond;
				add_to_queue(&min, &last, next);
				break ;
			}
			bond = bond->next;
		}
		path = next;
	}
	return (min);
}

int		dist_map(t_lemin *lemin)
{
	set_labels_and_dist(lemin->map);
	set_distance(lemin->map);
	set_actual_dist(lemin->map);
	return (0);
}

void	print_map(t_map *map)
{
	t_room		*curr;

	curr = map->rooms;
	while (curr != NULL)
	{
		ft_printf("%s %d\n", curr->name, curr->distance);
		curr = curr->next;
	}
}

void	redo_hefts(t_queue *path, t_lemin *lemin)
{
	path = NULL;
	lemin = NULL;
	// return (0);
}

void	solve(t_map *map, t_lemin *lemin)
{
	int			ants;

	ants = 0;
	delete_unconnected(map);
	dist_map(lemin);
	print_map(map);
	while (ants < map->ants)
	{
		(lemin->ants)[ants].path = get_minimal_path(lemin);
		redo_hefts(((lemin->ants)[ants]).path, lemin);
		ants++;
	}
}

int		 main(void)
{
	t_lemin		lemin;
	t_map		*map;

	map = validate();
	lemin.begin = find_entry(map);
	lemin.end = find_exit(map);
	lemin.map = map;
	lemin.ants = (t_ant*)malloc(sizeof(t_ant) * map->ants);
	if ((connected(map)))
		ft_printf("%s\n", map->file);
	else
	{
		/* error */
		exit (0);
	}
	solve(map, &lemin);
	free(map->file);
	return (0);
}

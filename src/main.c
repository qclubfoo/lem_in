/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:10:34 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/28 18:27:28 by sbrella          ###   ########.fr       */
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
		distance = path->distance;
		while (bond)
		{
			if (bond->bond->distance < distance)
			{
				distance = bond->bond->distance;
				next = bond->bond;
			}
			bond = bond->next;
		}
		add_to_queue(&min, &last, next);
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
	printf("\n");
}

void	set_labels_to_zero(t_lemin *lemin)
{
	t_room		*room;

	room = lemin->map->rooms;
	while (room != NULL)
	{
		room->label = 0;
		room = room->next;
	}
}

void	redistance(t_room *room)
{
	t_bond		*list;
	int			dist;

	if (room->se == 2)
		return ;
	list = room->bonds;
	dist = __INT_MAX__;
	if (room->label != 1)
	{
		while (list != NULL)
		{
			if (list->bond->distance < dist && list->bond->se != 2)
				dist = list->bond->distance + 1;
			list = list->next;
		}
		if (room->se != 2)
			room->distance = dist;
	}
}

void	redo_hefts(t_queue *path, t_lemin *lemin)
{
	t_queue		*dbl;
	t_queue		*min;
	t_queue		*last;
	t_room		*room;
	int			dist;

	min = NULL;
	last = NULL;
	dbl = path;
	lemin->begin->distance++;
	while (dbl != NULL)
	{
		if (dbl->room != lemin->end)
			dbl->room->distance = dbl->room->distance + 1;
		dbl = dbl->next;
	}
	dbl = path;
	set_labels_to_zero(lemin);
	add_neighbors_to_queue(lemin->begin, &min, &last);
	while (dbl != NULL)
	{
		add_neighbors_to_queue(dbl->room, &min, &last);
		dbl->room->label = 1;
		dbl = dbl->next;
	}
	while (min != NULL)
	{
		dist = min->room->distance;
		redistance(min->room);
		if (dist != min->room->distance)
		{
			room = min->room;
			delete_first_elem(&min);
			add_neighbors_to_queue(room, &min, &last);
			room->label = 1;
		}
		else
			delete_first_elem(&min);
	}
}

void	print_path(t_queue *path, int ants)
{
	while (path != NULL)
	{
		printf("%s %d\n", path->room->name, ants);
		path = path->next;
	}
	printf("\n");
}

void	solve(t_map *map, t_lemin *lemin)
{
	int			ants;

	ants = 0;
	delete_unconnected(map);
	dist_map(lemin);
	// print_map(map);
	// printf("\n");
	while (ants < map->ants)
	{
		(lemin->ants)[ants].path = get_minimal_path(lemin);
		print_path((lemin->ants)[ants].path, ants);
		redo_hefts(((lemin->ants)[ants]).path, lemin);
		// print_map(map);
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

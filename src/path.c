/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:02:22 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/31 18:28:02 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*find_exit(t_map *map)
{
	t_room		*room;

	room = map->rooms;
	while (room != NULL && room->se != 2)
		room = room->next;
	return (room);
}

void			set_labels_and_dist(t_map *map)
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

t_room			*lowest_dist(t_room *path)
{
	t_room		*next;
	t_bond		*bond;
	int			distance;

	bond = path->bonds;
	distance = path->distance;
	while (bond)
	{
		if (bond->bond->distance <= distance)
		{
			distance = bond->bond->distance;
			next = bond->bond;
		}
		bond = bond->next;
	}
	return (next);
}

t_queue			*get_minimal_path(t_lemin *lemin)
{
	t_room		*path;
	t_queue		*min;
	t_queue		*last;
	t_room		*next;

	min = NULL;
	last = NULL;
	path = lemin->begin;
	while (path->distance != 0)
	{
		next = lowest_dist(path);
		add_to_queue(&min, &last, next);
		path = next;
	}
	return (min);
}

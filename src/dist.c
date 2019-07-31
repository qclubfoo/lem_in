/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:33:49 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/31 18:37:36 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			set_actual_dist(t_map *map)
{
	t_room		*room;

	room = map->rooms;
	while (room != NULL)
	{
		room->actual_dist = room->distance;
		room = room->next;
	}
}

int				dist_map(t_lemin *lemin)
{
	set_labels_and_dist(lemin->map);
	set_distance(lemin->map);
	set_actual_dist(lemin->map);
	return (0);
}

void			print_map(t_map *map)
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

void			set_labels_to_zero(t_lemin *lemin)
{
	t_room		*room;

	room = lemin->map->rooms;
	while (room != NULL)
	{
		room->label = 0;
		room = room->next;
	}
}

void			redistance(t_room *room)
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
			if (list->bond->se == 2)
				return ;
			if (list->bond->distance < dist)
				dist = list->bond->distance + 1;
			list = list->next;
		}
		if (room->se != 2)
			room->distance = dist;
	}
}

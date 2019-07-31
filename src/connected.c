/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connected.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:01:35 by ilya              #+#    #+#             */
/*   Updated: 2019/07/31 18:16:34 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		connected(t_map *map)
{
	t_queue		*queue;
	t_room		*entry;
	t_queue		*last;
	int			ret;

	ret = 0;
	queue = NULL;
	last = NULL;
	entry = find_entry(map);
	add_neighbors_to_queue(entry, &queue, &last);
	entry->label = 1;
	while (queue)
	{
		if (queue->room->se == 2)
			ret = 1;
		add_neighbors_to_queue(queue->room, &queue, &last);
		queue->room->label = 1;
		delete_first_elem(&queue);
	}
	return (ret);
}

void	define_dist(t_room *room)
{
	t_bond		*list;
	int			dist;

	list = room->bonds;
	dist = __INT_MAX__;
	if (room->label != 1)
	{
		while (list != NULL)
		{
			if (list->bond->distance < dist)
				dist = list->bond->distance + 1;
			list = list->next;
		}
		room->distance = dist;
	}
}

void	delete_room(t_room *room)
{
	t_bond		*bond;
	t_bond		*next;

	bond = room->bonds;
	while (bond != NULL)
	{
		next = bond->next;
		free(bond);
		bond = next;
	}
	free(room->name);
	free(room);
}

int		delete_unconnected(t_map *map)
{
	t_room		*prev;
	t_room		*curr;
	t_room		*next;

	curr = map->rooms;
	prev = NULL;
	while (curr != NULL)
	{
		next = curr->next;
		if (curr->label != 1)
		{
			if (prev != NULL)
				prev->next = next;
			if (map->rooms == curr)
				map->rooms = map->rooms->next;
			delete_room(curr);
		}
		else
			prev = curr;
		curr = next;
	}
	return (0);
}

int		set_distance(t_map *map)
{
	t_queue		*queue;
	t_room		*entry;
	t_queue		*last;

	queue = NULL;
	last = NULL;
	entry = find_exit(map);
	add_neighbors_to_queue(entry, &queue, &last);
	entry->label = 1;
	entry->distance = 0;
	while (queue)
	{
		define_dist(queue->room);
		add_neighbors_to_queue(queue->room, &queue, &last);
		queue->room->label = 1;
		delete_first_elem(&queue);
	}
	return (0);
}

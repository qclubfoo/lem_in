/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:12:11 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/31 18:16:16 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_to_queue(t_queue **queue, t_queue **last, t_room *room)
{
	if (*queue == NULL)
	{
		*queue = (t_queue*)malloc(sizeof(t_queue));
		*last = *queue;
	}
	else
	{
		(*last)->next = (t_queue*)malloc(sizeof(t_queue));
		(*last) = (*last)->next;
	}
	(*last)->room = room;
	(*last)->next = NULL;
}

void	decisive_add_neighbors(t_room *room, t_queue **queue, t_queue **last)
{
	t_bond		*list;

	list = room->bonds;
	if (room->label != 1)
		while (list != NULL)
		{
			if (list->bond->label != 1)
				add_to_queue(queue, last, list->bond);
			list = list->next;
		}
}

void	add_neighbors_to_queue(t_room *room, t_queue **queue, t_queue **last)
{
	t_bond		*list;

	list = room->bonds;
	if (room->label != 1)
		while (list != NULL)
		{
			add_to_queue(queue, last, list->bond);
			list = list->next;
		}
}

t_room	*find_entry(t_map *map)
{
	t_room		*room;

	room = map->rooms;
	while (room != NULL && room->se != 1)
		room = room->next;
	return (room);
}

void	free_queue(t_queue *queue)
{
	t_queue		*next;

	while (queue != NULL)
	{
		next = queue->next;
		free(queue);
		queue = next;
	}
}

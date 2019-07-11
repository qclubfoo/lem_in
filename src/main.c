/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:10:34 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/11 19:35:37 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

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

void	delete_first_elem(t_queue **queue)
{
	t_queue		*next;

	if (*queue == NULL)
		return ;
	next = (*queue)->next;
	free(*queue);
	*queue = next;
}

int		connected(t_map *map)
{
	t_queue		*queue;
	t_room		*entry;
	t_queue		*last;

	queue = NULL;
	last = NULL;
	entry = find_entry(map);
	add_neighbors_to_queue(entry, &queue, &last);
	entry->label = 1;
	while (queue)
	{
		if (queue->room->se == 2)
		{
			free_queue(queue);
			return (1);
		}
		add_neighbors_to_queue(queue->room, &queue, &last);
		queue->room->label = 1;
		delete_first_elem(&queue);
	}
	return (0);
}

int		 main(void)
{
	t_map   *map;

	map = validate();
	if ((connected(map)))
		ft_printf("%s\n", map->file);
	else
	{
		/* error */
		exit (0);
	}
	free(map->file);
	return (0);
}
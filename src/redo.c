/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:26:38 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/31 19:50:47 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				get_weight(t_queue *path)
{
	int			ret;

	ret = 0;
	while (path != NULL)
	{
		ret++;
		path = path->next;
	}
	return (ret);
}

void			redo_while(t_queue *dbl, t_queue **min, t_queue **last)
{
	int			dist;
	t_room		*room;

	while (dbl != NULL)
	{
		if (dbl->room->se != 2)
			decisive_add_neighbors(dbl->room, min, last);
		dbl->room->label = 1;
		dbl = dbl->next;
	}
	while (*min != NULL)
	{
		dist = (*min)->room->distance;
		redistance((*min)->room);
		if (dist != (*min)->room->distance)
		{
			room = (*min)->room;
			delete_first_elem(min);
			add_neighbors_to_queue(room, min, last);
			room->label = 1;
		}
		else
			delete_first_elem(min);
	}
}

void			redo_hefts(t_queue *path, t_lemin *lemin)
{
	t_queue		*dbl;
	t_queue		*min;
	t_queue		*last;

	min = NULL;
	last = NULL;
	dbl = path;
	lemin->begin->distance = lemin->begin->distance + 1;
	while (dbl != NULL)
	{
		if (dbl->room != lemin->end)
			dbl->room->distance = dbl->room->distance + 1;
		dbl = dbl->next;
	}
	dbl = path;
	set_labels_to_zero(lemin);
	decisive_add_neighbors(lemin->begin, &min, &last);
	lemin->begin->label = 1;
	redo_while(dbl, &min, &last);
}

void			solve(t_map *map, t_lemin *lemin)
{
	int			ants;

	ants = 0;
	delete_unconnected(map);
	dist_map(lemin);
	while (ants < map->ants)
	{
		(lemin->ants)[ants].path = get_minimal_path(lemin);
		redo_hefts(((lemin->ants)[ants]).path, lemin);
		ants++;
	}
}

void			init_ants(t_lemin *lemin)
{
	int			num;
	t_ant		*ants;

	num = 0;
	ants = lemin->ants;
	while (num < lemin->map->ants)
	{
		(lemin->ants)[num].position = lemin->begin;
		(lemin->ants)[num].finish = 0;
		(lemin->ants)[num].number = -1;
		num++;
	}
}

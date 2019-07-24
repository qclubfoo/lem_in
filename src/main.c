/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:10:34 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/23 13:38:52 by ilya             ###   ########.fr       */
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

void	set_labels(t_map *map)
{
	t_room		*room;

	room = map->rooms;
	while (room)
	{
		room->label = 0;
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

	min = NULL;
	last = NULL;
	path = lemin->end;
	while (path->se != 1)
	{
		bond = path->bonds;
		while (bond)
		{
			if (bond->bond->distance < path->distance)
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

int		solve(t_lemin *lemin)
{
	t_queue		*min;

	lemin->paths = (t_queue**)malloc(sizeof(t_queue*) * 2);
	set_labels(lemin->map);
	set_distance(lemin->map);
	set_actual_dist(lemin->map);
	min = get_minimal_path(lemin);
	while (min)
	{
		printf("%s\n", min->room->name);
		min = min->next;
	}
	return (0);
}

int		 main(void)
{
	t_lemin		lemin;
	t_map		*map;

	map = validate();
	lemin.begin = find_entry(map);
	lemin.end = find_exit(map);
	lemin.map = map;
	if ((connected(map)))
		ft_printf("%s\n", map->file);
	else
	{
		/* error */
		exit (0);
	}
	solve(&lemin);
	free(map->file);
	return (0);
}

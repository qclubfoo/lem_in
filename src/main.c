/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:10:34 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/30 21:23:00 by sbrella          ###   ########.fr       */
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
			if (bond->bond->distance <= distance)
			{
				distance = bond->bond->distance;
				next = bond->bond;
			}
			bond = bond->next;
		}
		add_to_queue_begin(&min, &last, next);
		path = next;
	}
	return (min);
}

void	set_actual_dist(t_map *map)
{
	t_room		*room;

	room = map->rooms;
	while (room != NULL)
	{
		room->actual_dist = room->distance;
		room = room->next;
	}
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

int		get_weight(t_queue *path)
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

void	redo_hefts(t_queue *path, t_lemin *lemin)
{
	t_queue		*dbl;
	t_queue		*min;
	t_queue		*last;
	t_room		*room;
	int			dist;
	int			weight;

	min = NULL;
	last = NULL;
	dbl = path;
	weight = 1;//get_weight(path);
	lemin->begin->distance = lemin->begin->distance + weight;
	while (dbl != NULL)
	{
		if (dbl->room != lemin->end)
			dbl->room->distance = dbl->room->distance + weight;
		dbl = dbl->next;
	}
	dbl = path;
	set_labels_to_zero(lemin);
	decisive_add_neighbors(lemin->begin, &min, &last);
	lemin->begin->label = 1;
	while (dbl != NULL)
	{

		if (dbl->room->se != 2)
			decisive_add_neighbors(dbl->room, &min, &last);
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
	// room = lemin->map->rooms;
	// while (room != NULL)
	// {
	// 	room->distance += room->actual_dist;
	// 	room = room->next;
	// }
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
		// print_path((lemin->ants)[ants].path, ants);
		redo_hefts(((lemin->ants)[ants]).path, lemin);
		// print_map(map);
		ants++;
	}
}

void	init_ants(t_lemin *lemin)
{
	int			num;
	t_ant		*ants;

	num = 0;
	ants = lemin->ants;
	while (num < lemin->map->ants)
	{
		(lemin->ants)[num].position = lemin->begin;
		(lemin->ants)[num].finish = 0;
		num++;
	}
}

t_room	*get_next(t_queue *path, t_room *pos)
{
	while (path->room != pos)
		path = path->next;
	return (path->next->room);
}

void	print_moves(t_lemin *lemin)
{
	int			ants;
	int			all;
	t_room		*next;
	static int	i = 0;

	init_ants(lemin);
	all = 0;
	while (all != lemin->map->ants)
	{
		ants = -1;
		while (++ants < lemin->map->ants)
		{
			if (lemin->ants[ants].finish == 1)
				continue;
			if (lemin->ants[ants].position == lemin->begin)
			{
				if (lemin->ants[ants].path->room->ant == 0)
				{
					lemin->ants[ants].position = lemin->ants[ants].path->room;
					if (lemin->ants[ants].path->room->se != 2)
						lemin->ants[ants].path->room->ant = 1;
					else
					{
						all++;
						lemin->ants[ants].finish = 1;
					}
					ft_printf("%d %d-%s ", i, ants + 1, lemin->ants[ants].position->name);
				}
			}
			else
			{
				next = get_next(lemin->ants[ants].path, lemin->ants[ants].position);
				if (next->ant == 0)
				{
					if (next->se != 2)
						next->ant = 1;
					else
					{
						all++;
						lemin->ants[ants].finish = 1;
					}
					lemin->ants[ants].position->ant = 0;
					lemin->ants[ants].position = next;
					ft_printf("%d %d-%s ", i, ants + 1, lemin->ants[ants].position->name);
				}
			}
		}
		i++;
		ft_printf("\n");
	}
}

void	free_path(t_queue **queue)
{
	int			count;

	count = get_weight(*queue);
	while (count-- > 0)
		delete_first_elem(queue);
}

void	free_bonds(t_bond *bonds)
{
	t_bond		*next;

	while (bonds != NULL)
	{
		next = bonds->next;
		free(bonds);
		bonds = next;
	}
}

void	free_everything(t_lemin *lemin)
{
	int			ants;
	t_room		*curr;
	t_room		*next;

	ants = -1;
	while (++ants < lemin->map->ants)
		free_path(&lemin->ants[ants].path);
	free(lemin->ants);
	curr = lemin->map->rooms;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr->name);
		free_bonds(curr->bonds);
		free(curr);
		curr = next;
	}
	free(lemin->map->file);
	free(lemin->map);
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
	print_moves(&lemin);
	free_everything(&lemin);
	return (0);
}

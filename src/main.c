/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:10:34 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/31 19:12:50 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

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

void			redo_hefts(t_queue *path, t_lemin *lemin)
{
	t_queue		*dbl;
	t_queue		*min;
	t_queue		*last;
	t_room		*room;
	int			dist;

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
}

void			print_path(t_queue *path, int ants)
{
	while (path != NULL)
	{
		printf("%s %d\n", path->room->name, ants);
		path = path->next;
	}
	printf("\n");
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
		num++;
	}
}

t_room			*get_next(t_queue *path, t_room *pos)
{
	while (path->room != pos)
		path = path->next;
	return (path->next->room);
}

void			free_path(t_queue **queue)
{
	int			count;

	count = get_weight(*queue);
	while (count-- > 0)
		delete_first_elem(queue);
}

void			free_bonds(t_bond *bonds)
{
	t_bond		*next;

	while (bonds != NULL)
	{
		next = bonds->next;
		free(bonds);
		bonds = next;
	}
}

void			free_everything(t_lemin *lemin)
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

int				main(void)
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
		ft_printf("Error\n");
		exit(0);
	}
	solve(map, &lemin);
	print_moves(&lemin);
	free_everything(&lemin);
	return (0);
}

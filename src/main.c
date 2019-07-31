/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:17:31 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/31 19:45:17 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		ft_printf("ERROR\n");
		exit(0);
	}
	solve(map, &lemin);
	print_moves(&lemin);
	free_everything(&lemin);
	return (0);
}

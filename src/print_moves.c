/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:41:10 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/31 18:57:10 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_begin(t_lemin *lemin, int ants, int *all)
{
	if (lemin->ants[ants].path->room->ant == 0)
	{
		lemin->ants[ants].position = lemin->ants[ants].path->room;
		if (lemin->ants[ants].path->room->se != 2)
			lemin->ants[ants].path->room->ant = 1;
		else
		{
			(*all)++;
			lemin->ants[ants].finish = 1;
		}
		ft_printf("L%d-%s ", ants + 1,
		lemin->ants[ants].position->name);
	}
}

void			print_middle(t_lemin *lemin, int ants, int *all)
{
	t_room		*next;

	next = get_next(lemin->ants[ants].path,
	lemin->ants[ants].position);
	if (next->ant == 0)
	{
		if (next->se != 2)
			next->ant = 1;
		else
		{
			(*all)++;
			lemin->ants[ants].finish = 1;
		}
		lemin->ants[ants].position->ant = 0;
		lemin->ants[ants].position = next;
		ft_printf("L%d-%s ", ants + 1,
		lemin->ants[ants].position->name);
	}
}

void			print_moves(t_lemin *lemin)
{
	int			ants;
	int			all;

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
				print_begin(lemin, ants, &all);
			else
				print_middle(lemin, ants, &all);
		}
		ft_printf("\n");
	}
}

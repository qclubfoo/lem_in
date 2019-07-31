/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:13:23 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/30 20:14:19 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/visualizer.h"

void	ft_free_map(t_map *map)
{
	ft_free_rooms(map->rooms);
	ft_free_bonds(map->bonds);
	ft_free_steps(map->steps);
	free(map);
	map = NULL;
}

void	ft_free_rooms(t_rooms *rooms)
{
	t_rooms	*tmp;
	t_rooms *ttmp;

	tmp = rooms;
	while (tmp != NULL)
	{
		ttmp = tmp->next;
		free(tmp->name);
		tmp->name = NULL;
		free(tmp);
		tmp = NULL;
		tmp = ttmp;
	}
}

void	ft_free_bonds(t_bonds *bonds)
{
	t_bonds	*tmp;
	t_bonds	*ttmp;

	tmp = bonds;
	while (tmp != NULL)
	{
		ttmp = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = ttmp;
	}
}

void	ft_free_steps(t_steps *steps)
{
	t_steps	*tmp;
	t_steps	*ttmp;
	t_step	*tmp_s;
	t_step	*ttmp_s;

	tmp = steps;
	while (tmp != NULL)
	{
		ttmp = tmp->next;
		tmp_s = tmp->step;
		while (tmp_s != NULL)
		{
			ttmp_s = tmp_s->next;
			free(tmp_s);
			tmp_s = ttmp_s;
		}
		free(tmp);
		tmp = ttmp;
	}
}

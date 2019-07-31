/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:39:17 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/31 19:06:05 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_map	*validate(void)
{
	char	*str;
	t_check	*check;
	t_map	*map;

	str = ft_read();
	if (str == NULL)
		ft_exit(str);
	check = ft_check_map(str);
	check == NULL ? ft_exit(str) : 0;
	ft_check_el(check, str);
	map = (t_map*)malloc(sizeof(t_map));
	if (ft_make_map(str, map))
		ft_free_and_exit(map, check, str);
	if (ft_check_rep_rooms(map->rooms))
		ft_free_and_exit(map, check, str);
	map->file = str;
	free(check);
	check = NULL;
	return (map);
}

void	ft_exit(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	write(2, "ERROR\n", 6);
	exit(0);
}

void	ft_free_map(t_map *map)
{
	t_room	*tmp_r;
	t_bond	*tmp_b;

	while (map->rooms != NULL)
	{
		tmp_r = map->rooms;
		map->rooms = map->rooms->next;
		free(tmp_r->name);
		tmp_r->name = NULL;
		while (tmp_r->bonds != NULL)
		{
			tmp_b = tmp_r->bonds;
			tmp_r->bonds = tmp_r->bonds->next;
			free(tmp_b);
			tmp_b = NULL;
		}
		free(tmp_r);
		tmp_r = NULL;
	}
	free(map);
	map = NULL;
}

void	ft_free_and_exit(t_map *map, t_check *check, char *str)
{
	ft_free_map(map);
	map = NULL;
	free(check);
	check = NULL;
	ft_exit(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:39:17 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/08 13:11:05 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

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

void	ft_check_el(t_check *check, char *str)
{
	int	i;
	int	count_del;

	i = 0;
	count_del = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			count_del++;
	}
	if (ft_count_del(str, '\n') != check->start + check->end + check->rooms +
											check->bonds + check->comments + 1)
	{
		free(check);
		check = NULL;
		ft_exit(str);
	}
}

int		ft_check_rep_rooms(t_room *rooms)
{
	t_room	*tmp;
	t_room	*ttmp;

	tmp = rooms;
	while (tmp != NULL)
	{
		ttmp = tmp->next;
		if (ttmp != NULL)
		{
			while (ttmp != NULL)
			{
				if (ft_strcmp(tmp->name, ttmp->name))
					return (1);
				ttmp = ttmp->next;
			}
			ttmp = NULL;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	make_null(t_room *tmp_r, t_bond *tmp_b, t_bond *tmp)
{
	tmp_r = NULL;
	tmp_b = NULL;
	tmp = NULL;
}

int		ft_check_rep_bonds(t_room *rooms)
{
	t_room	*tmp_r;
	t_bond	*tmp_b;
	t_bond	*tmp;

	tmp_r = rooms;
	while (tmp_r != NULL)
	{
		tmp_b = tmp_r->bonds;
		while (tmp_b != NULL)
		{
			tmp = tmp_b->next;
			if (tmp != NULL)
			{
				if (ft_strcmp(tmp->bond->name, tmp_b->bond->name))
				{
					make_null(tmp_r, tmp_b, tmp);
					return (1);
				}
			}
			tmp_b = tmp_b->next;
		}
		tmp_r = tmp_r->next;
	}
	make_null(tmp_r, tmp_b, tmp);
	return (0);
}

int		main(void)
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
	if (ft_check_rep_bonds(map->rooms))
		ft_free_and_exit(map, check, str);
	ft_printf(str);
	ft_free_map(map);
	map = NULL;
	free(check);
	check = NULL;
	free(str);
	return (0);
}

// печать комнат и их содержимого (если понадобится для проверки)
	// printf("ants = %d\n", map->ants);
	// while (map->rooms != NULL)
	// {
	// 	printf("room_name = %s\nse = %d\nx = %d\ny = %d\nbonds: ", map->rooms->name, map->rooms->se, map->rooms->x, map->rooms->y);
	// 	while (map->rooms->bonds != NULL)
	// 	{
	// 		printf("%s ", map->rooms->bonds->bond->name);
	// 		map->rooms->bonds = map->rooms->bonds->next;
	// 	}
	// 	printf("\n");
	// 	map->rooms = map->rooms->next;
	// }
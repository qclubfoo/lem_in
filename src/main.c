/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:39:17 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/09 16:39:22 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

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
	ft_printf("%s\n", str);
	ft_free_map(map);
	map = NULL;
	free(check);
	check = NULL;
	free(str);
	str = NULL;
	return (0);
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
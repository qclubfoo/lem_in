/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:39:17 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/02 17:24:33 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	ft_exit(char *str)
{
	free(str);
	str = NULL;
	write(2, "Error\n", 6);
	exit(0);
}

int 	main(void)
{
	char	*str;
	t_map	*map;
	t_room	*tmp;

	str = ft_read();
	ft_check_map(str) == 1 ? ft_exit(str) : 0;
	map = ft_make_map(str);
	map == NULL ? ft_exit(str) : 0;
	write(1, "OK\n", 3);
	free(str);
	str = NULL;
	while (map->rooms != NULL)
	{
		tmp = map->rooms;
		map->rooms = map->rooms->next;
		free(tmp->name);
		tmp->name = NULL;
		free(tmp);
		tmp = NULL;
	}
	free(map->rooms);
	map->rooms = NULL;
	free(map);
	map = NULL;
	// ft_make_map(&map, str);
	exit(0);
}

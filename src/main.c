/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:39:17 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/03 11:44:15 by qclubfoo         ###   ########.fr       */
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

void	ft_free_map(t_map *map)
{
	t_room	*tmp;
	t_bond	*ttmp;

	while (map->rooms != NULL)
	{
		tmp = map->rooms;
		map->rooms = map->rooms->next;
		free(tmp->name);
		tmp->name = NULL;
					printf("tut\n");
		while (tmp->bonds != NULL)
		{
			ttmp = tmp->bonds;
			tmp->bonds = tmp->bonds->next;
			free(ttmp->bond);
			ttmp->bond = NULL;
		}
		free(tmp->bonds->bond);
		tmp->bonds->bond = NULL;
		free(tmp->bonds);
		tmp->bonds = NULL;
		free(tmp);
		tmp = NULL;
	
	}
	free(map->rooms);
	map->rooms = NULL;
	free(map);
	map = NULL;
}

int 	main(void)
{
	char	*str;
	t_map	*map;
	t_room	*tmp;
	t_bond	*ttmp;

	str = ft_read();
	ft_check_map(str) == 1 ? ft_exit(str) : 0;
	map = ft_make_map(str);
	map == NULL ? ft_exit(str) : 0;
	write(1, "OK\n", 3);
	tmp = map->rooms;
	while (tmp != NULL)
	{
		printf("name = %s\nse = %d\nx = %d\ny = %d\nbonds are: ", tmp->name, tmp->se, tmp->x, tmp->y);
		while (tmp->bonds != NULL)
		{
			printf("%s ", tmp->bonds->bond->name);
			tmp->bonds = tmp->bonds->next;
		}
		printf("\n\n");
		tmp = tmp->next;
	}
	tmp = NULL;

	free(str);
	str = NULL;
	ft_free_map(map);
	exit(0);
}

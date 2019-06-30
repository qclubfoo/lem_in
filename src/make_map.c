/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:28:58 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/29 16:17:44 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_make_ants(t_map *map, char *str)
{
	int	err;

	err = 0;
	if (ft_atoi_err(str, &err) < 0 || err != 0)
		return (1);
	else
		map->ants = ft_atoi_err(str, &err);
	return (0);
}

int		ft_return (char **check)
{
	int	i;

	i = 0;
	while (check[i] != NULL)
	{
		free(check[i]);
		check[i] == NULL;
		i++;
	}
	free(check[i]);
	check[i] == NULL;
	free(check);
	check = NULL;
	return (1);
}

int		check_split(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int		ft_make_rooms(t_map *map, char **split)
{
	int		i;
	char	**split_str;
	int		switcher;
	t_room	*tmp;
	int		sf;

	map->rooms = add_first_room();
	i = 1;
	switcher = 1;
	while (split[i] != NULL && switcher == 1)
	{
		sf = -1;
		if (ft_strcmp(split[i], "##start"))
		{
			sf = 0;
			i++;
		}
		else if (ft_strcmp(split[i], "##finish"))
		{
			sf = 1;
			i++;
		}
		else if (split[i][0] == '#')
		{
			i++;
			continue ;
		}
		tmp = map->rooms;
		if (map->rooms->next != NULL)
			tmp = add_new_room(map->rooms);
		**split_str = ft_strsplit(split[i], ' ');
		if (check_split(split_str) != 3)
			

		
		// else if (ft_strcmp(split[i], "##finish"))
		// {
		// 	if (map->rooms->next == NULL)
		// 	{
		// 		map->rooms->finish = 1;
		// 		i++;
		// 	}
		// 	else
		// 	{
		// 		tmp = add_new_room(map->rooms);
		// 		tmp->finish = 1;
		// 		tmp = NULL;
		// 		i++;
		// 	}
		// }
		// else if (split[i] != NULL && split[i][0] == '#')
		// {
		// 	comment = 0;
		// 	i++;
		// }
		// if ()
		// {
		// 	split_str = ft_strsplit(split[i], ' ');
			
		// }
	}
}

int		ft_make_map(t_map *map, char *str)
{
	char	**split;

	split = ft_strsplit(str, '\n');
	ft_make_ants(map, split[0]);		//проверить возвращаемое значение, если не 0 то освободить память и выйти;
	ft_make_rooms(map, split);
}
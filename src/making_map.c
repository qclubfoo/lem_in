/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:14:33 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/02 13:22:46 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_hash(char **str, int *i, t_check *check)
{
	if (ft_strcmp(str[*i], "##start"))
	{
		check->start += 1;
		*i += 1;
	}
	else if (ft_strcmp(str[*i], "##end"))
	{
		check->end += 1;
		*i += 1;
	}
	else if (str[*i][0] == '#')
	{
		*i += 1;
		return (1);
	}
	return (0);
}

void		ft_make_room(char *str, t_check *check, t_map *map)
{
	char 	**split;
	int		i;
	t_room	*tmp;

	i = 0;
	split = ft_strsplit(str, ' ');
	while (split[i] != NULL)
		i++;
	if (i != 3)
	{
		check->check_type = 2;
		return (ft_return(split, 0));
	}
	if (map->rooms == NULL)
	{
		map->rooms = add_first_room();
		tmp = map->rooms;
	}
	else
		tmp = add_new_room(map->rooms);
	i = 0;
	while (split[0][i])
		i++;
	tmp->name = (char*)malloc(sizeof(char) * i + 1);
	ft_strncpy(tmp->name, split[0], 0);
	tmp->x = ft_atoi(split[1]);
	tmp->y = ft_atoi(split[2]);
	tmp = NULL;
	ft_return(split, 0);
}

void		ft_make_bonds(char *str, t_check *check, t_map *map)
{

}

t_map		ft_make_map(char *input, t_check *check)
{
	char	**str;
	int		i;
	t_map	map;

	i = 0;
	check->check_type = 1;
	check->start = 0;
	check->end = 0;
	str = ft_strsplit(input, '\n');
	map.ants = ft_atoi(str[i++]);
	map.rooms = NULL;
	while(str[i] != NULL)
	{
		if (ft_hash(str, &i, check))
			continue ;
		if (check->check_type == 1)
			ft_make_room(str[i], check, &map);
		if (check->check_type == 2)
			ft_make_bonds(str[i], check, &map);
	}
}

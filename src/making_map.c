/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:03:41 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/31 19:05:48 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_make_map(char *input, t_map *map)
{
	char	**str;
	int		i;
	int		se;
	int		check_type;

	str = ft_init_making_map(input, map, &i, &se);
	check_type = 1;
	while (str[i] != NULL)
	{
		if (ft_make_hash(str, &i, &se))
			continue ;
		if (check_type == 1)
			ft_make_room(str[i], map, &check_type, &se);
		if (check_type == 2)
		{
			if (ft_make_bond(str[i], map))
			{
				ft_return(str);
				return (1);
			}
		}
		i++;
	}
	ft_return(str);
	return (0);
}

char	**ft_init_making_map(char *input, t_map *map, int *i, int *se)
{
	char	**str;

	*i = 1;
	str = ft_strsplit(input, '\n');
	map->ants = ft_atoi(str[0]);
	map->rooms = NULL;
	map->file = NULL;
	*se = 0;
	return (str);
}

int		ft_make_hash(char **str, int *i, int *se)
{
	if (ft_strcmp(str[*i], "##start"))
	{
		*se = 1;
		*i += 1;
		return (1);
	}
	else if (ft_strcmp(str[*i], "##end"))
	{
		*se = 2;
		*i += 1;
		return (1);
	}
	else if (str[*i][0] == '#')
	{
		*i += 1;
		return (1);
	}
	return (0);
}

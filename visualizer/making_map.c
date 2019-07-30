/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 17:54:09 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/30 19:51:22 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/visualizer.h"

t_map	*adding_data(void)
{
	char	*input;
	char	**str;
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	map->rooms = NULL;
	map->bonds = NULL;
	map->steps = NULL;
	input = ft_read();
	str = ft_split_input(input, map);
	ft_make_map(&map->rooms, &map->bonds, &map->steps, str);
	ft_return(str);
	return (map);
}

char	**ft_split_input(char *input, t_map *map)
{
	char	**str;

	str = ft_strsplit(input, '\n');
	map->ants = ft_atoi(str[0]);
	free(input);
	input = NULL;
	int i = 0;
	return (str);
}

void	ft_make_map(t_rooms **rooms, t_bonds **bonds, t_steps **steps, char **str)
{
	int		i;
	int		check_type;

	i = 1;
	check_type = 1;
	while (str[i] != NULL)
	{
		if (ft_make_hash(str, i))
		{
			i++;
			continue ;
		}
		if (check_type == 1)
			ft_make_room(str[i], &check_type, rooms);
		if (check_type == 2){
			ft_make_bond(str[i], &check_type, bonds, *rooms);}
		if (check_type == 3)
		{
			if (*steps == NULL)
				*steps = add_first_steps();
			else
				add_new_steps(*steps);
			ft_make_step(str[i], steps, *rooms);
		}
		i++;
	}
}

int		ft_make_hash(char **str, int i)
{
	if (str[i][0] == '#')
	{
		i += 1;
		return (1);
	}
	return (0);
}

void	ft_return(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str[i]);
	str[i] = NULL;
	free(str);
	str = NULL;
}

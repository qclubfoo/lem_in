/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:14:33 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/03 11:41:56 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_hash(char **str, int *i, int *start, int *end)
{
	if (ft_strcmp(str[*i], "##start"))
	{
		*start += 1;
		*i += 1;
	}
	else if (ft_strcmp(str[*i], "##end"))
	{
		*end += 1;
		*i += 1;
	}
	else if (str[*i][0] == '#')
	{
		*i += 1;
		return (1);
	}
	return (0);
}

void		ft_make_room(char *str, int *check_type, t_map *map, int *start, int *end)
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
		*check_type = 2;
		ft_return(split, 0);
		return ;
	}
	if (map->rooms == NULL)
	{
		map->rooms = add_first_room();
		*start == 1 ? map->rooms->se = 1 : 0;
		*start == 1 ? *start = 0 : 0;
		*end == 1 ? map->rooms->se = 2 : 0;
		*end == 1 ? *end = 0 : 0;
		tmp = map->rooms;
	}
	else
	{
		add_new_room(map->rooms);
		tmp = map->rooms;
		while (tmp->next != NULL)
			tmp = tmp->next;
		*start == 1 ? tmp->se = 1 : 0;
		*start == 1 ? *start = 0 : 0;
		*end == 1 ? tmp->se = 2 : 0;
		*end == 1 ? *end = 0 : 0;
	}
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

void		ft_make_bonds(char *str, int *check_type, t_map *map)
{
	char	**split;
	t_room	*tmp;
	t_room	*src;
	t_room	*dst;
	t_bond	*ttmp;

	src = NULL;
	dst = NULL;
	tmp = map->rooms;
	split = ft_strsplit(str, '-');
	while (src == NULL && dst == NULL)
	{
		if (ft_strcmp(tmp->name, split[0]))
			dst = tmp;
		if (ft_strcmp(tmp->name, split[1]))
			src = tmp;
		if (tmp == NULL)
			break ;
		tmp = tmp->next;
	}
	if (src == NULL || dst == NULL)
	{
		ft_return(split, 1);
		*check_type = -1;
		return ;
	}
	if (dst->bonds == NULL)
	{
		dst->bonds = add_first_bond();
		ttmp = dst->bonds;
	}
	else
	{
		ttmp = dst->bonds;
		while (ttmp->next != NULL)
			ttmp = ttmp->next;
		ttmp->next = add_first_bond();
		ttmp = ttmp->next;
	}
	ttmp->bond = src;
	tmp = NULL;
	src = NULL;
	dst = NULL;
	ttmp = NULL;
}

t_map		*ft_make_map(char *input)
{
	char	**str;
	int		i;
	t_map	*map;
	int		check_type;
	int		start;
	int		end;

	map = (t_map*)malloc(sizeof(t_map));
	i = 0;
	check_type = 1;
	start = 0;
	end = 0;
	str = ft_strsplit(input, '\n');
	map->ants = ft_atoi(str[i++]);
	map->rooms = NULL;
	while(str[i] != NULL)
	{
		if (ft_hash(str, &i, &start, &end))
			continue ;
		if (check_type == 1)
			ft_make_room(str[i], &check_type, map, &start, &end);
		// ft_check_rooms_repeat(map->rooms);
		if (check_type == 2)
			ft_make_bonds(str[i], &check_type, map);
		if (check_type == -1)
		{
			ft_return(str, 0);
			ft_free_map(map);
			return (NULL);
		}
		i++;
	}
	ft_return(str, 0);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:03:41 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/08 16:34:12 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_make_hash(char **str, int *i, int *se)
{
	if (ft_strcmp(str[*i], "##start"))
	{
		*se = 1;
		*i += 1;
	}
	else if (ft_strcmp(str[*i], "##end"))
	{
		*se = 2;
		*i += 1;
	}
	else if (str[*i][0] == '#')
	{
		*i += 1;
		return (1);
	}
	return (0);
}

void	ft_write_room(t_map *map, char **make_room, int *se)
{
	t_room	*tmp;

	tmp = map->rooms;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->name = (char*)malloc(sizeof(char) * (ft_strlen(make_room[0]) + 1));
	ft_strncpy(tmp->name, make_room[0], 0);
	tmp->x = ft_atoi(make_room[1]);
	tmp->y = ft_atoi(make_room[2]);
	tmp->bonds = NULL;
	if (*se)
	{
		tmp->se = *se;
		*se = 0;
	}
	tmp = NULL;
}

void	ft_make_room(char *str, t_map *map, int *check_type, int *se)
{
	char	**make_room;
	int		i;		

	make_room = ft_strsplit(str, ' ');
	i = 0;
	while(make_room[i])
		i++;
	if (i != 3)
		*check_type = 2;
	else
	{
		if (map->rooms == NULL)
			map->rooms = add_first_room();
		else
			add_new_room(map->rooms);
		ft_write_room(map, make_room, se);
	}
	ft_return(make_room);
}

void	ft_make_bond_one(char *str, t_map *map, t_room **dst, t_room **src)
{
	char **split;

	split = ft_strsplit(str, '-');
	*dst = map->rooms;
	*src = map->rooms;
	while (*dst != NULL)
	{
		if (ft_strcmp((*dst)->name, split[0]))
			break ;
		*dst = (*dst)->next;
	}
	while (src != NULL)
	{
		if (ft_strcmp((*src)->name, split[1]))
			break ;
		*src = (*src)->next;
	}
	free(split);
	split = NULL;
}

int		ft_make_bond(char *str, t_map *map)
{
	t_room	*dst;
	t_room	*src;
	t_bond	*tmp;

	dst = NULL;
	src = NULL;
	ft_make_bond_one(str, map, &dst, &src);
	if (dst == NULL || src == NULL || src == dst)
	{
		dst = NULL;
		src = NULL;
		// ft_return(split);
		// printf("return\n");
		return (1);
	}
	if (dst->bonds == NULL)
	{
		// printf("tut\n");
		dst->bonds = (t_bond*)malloc(sizeof(t_bond));
		dst->bonds->next = NULL;
		dst->bonds->bond = src;
		// printf("src = %p\ndst = %p\ndst->bonds->bond = %p\n\n", src, dst, dst->bonds->bond);
	}
	else
	{
		// printf("zdes\n");
		tmp = dst->bonds;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (t_bond*)malloc(sizeof(t_bond));
		tmp = tmp->next;
		tmp->next = NULL;
		tmp->bond = src;
		// printf("src = %p\ndst = %p\ndst->bonds->bond = %p\n\n", src, dst, dst->bonds->bond);
	}
	// printf("split[0] = %s\nsplit[1] = %s\n\n", split[0], split[1]);
	src = NULL;
	dst = NULL;
	tmp = NULL;
	// ft_return(split);
	return (0);
}

int		ft_make_map(char *input, t_map *map)
{
	char	**str;
	int		i;
	int		se;
	int		check_type;

	i = 0;
	str = ft_strsplit(input, '\n');
	map->ants = ft_atoi(str[i++]);
	map->rooms = NULL;
	se = 0;
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

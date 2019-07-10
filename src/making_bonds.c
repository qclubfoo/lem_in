/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_bonds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:09:31 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/10 16:10:40 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_make_bond(char *str, t_map *map)
{
	t_room	*dst;
	t_room	*src;
	t_bond	*tmp;

	dst = NULL;
	src = NULL;
	ft_find_bond(str, map, &dst, &src);
	if (dst == NULL || src == NULL || src == dst)
	{
		dst = NULL;
		src = NULL;
		return (1);
	}
	if (ft_check_repeat(src, dst, 2))
		ft_add_bond(src, dst);
	if (ft_check_repeat(src, dst, 1))
		ft_add_bond(dst, src);
	src = NULL;
	dst = NULL;
	tmp = NULL;
	return (0);
}

void	ft_find_bond(char *str, t_map *map, t_room **dst, t_room **src)
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
	while (*src != NULL)
	{
		if (ft_strcmp((*src)->name, split[1]))
			break ;
		*src = (*src)->next;
	}
	ft_return(split);
	split = NULL;
}

int		ft_check_repeat(t_room *src, t_room *dst, int flag)
{
	t_bond	*tmp_s;
	t_bond	*tmp_d;

	tmp_s = src->bonds;
	tmp_d = dst->bonds;
	while (tmp_s && flag == 1)
	{
		if (ft_strcmp(tmp_s->bond->name, dst->name))
			return (0);
		tmp_s = tmp_s->next;
	}
	while (tmp_d && flag == 2)
	{
		if (ft_strcmp(tmp_d->bond->name, src->name))
			return (0);
		tmp_d = tmp_d->next;
	}
	tmp_s = NULL;
	tmp_d = NULL;
	return (1);
}

void	ft_add_bond(t_room *src, t_room *dst)
{
	t_bond *tmp;

	if (dst->bonds == NULL)
	{
		dst->bonds = (t_bond*)malloc(sizeof(t_bond));
		dst->bonds->next = NULL;
		dst->bonds->bond = src;
	}
	else
	{
		tmp = dst->bonds;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (t_bond*)malloc(sizeof(t_bond));
		tmp = tmp->next;
		tmp->next = NULL;
		tmp->bond = src;
	}
}

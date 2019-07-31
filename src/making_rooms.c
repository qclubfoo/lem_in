/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:06:05 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/31 19:05:54 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_make_room(char *str, t_map *map, int *check_type, int *se)
{
	char	**make_room;
	int		i;

	make_room = ft_strsplit(str, ' ');
	i = 0;
	while (make_room[i])
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

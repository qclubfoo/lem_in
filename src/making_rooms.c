/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:06:05 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/08 19:22:17 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

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

t_room	*add_first_room(void)
{
	t_room	*first_room;

	first_room = (t_room*)malloc(sizeof(t_room));
	first_room->se = 0;
	first_room->bonds = NULL;
	first_room->next = NULL;
	return (first_room);
}

t_room	*add_new_room(t_room *head)
{
	while (head->next != NULL)
		head = head->next;
	head->next = (t_room*)malloc(sizeof(t_room));
	head->next->se = 0;
	head->next->bonds = NULL;
	head->next->next = NULL;
	return (head->next);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:24:57 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/30 18:17:54 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/visualizer.h"

void	ft_make_room(char *str, int *check_type, t_rooms **rooms)
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
		if (*rooms == NULL)
			*rooms = add_first_room();
		else
			add_new_room(*rooms);
		ft_write_room(*rooms, make_room);
	}
	ft_return(make_room);
}

t_rooms	*add_first_room(void)
{
	t_rooms	*first_room;

	if (!(first_room = (t_rooms*)malloc(sizeof(t_rooms))))
		return (NULL);
	first_room->name = NULL;
	first_room->x = -1;
	first_room->y = -1;
	first_room->next = NULL;
	return (first_room);
}

void	add_new_room(t_rooms *rooms)
{
	t_rooms	*tmp;

	tmp = rooms;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_rooms*)malloc(sizeof(t_rooms));
	tmp = tmp->next;
	tmp->name = NULL;
	tmp->x = -1;
	tmp->y = -1;
	tmp->next = NULL;
}

void	ft_write_room(t_rooms *rooms, char **make_room)
{
	t_rooms	*tmp;

	tmp = rooms;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->name = (char*)malloc(sizeof(char) * (ft_strlen(make_room[0]) + 1));
	ft_strncpy(tmp->name, make_room[0], 0);
	tmp->x = ft_atoi(make_room[1]);
	tmp->y = ft_atoi(make_room[2]);
	tmp = NULL;
}

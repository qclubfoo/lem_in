/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_adding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 09:42:16 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/29 10:40:21 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_room		*add_first_room(void)
{
	t_room	*first_room;

	first_room = (t_room**)malloc(sizeof(t_room));
	first_room->start = 0;
	first_room->finish = 0;
	first_room->next = NULL;
	return (first_room);
}

t_room		*add_new_room(t_room *head)
{
	t_room	*next_room;

	while (head->next != NULL)
		head = head->next;
	head->next = add_first_room();
	return (head->next);
}
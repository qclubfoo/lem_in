/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_adding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 09:42:16 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/30 21:08:11 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_room		*add_first_room(void)
{
	t_room	*first_room;

	first_room = (t_room*)malloc(sizeof(t_room));
	first_room->se = 0;
	first_room->bonds = NULL;
	first_room->next = NULL;
	first_room->ant = 0;
	first_room->distance = __INT_MAX__;
	return (first_room);
}

t_room		*add_new_room(t_room *head)
{
	while (head->next != NULL)
		head = head->next;
	head->next = (t_room*)malloc(sizeof(t_room));
	head->next->distance = __INT_MAX__;
	head->next->se = 0;
	head->next->label = 0;
	head->next->ant = 0;
	head->next->bonds = NULL;
	head->next->next = NULL;
	return (head->next);
}

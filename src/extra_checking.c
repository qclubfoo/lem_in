/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:18:35 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/08 19:19:02 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	ft_check_el(t_check *check, char *str)
{
	int	i;
	int	count_del;

	i = 0;
	count_del = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			count_del++;
	}
	if (ft_count_del(str, '\n') != check->start + check->end + check->rooms +
											check->bonds + check->comments + 1)
	{
		free(check);
		check = NULL;
		ft_exit(str);
	}
}

int		ft_check_rep_rooms(t_room *rooms)
{
	t_room	*tmp;
	t_room	*ttmp;

	tmp = rooms;
	while (tmp != NULL)
	{
		ttmp = tmp->next;
		if (ttmp != NULL)
		{
			while (ttmp != NULL)
			{
				if (ft_strcmp(tmp->name, ttmp->name))
					return (1);
				ttmp = ttmp->next;
			}
			ttmp = NULL;
		}
		tmp = tmp->next;
	}
	return (0);
}

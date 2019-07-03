/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 23:13:51 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/03 16:26:19 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	ft_return (char **str)
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

void	ft_init_check(t_check *check)
{
	check->err = 0;
	check->start = 0;
	check->end = 0;
	check->rooms = 0;
	check->bonds = 0;
	check->comments = 0;
	check->check_type = 1;
}

int		ft_count_del(char *str, char del)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i++] == del)
			count++;
	}
	return (count);
}
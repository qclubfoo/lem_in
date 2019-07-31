/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 23:13:51 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/31 19:05:20 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	*exit_checking(t_check *check, char **str)
{
	ft_return(str);
	free(check);
	check = NULL;
	return (NULL);
}

void	ft_return(char **str)
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
	check->flag = 0;
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

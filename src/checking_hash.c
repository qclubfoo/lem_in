/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:37:11 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/31 19:04:55 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_hash(char **str, int *i, t_check *check)
{
	if (ft_strcmp(str[*i], "##start") && check->check_type == 1)
		return (ft_start(str, i, check));
	else if (ft_strcmp(str[*i], "##end") && check->check_type == 1)
		return (ft_end(str, i, check));
	else if (str[*i][0] == '#')
	{
		check->comments += 1;
		*i += 1;
		return (1);
	}
	return (0);
}

int		ft_start(char **str, int *i, t_check *check)
{
	check->start += 1;
	if (check->start > 1)
		check->err = 1;
	if (str[*i + 1] != NULL &&
	(ft_strcmp(str[*i + 1], "##end") || ft_strchr(str[*i + 1], '-')))
		check->err = 1;
	*i += 1;
	check->flag += 1;
	return (1);
}

int		ft_end(char **str, int *i, t_check *check)
{
	check->end += 1;
	if (check->end > 1)
		check->err = 1;
	if (str[*i + 1] != NULL &&
	(ft_strcmp(str[*i + 1], "##start") || ft_strchr(str[*i + 1], '-')))
		check->err = 1;
	*i += 1;
	check->flag += 1;
	return (1);
}

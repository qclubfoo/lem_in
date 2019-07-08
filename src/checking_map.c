/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 08:19:51 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/08 12:56:33 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_check		*ft_check_map(char *input)
{
	char	**str;
	t_check	*check;

	str = ft_strsplit(input, '\n');
	if (str == NULL)
		return (NULL);
	check = (t_check*)malloc(sizeof(t_check));
	ft_init_check(check);
	if (ft_atoi_err(str[0], &check->err) <= 0 || check->err != 0)
		return (exit_checking(check, str));
	ft_checking(check, str);
	if (check->err != 0 || check->rooms == 0 || check->bonds == 0
									|| check->start == 0 || check->end == 0)
		return (exit_checking(check, str));
	ft_return(str);
	return (check);
}

void		ft_checking(t_check *check, char **str)
{
	int	i;

	i = 1;
	while (str[i] != NULL)
	{
		if (ft_check_hash(str, &i, check))
			continue ;
		if (check->check_type == 1)
			check_room(str[i], check);
		if (check->check_type == 2)
			check_bond(str[i], check);
		if (check->err != 0)
			break ;
		i++;
	}
}

int			ft_check_hash(char **str, int *i, t_check *check)
{
	if (ft_strcmp(str[*i], "##start") && check->check_type == 1)
	{
		check->start += 1;
		if (check->start > 1)
			check->err = 1;
		if (str[*i + 1] != NULL && ft_strcmp(str[*i + 1], "##end"))
			check->err = 1;
		*i += 1;
	}
	else if (ft_strcmp(str[*i], "##end") && check->check_type == 1)
	{
		check->end += 1;
		if (check->end > 1)
			check->err = 1;
		if (str[*i + 1] != NULL && ft_strcmp(str[*i + 1], "##start"))
			check->err = 1;
		*i += 1;
	}
	else if (str[*i][0] == '#')
	{
		check->comments += 1;
		*i += 1;
		return (1);
	}
	return (0);
}

void		check_room(char *str, t_check *check)
{
	char	**check_room;
	int		i;

	i = 0;
	check_room = ft_strsplit(str, ' ');
	while (check_room[i] != NULL)
		i++;
	i > 1 && (check_room[0][0] == 'L' || ft_strchr(check_room[0], '-')
			|| ft_strchr(check_room[0], ' ')) ? check->err = 1 : 0;
	i == 3 && check->err != 1 ? ft_atoi_err(check_room[1], &check->err) : 0;
	i == 3 && check->err != 1 ? ft_atoi_err(check_room[2], &check->err) : 0;
	i == 3 && ft_count_del(str, ' ') != 2 ? check->err = 1 : 0;
	if (i != 3 || check->err != 0)
		check->check_type = 2;
	else
		check->rooms += 1;
	ft_return(check_room);
}

void		check_bond(char *str, t_check *check)
{
	char	**check_bond;
	int		i;

	i = 0;
	check_bond = ft_strsplit(str, '-');
	while (check_bond[i] != NULL)
		i++;
	if (i != 2 || ft_count_del(str, '-') != 1)
		check->err = 1;
	else
		check->bonds += 1;
	ft_return(check_bond);
}

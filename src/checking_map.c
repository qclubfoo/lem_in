/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 08:19:51 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/30 08:31:20 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_check		*ft_check_map(char *input)
{
	char	**str;
	int		i;
	t_check	check;

	ft_init_check(&check);
	i = 0;
	str = ft_strsplit(input, '\n');
	if (ft_atoi_err(str[i++], &check.err) < 0 || check.err != 0)
		return (ft_return(str, 1));
	while (str[i] != NULL)
	{
		if (ft_check_hash(str, &i, &check))
			continue ;
		if (check.check_type == 1 && check.err == 0)
			check_room(str[i], &check.check_type, &check.rooms, &check.err);
		if (check.check_type == 2 && check.err == 0)
			check_bond(str[i], &check.bonds, &check.err);
		if (check.err != 0)
			break ;
		i++;
	}
	if (check.err != 0 || check.rooms == 0 || check.bonds == 0)
		return (ft_return(str, 1));
	ft_return (str, 0);
	return (&check);
}

int		ft_check_hash(char **str, int *i, t_check *check)
{
	if (ft_strcmp(str[*i], "##start"))
	{
		check->start += 1;
		if (check->start > 1)
			check->err = 1;
		*i += 1;
	}
	else if (ft_strcmp(str[*i], "##end"))
	{
		check->end += 1;
		if (check->end > 1)
			check->err = 1;
		*i += 1;
	}
	else if (str[*i][0] == '#')
	{
		*i += 1;
		return (1);
	}
	return (0);
}

void	check_room(char *str, int *check_type, int *rooms, int *err)
{
	char **check;
	int	i;

	i = 0;
	check = ft_strsplit(str, ' ');
	while (check[i] != NULL)
		i++;
	i > 0 && check[0][0] == 'L' ? *err = 1 : 0;
	i == 3 ? ft_atoi_err(check[1], err) : 0;
	i == 3 ? ft_atoi_err(check[2], err) : 0;
	if (i != 3 || *err != 0)
		*check_type = 2;
	else
		*rooms += 1;
	ft_return(check, *err);
}

void	check_bond(char *str, int *bonds, int *err)
{
	char **check;
	int	i;

	i = 0;
	check = ft_strsplit(str, '-');
	while (check[i] != NULL)
		i++;
	if (i != 2)
		*err = 1;
	else
		*bonds += 1;
	ft_return(check, *err);
}

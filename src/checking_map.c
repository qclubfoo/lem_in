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

int		ft_return (char **str, int err)
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
	if (err != 0)
		return (1);
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

int		ft_check_map(char *input)
{
	char	**str;
	int		err;
	int		i;
	int		start;
	int		end;
	int		rooms;
	int		bonds;
	int		check_type;

	err = 0;
	i = 0;
	start = 0;
	end = 0;
	rooms = 0;
	bonds = 0;
	check_type = 1;
	str = ft_strsplit(input, '\n');
	if (ft_atoi_err(str[i++], &err) < 0 || err != 0)
		return (ft_return(str, 1));
	while (str[i] != NULL)
	{
		if (ft_strcmp(str[i], "##start"))
		{
			start += 1;
			if (start > 1)
				return (ft_return(str, 1));
			i++;
		}
		else if (ft_strcmp(str[i], "##end"))
		{
			end += 1;
			if (end > 1)
				return (ft_return(str, 1));
			i++;
		}
		else if (str[i][0] == '#')
		{
			i++;
			continue ;
		}
		if (check_type == 1)
			check_room(str[i], &check_type, &rooms, &err);
		if (check_type == 2 && err == 0)
			check_bond(str[i], &bonds, &err);
		if (err != 0)
			break ;
		i++;
	}
	printf("err = %d\nrooms = %d\nbonds = %d\n", err, rooms, bonds);
	if (err != 0 || rooms == 0 || bonds == 0)
		return (ft_return(str, 1));
	return (ft_return(str, 0));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 17:54:09 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/28 18:35:30 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/visualizer.h"

int	function(void)
{
	int		ants;
	char	*input;
	char	**str;
	t_rooms	*rooms;
	t_bonds *bonds;
	t_steps *steps;

	input = read();
	i = 0;
	ft_split_input(input, str, &ants);
	ft_make_map(rooms, bonds, steps, str);

	return (ants);
}

void	ft_split_input(char *input, char **str, int *ants)
{
	*ants = ft_atoi(str[0]);
	str = ft_strsplit(input, '\n');
	free(input);
	input = NULL;
}

void	ft_make_map(t_rooms *rooms, t_bonds *bonds, t_steps *steps, char **str)
{
	int		i;
	int		check_type;

	i = 1;
	check_type = 1;
	while (str[i] != NULL)
	{
		if (ft_make_hash(str, &i))
			continue ;
		if (check_type == 1)
			ft_make_room(str[i], &check_type);
		if (check_type == 2)
		{
			if (ft_make_bond(str[i], map))
			{
				ft_return(str);
				return (1);
			}
		}
		i++;
	}

}
int		ft_make_hash(char **str, int *i, int *se)
{
	if (ft_strcmp(str[*i], "##start"))
	{
		*se = 1;
		*i += 1;
		return (1);
	}
	else if (ft_strcmp(str[*i], "##end"))
	{
		*se = 2;
		*i += 1;
		return (1);
	}
	else if (str[*i][0] == '#')
	{
		*i += 1;
		return (1);
	}
	return (0);
}
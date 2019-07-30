/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_bonds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:54:22 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/30 15:39:50 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/visualizer.h"

void	ft_make_bond(char *str, int *check_type, t_bonds *bonds, t_rooms *rooms)
{
	char	**make_bonds;
	int		i;

	make_bonds = ft_strsplit(str, '-');
	i = 0;
	while (make_bonds[i])
		i++;
	if (i != 2 || (i > 0 && make_bonds[0][0] == 'L'))
		*check_type = 3;
	else
	{
		if (bonds == NULL)
			bonds = add_first_bond();
		else
			add_new_bond(bonds);
		write_new_bond(bonds, rooms, make_bonds);
	}
	ft_return(make_bonds);
}

t_bonds	*add_first_bond(void)
{
	t_bonds	*new;

	if (!(new = (t_bonds*)malloc(sizeof(t_bonds))))
		return (NULL);
	new->x_1 = -1;
	new->y_1 = -1;
	new->x_2 = -1;
	new->y_2 = -1;
	new->next = NULL;
	return (new);
}

void	add_new_bond(t_bonds *bonds)
{
	t_bonds		*tmp;

	tmp = bonds;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (!(tmp->next = (t_bonds*)malloc(sizeof(t_bonds))))
		return (NULL);
	tmp->next->x_1 = -1;
	tmp->next->y_1 = -1;
	tmp->next->x_2 = -1;
	tmp->next->y_2 = -1;
	tmp->next->next = NULL;
}

void	write_new_bond(t_bonds *bonds, t_rooms *rooms, char **str)
{
	int		flag;
	t_rooms	*tmp;

	flag = 0;
	tmp = rooms;
	while (rooms != NULL && flag != 2)
	{
		if (ft_strcmp(tmp->name, str[0]))
		{
			bonds->x_1 = tmp->x;
			bonds->y_1 = tmp->y;
			flag++;
		}
		else if (ft_strcmp(tmp->name, str[1]))
		{
			bonds->x_2 = tmp->x;
			bonds->y_2 = tmp->y;
			flag++;
		}
		rooms = tmp->next;
	}
}

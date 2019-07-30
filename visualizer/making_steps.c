/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_steps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:01:08 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/30 21:37:29 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/visualizer.h"

void	ft_make_step(char *str, t_steps **steps, t_rooms *rooms)
{
	char	**make_step;
	t_steps	*tmp;
	t_step	*tmp_ss;
	int		i;

	i = 0;
	make_step = ft_strsplit(str, ' ');
	ft_remove_l(make_step);
	tmp = *steps;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (make_step[i])
	{
		if (tmp->step == NULL)
			tmp->step = add_first_separate_step();
		else
			add_new_separate_step(&(tmp->step));
		ft_find_step(&tmp->step, rooms, make_step[i]);
		i++;
	}
	ft_return(make_step);
}

void	ft_remove_l(char **make_step)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (make_step[i])
	{
		tmp = (char*)malloc(sizeof(char) * ft_strlen(make_step[i]));
		j = 0;
		while (make_step[i][j + 1])
		{
			tmp[j] = make_step[i][j + 1];
			j++;
		}
		tmp[j] = '\0';
		free(make_step[i]);
		make_step[i] = tmp;
		tmp = NULL;
		i++;
	}
}

void	ft_find_step(t_step **step, t_rooms *rooms, char *str)
{
	char	**split;
	t_rooms	*tmp;
	t_step	*tmp_s;

	split = ft_strsplit(str, '-');
	tmp_s = *step;
	while (tmp_s->next != NULL)
		tmp_s = tmp_s->next;
	tmp_s->ant_num = ft_atoi(split[0]);
	tmp = rooms;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, split[1]))
		{
			tmp_s->x = tmp->x;
			tmp_s->y = tmp->y;
			break ;
		}
		tmp = tmp->next;
	}
	ft_return(split);
}

t_steps	*add_first_steps(void)
{
	t_steps		*new;

	new = (t_steps*)malloc(sizeof(t_steps));
	new->next = NULL;
	new->step = NULL;
	return (new);
}

void	add_new_steps(t_steps *steps)
{
	t_steps		*tmp;

	tmp = steps;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_steps*)malloc(sizeof(t_steps));
	tmp->next->step = NULL;
	tmp->next->next = NULL;
}

t_step	*add_first_separate_step(void)
{
	t_step	*new;
	new = (t_step*)malloc(sizeof(t_step));
	new->ant_num = -1;
	new->x = -1;
	new->y = -1;
	new->next = NULL;
	return (new);
}

void	add_new_separate_step(t_step **step)
{
	t_step	*tmp;

	tmp = *step;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_step*)malloc(sizeof(t_step));
	tmp = tmp->next;
	tmp->ant_num = -1;
	tmp->next = NULL;
	tmp->x = -1;
	tmp->y = -1;
}

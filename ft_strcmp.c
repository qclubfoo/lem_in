/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:12:20 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/28 16:06:04 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/lem_in.h"

int	ft_strcmp(char *str, char *find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (find[i] != '\0')
	{
		while (str[j] != find[i] && str[j] != '\0' && find[i] != '\0')
			j++;
		if (str[j] == '\0' && find[i] != '\0')
			return (0);
		i++;
	}
	if (find[i] == '\0' && str[i] == '\0')
		return (1);
	else
		return (0);
}

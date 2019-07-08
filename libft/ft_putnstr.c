/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:15:35 by sbrella           #+#    #+#             */
/*   Updated: 2019/03/25 17:04:05 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnstr(char *str, size_t lim)
{
	size_t		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] && i < lim)
		i++;
	if (i > 0)
		write(1, str, i);
	return (i);
}

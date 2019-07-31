/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:32:41 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/10 18:45:09 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long int	res;
	int					sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\f' || *str == '\r' || *str == '\v')
		str++;
	*str == '-' ? sign = -1 : 0;
	*str == '+' || *str == '-' ? str++ : 0;
	while ('0' <= *str && *str <= '9')
	{
		if ((res > MAX_I) || ((res == MAX_I && (*str - '0') > 7) && sign == 1)
		|| (res > MAX_I) || ((res == MAX_I && (*str - '0') > 8) && sign == -1))
			return (-1);
		res = 10 * res + (int)(*str - '0');
		str++;
	}
	return ((int)(sign * res));
}

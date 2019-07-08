/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:32:41 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/08 16:43:13 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/lem_in.h"

int		ft_atoi_err(char *str, int *err)
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
		{
			*err = 1;
			return (-1);
		}
		res = 10 * res + (int)(*str - '0');
		str++;
	}
	if ((*str > 32 && *str < 48) || (*str > 57 && *str < 127))
		*err = 1;
	return ((int)(sign * res));
}

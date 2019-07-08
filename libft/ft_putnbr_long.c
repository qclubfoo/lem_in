/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 19:21:46 by sbrella           #+#    #+#             */
/*   Updated: 2019/04/28 21:46:27 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long long int	long_abs(long long int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

#include "libft.h"

static char				def_sym(char sign, char a)
{
	if (a < 10)
		return ('0');
	else
		return (sign == 'X' ? 'A' - 10 : 'a' - 10);
}

static void				ft_recput(long long int n, char sign, int pow)
{
	unsigned long long int a;

	if (sign == 'd' || sign == 'i' || sign == 'D')
	{
		if ((n > -pow) && (n < pow))
			ft_putchar((char)(long_abs(n)) + '0');
		else
		{
			ft_recput(n / pow, sign, pow);
			ft_recput(n % pow, sign, pow);
		}
	}
	else
	{
		a = (unsigned long long)(n);
		if (a < (unsigned long long int)pow)
			ft_putchar((char)(a) + def_sym(sign, (char)(a)));
		else
		{
			ft_recput(a / pow, sign, pow);
			ft_recput(a % pow, sign, pow);
		}
	}
}

void					ft_putnbr_long(long long int n, char sign)
{
	int	pow;

	if (sign == 'd' || sign == 'i' || sign == 'u' || sign == 'D' || sign == 'U')
		pow = 10;
	else if (sign == 'o' || sign == 'O')
		pow = 8;
	else
		pow = 16;
	ft_recput(n, sign, pow);
}

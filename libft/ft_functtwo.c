/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functtwo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:22:42 by sbrella           #+#    #+#             */
/*   Updated: 2019/03/25 17:15:53 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			cut_int(long double *a)
{
	long double	i;

	while (*a >= 10.0)
	{
		i = 1.0;
		while (i * 10.0 < *a)
			i *= 10.0;
		*a -= (char)(*a / i) * i;
	}
}

unsigned int	ft_rec_put_int(long double a)
{
	unsigned int	i;

	i = 0;
	if ((a < 10.0))
	{
		ft_putchar((char)(a) + '0');
		return (1);
	}
	else
	{
		i += ft_rec_put_int(a / 10.0);
		cut_int(&a);
		ft_putchar((char)(a) + '0');
		i += 1;
	}
	return (i);
}

unsigned int	ft_put_int(long double a)
{
	if (a < 0)
		a = -a;
	return (ft_rec_put_int(a));
}

int				ft_putpoint(int precision, int point, long double a)
{
	int		pr;

	pr = precision;
	a = a > 0 ? a : -a;
	if (!(point > 0 && precision == 0))
	{
		ft_putchar('.');
		pr += 1;
		cut_int(&a);
		a = a - (long double)((char)a);
		while (precision > 0)
		{
			a *= 10;
			cut_int(&a);
			ft_putchar((char)(a) + '0');
			precision--;
		}
		return (pr);
	}
	return (0);
}

void			ft_round(int precision, int point, long double *a)
{
	long double i;

	i = 1.0;
	if (*a == 0.0)
		return ;
	if (precision == 0 && point > 0)
		precision = 6;
	while (precision-- + 1 >= 0)
		i = i / 10;
	i = i * (*a > 0 ? 5 : -5);
	*a += i;
}

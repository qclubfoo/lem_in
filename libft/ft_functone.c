/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:22:32 by sbrella           #+#    #+#             */
/*   Updated: 2019/04/28 21:29:04 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_rec_count_int(long double a)
{
	unsigned int	i;

	i = 0;
	if ((a < 10.0))
	{
		return (1);
	}
	else
	{
		i += ft_rec_count_int(a / 10.0);
		cut_int(&a);
		i += 1;
	}
	return (i);
}

unsigned int	ft_count_int(long double a)
{
	if (a < 0)
		a = -a;
	return (ft_rec_count_int(a));
}

int				ft_count_round(int precision, int point, long double a)
{
	int		pr;

	pr = precision;
	a = a > 0 ? a : -a;
	if (!(point > 0 && precision == 0))
	{
		pr += 1;
		cut_int(&a);
		a = a - (long double)((char)a);
		while (precision > 0)
		{
			a *= 10;
			cut_int(&a);
			precision--;
		}
		return (pr);
	}
	return (0);
}

void			manage_end(size_t *total, t_specs *sp, long double *a)
{
	int i;

	if (sp->zero > 0 && sp->atoi > 0 && sp->minus == 0)
	{
		i = sp->atoi - ft_count_round(sp->precision, sp->point, *a)
		- ft_count_int(*a) - 1;
		*total += i > 0 ? i : 0;
		if (i > 0)
			put_symb((size_t)i, '0');
	}
	i = ft_put_int(*a);
	i += ft_putpoint(sp->precision, sp->point, *a);
	*total += i;
	if (sp->minus > 0 && sp->atoi > 0)
	{
		i = sp->atoi - ft_count_round(sp->precision, sp->point, *a)
		- ft_count_int(*a) - 1;
		*total += i > 0 ? i : 0;
		if (i > 0)
			put_symb((size_t)i, ' ');
	}
}

int				manage_f(size_t *total, va_list ap, t_specs *sp)
{
	long double		a;
	unsigned int	i;

	if (sp->bigl == 1)
		a = va_arg(ap, long double);
	else
		a = (long double)va_arg(ap, double);
	if (sp->point == 0)
		sp->precision = 6;
	ft_round(sp->precision, sp->point, &a);
	if (sp->minus == 0 && sp->atoi > 0 && sp->zero == 0)
	{
		i = sp->atoi - ft_count_round(sp->precision, sp->point, a)
		- ft_count_int(a) - (a < 0 ? 1 : 0);
		*total += i > 0 ? i : 0;
		if (i > 0)
			put_symb((size_t)i, ' ');
	}
	if (a < 0 && a >= -1.796E308)
	{
		ft_putchar('-');
		*total += 1;
	}
	manage_end(total, sp, &a);
	return (0);
}

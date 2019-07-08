/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functfour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:22:56 by sbrella           #+#    #+#             */
/*   Updated: 2019/04/16 18:00:53 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	convert_d(va_list ap, t_specs *sp, char sign)
{
	long long int	a;

	if (sp->lnglng == 1)
		a = va_arg(ap, long long int);
	else if (sp->lng == 1 || sign == 'D' || sign == 'O' || sign == 'U')
		a = (((sign == 'd' || sign == 'i' || sign == 'D')) ?
		(long long int)va_arg(ap, long int) :
		(long long int)va_arg(ap, unsigned long int));
	else if (sp->shrt == 1)
		a = (((sign == 'd' || sign == 'i' || sign == 'D')) ?
		(long long int)((short int)va_arg(ap, long int)) :
		(long long int)((unsigned short int)va_arg(ap, unsigned long int)));
	else if (sp->shrtshrt == 1)
		a = (((sign == 'd' || sign == 'i' || sign == 'D')) ?
		(long long int)((char)va_arg(ap, long int)) :
		(long long int)((unsigned char)va_arg(ap, unsigned long int)));
	else
		a = (((sign == 'd' || sign == 'i')) ?
		(long long int)va_arg(ap, int)
		: (long long int)va_arg(ap, unsigned int));
	return (a);
}

int				char_conv(size_t *total, t_specs *sp, unsigned int ch)
{
	int i;

	if (sp->atoi > 1 && sp->minus == 0)
	{
		i = sp->atoi - 1;
		*total += i;
		if (i > 0)
			put_symb((size_t)i, (sp->zero > 0 ? '0' : ' '));
	}
	ft_putchar((char)ch);
	if (sp->minus > 0 && sp->atoi > 1)
	{
		i = sp->atoi - 1;
		*total += i;
		if (i > 0)
			put_symb((size_t)i, (sp->zero > 0 ? '0' : ' '));
	}
	*total += 1;
	return (0);
}

void			manage_ptr_beg(size_t *total, t_specs *sp, int i)
{
	int a;

	if (i + 2 < sp->atoi && sp->minus == 0)
	{
		a = sp->atoi - i - 2;
		*total += a;
		if (a > 0)
			put_symb((size_t)a, ' ');
	}
	ft_putstr("0x");
	*total += 2;
	if (sp->point > 0 && sp->precision > 0)
	{
		a = sp->precision - i;
		*total += a > 0 ? a : 0;
		if (a > 0)
			put_symb((size_t)a, '0');
	}
}

int				pointer_conv(void *ptr, size_t *total, t_specs *sp)
{
	int				i;
	long long int	p;
	int				a;

	p = (long long int)ptr;
	i = ft_countsim_long(p, 'p') - 1;
	manage_ptr_beg(total, sp, i);
	if (!(sp->point > 0 && sp->precision == 0))
	{
		ft_putnbr_long(p, 'p');
		*total += i;
	}
	if (i + 2 < sp->atoi && sp->minus > 0)
	{
		a = sp->atoi - i - 2;
		*total += a;
		if (a > 0)
			put_symb((size_t)a, ' ');
	}
	return (0);
}

void			man_form(t_specs *sp, const char **format, size_t *skip)
{
	if (**format)
	{
		sp->atoi = ft_atoi(*format);
		while (**format >= '0' && **format <= '9')
		{
			(*skip)++;
			(*format)++;
		}
		if (**format == '.')
		{
			(*format)++;
			(*skip)++;
			sp->point = 1;
			sp->precision = ft_atoi(*format);
			while (**format >= '0' && **format <= '9')
			{
				(*skip)++;
				(*format)++;
			}
		}
	}
}

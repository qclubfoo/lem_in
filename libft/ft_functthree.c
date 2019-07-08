/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functthree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:22:37 by sbrella           #+#    #+#             */
/*   Updated: 2019/04/16 18:03:00 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			manage_endf(t_specs *sp, size_t *total,
char sign, long long int a)
{
	int	i;

	if (sp->atoi > 0 && sp->minus == 1)
	{
		i = sp->atoi;
		manage_fli(sign, sp, &i, a);
		i -= ft_countsim_long(a, sign) - 1;
		if (i > 0)
		{
			*total += i;
			if (i > 0)
				put_symb((size_t)i, ' ');
		}
	}
}

void			manage_start(t_specs *sp, size_t *total,
char sign, long long int a)
{
	if (sp->space > 0 && sp->plus == 0 &&
	(sign == 'd' || sign == 'D' || sign == 'i') && a >= 0)
	{
		ft_putchar(' ');
		*total += 1;
	}
	if (sp->plus && a >= 0 &&
	(sign == 'd' || sign == 'i' || sign == 'D') && (sp->zero > 0 &&
		!(sp->point > 0 && sp->precision > 0)))
	{
		*total += 1;
		ft_putchar('+');
	}
	if (sp->hash > 0 && (sign == 'x' || sign == 'X') && a != 0 && (sp->zero > 0
	&& !(sp->point > 0 && sp->precision > 0)))
	{
		*total += 2;
		if (sign == 'x' || sign == 'X')
			ft_putstr(sign == 'x' ? "0x" : "0X");
	}
	if ((sign == 'd' || sign == 'i' || sign == 'D') && a < 0 && (sp->zero > 0 &&
		!(sp->point > 0 && sp->precision > 0)))
		ft_putchar('-');
}

void			manage_before(t_specs *sp, size_t *total,
char sign, long long int a)
{
	int	i;

	if (!(sp->atoi > 0 && sp->minus == 0))
		return ;
	i = sp->atoi;
	manage_fli(sign, sp, &i, a);
	i -= ft_countsim_long(a, sign) - 1;
	if (i <= 0)
		return ;
	*total += i;
	while (i-- > 0)
		ft_putchar((sp->zero > 0 &&
		!(sp->point > 0 && sp->precision > 0)) ? '0' : ' ');
}

void			manage_middle(t_specs *sp, size_t *total,
char sign, long long int a)
{
	if (sp->plus && a >= 0 &&
	(sign == 'd' || sign == 'i' || sign == 'D') && !(sp->zero > 0 &&
		!(sp->point > 0 && sp->precision > 0)))
	{
		*total += 1;
		ft_putchar('+');
	}
	if ((sign == 'd' || sign == 'i' || sign == 'D') && a < 0 && !(sp->zero > 0
	&& !(sp->point > 0 && sp->precision > 0)))
		ft_putchar('-');
	if (sp->hash > 0 && (sign == 'x' || sign == 'X') && a != 0 && !(sp->zero > 0
	&& !(sp->point > 0 && sp->precision > 0)))
	{
		*total += 2;
		if (sign == 'x' || sign == 'X')
			ft_putstr(sign == 'x' ? "0x" : "0X");
	}
	if (sp->hash > 0 && (sign == 'o' || sign == 'O') &&
	(!(a == 0) || (sp->point > 0 && sp->precision == 0)))
	{
		*total += 1;
		ft_putchar('0');
	}
}

int				manage_d(t_specs *sp, size_t *total, va_list ap, char sign)
{
	long long int	a;

	a = convert_d(ap, sp, sign);
	manage_start(sp, total, sign, a);
	manage_before(sp, total, sign, a);
	manage_middle(sp, total, sign, a);
	manage_dpoint(sp, total, sign, a);
	if ((a == 0 && (sp->point > 0 && sp->precision == 0) &&
	(sign == 'D' || sign == 'd' || sign == 'i')))
	{
		ft_putchar(' ');
		*total += 1;
	}
	if (!(a == 0 && ((sp->point > 0 && sp->precision == 0))))
	{
		ft_putnbr_long(a, sign);
		*total += ft_countsim_long(a, sign) - 1;
	}
	manage_endf(sp, total, sign, a);
	return (0);
}

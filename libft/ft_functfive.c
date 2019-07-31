/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functfive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:23:06 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/27 18:03:41 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			manage_fli(char sign, t_specs *sp, int *i, long long int a)
{
	int j;

	if (sp->plus && (sign == 'd' || sign == 'i' || sign == 'D') && a >= 0)
		*i = *i - 1;
	if (sp->space > 0 &&
	(sign == 'd' || sign == 'i' || sign == 'D') && a >= 0)
		*i = *i - 1;
	if (sp->hash > 0 && (sign == 'x' || sign == 'X') && a != 0)
		*i -= 2;
	if (sp->hash > 0 && (sign == 'o' || sign == 'O') && a != 0)
		*i = *i - 1;
	j = sp->precision - ft_countsim_long(a, sign) + 1 +
	(a < 0 && (sign == 'd' || sign == 'i' || sign == 'D') ? 1 : 0) -
	(a > 0 && (sign == 'o' || sign == 'O') && sp->hash > 0 ? 1 : 0);
	if (sp->point > 0 && j > 0)
		*i -= sp->precision - ft_countsim_long(a, sign) + 1 +
		(a < 0 && (sign == 'd' || sign == 'i' || sign == 'D') ? 1 : 0) -
		(a > 0 && (sign == 'o' || sign == 'O') && sp->hash > 0 ? 1 : 0);
}

void			manage_dpoint(t_specs *sp, size_t *total, char sign,
long long int a)
{
	int i;

	if (sp->point > 0)
	{
		i = sp->precision - ft_countsim_long(a, sign) + 1;
		if (sp->hash > 0 && (sign == 'o' || sign == 'O') && !(sp->zero > 0 &&
		!(sp->point > 0 && sp->precision > 0)) && a != 0)
			i--;
		if (a < 0 && (sign == 'D' || sign == 'd' || sign == 'i'))
			i++;
		*total += i > 0 ? i : 0;
		if (i > 0)
			put_symb((size_t)i, '0');
	}
}

int				manage_ptr_null(size_t *total, t_specs *sp)
{
	int i;

	if (sp->minus == 0)
	{
		i = sp->atoi - ((sp->point > 0 && sp->precision > 0 &&
		sp->precision < 6) ? sp->precision : 6);
		*total += (i > 0) ? i : 0;
		if (i > 0)
			put_symb((size_t)i, (sp->zero == 0 ? ' ' : '0'));
	}
	ft_putnstr("(null)", (sp->point > 0 && sp->precision > 0 &&
	sp->precision < 6) ? sp->precision : 6);
	*total += (sp->point > 0 && sp->precision > 0 &&
	sp->precision < 6) ? sp->precision : 6;
	if (sp->minus > 0)
	{
		i = sp->atoi - ((sp->point > 0 && sp->precision > 0 &&
		sp->precision < 6) ? sp->precision : 6);
		*total += (i > 0) ? i : 0;
		if (i > 0)
			put_symb((size_t)i, (sp->zero == 0 ? ' ' : '0'));
	}
	return (0);
}

int				string_conv(size_t *total, t_specs *sp, char *ptr)
{
	int i;

	if (ptr == NULL)
		return (manage_ptr_null(total, sp));
	if (sp->atoi > 0)
	{
		i = sp->atoi - (((sp->zero > 0 && ptr == NULL) || ((size_t)sp->precision
		< ft_strlen(ptr) && sp->point > 0)) ?
		(size_t)sp->precision : ft_strlen(ptr));
		*total += i > 0 ? i : 0;
		if (sp->minus == 0)
			if (i > 0)
				put_symb((size_t)i, (sp->zero == 0 ? ' ' : '0'));
		if (ptr != NULL)
			*total += ft_putnstr(ptr, (sp->point > 0) ?
			(size_t)sp->precision : ft_strlen(ptr));
		if (sp->minus == 1)
			if (i > 0)
				put_symb((size_t)i, (sp->zero == 0 ? ' ' : '0'));
		return (0);
	}
	*total += ft_putnstr(ptr, (sp->point > 0) ?
	(size_t)sp->precision : ft_strlen(ptr));
	return (0);
}

int				man_len(t_specs *sp, const char *format)
{
	if (*format == 'l')
	{
		sp->lng = 1;
		if (*(format + 1) == 'l')
		{
			sp->lnglng = 1;
			return (2);
		}
	}
	if (*format == 'h')
	{
		if (*(format + 1) == 'h')
		{
			sp->shrtshrt = 1;
			return (2);
		}
		else
			sp->shrt = 1;
	}
	if (*format == 'L')
	{
		sp->bigl = 1;
		return (2);
	}
	return (1);
}

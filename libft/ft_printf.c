/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:52:15 by sbrella           #+#    #+#             */
/*   Updated: 2019/04/16 18:05:49 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			init_sp(t_specs *sp)
{
	sp->str = NULL;
	sp->ptr = NULL;
	sp->i = 0;
	sp->precision = 0;
	sp->shrt = 0;
	sp->shrtshrt = 0;
	sp->bigl = 0;
	sp->hash = 0;
	sp->space = 0;
	sp->minus = 0;
	sp->lng = 0;
	sp->atoi = 0;
	sp->point = 0;
	sp->plus = 0;
	sp->lng = 0;
	sp->zero = 0;
	sp->lnglng = 0;
}

int				fill_struc(t_specs *sp, const char *format)
{
	size_t		skip;

	init_sp(sp);
	skip = 0;
	while (*(++format) && (*format == '#' || *format == ' '
	|| *format == '0' || *format == '-' || *format == '+'))
	{
		sp->hash |= *format == '#' ? 1 : 0;
		sp->space |= *format == ' ' ? 1 : 0;
		sp->minus |= *format == '-' ? 1 : 0;
		sp->zero |= *format == '0' ? 1 : 0;
		sp->plus |= *format == '+' ? 1 : 0;
		skip++;
	}
	man_form(sp, &format, &skip);
	if (*format == 'l' || *format == 'h' || *format == 'j'
	|| *format == 't' || *format == 'z' || *format == 'L')
		return (skip + man_len(sp, format));
	return (skip);
}

int				percent_conv(size_t *total, t_specs *sp)
{
	if (sp->atoi > 0 && sp->minus == 0)
	{
		sp->atoi--;
		*total += sp->atoi;
		if (sp->atoi > 0)
			put_symb((size_t)sp->atoi, (sp->zero == 0 ? ' ' : '0'));
	}
	ft_putchar('%');
	if (sp->atoi > 0 && sp->minus == 1)
	{
		sp->atoi--;
		*total += sp->atoi;
		if (sp->atoi > 0)
			put_symb((size_t)sp->atoi, ' ');
	}
	*total += 1;
	return (0);
}

int				manage_flag(const char *format, va_list ap, size_t *total)
{
	t_specs		sp;
	size_t		skip;

	skip = fill_struc(&sp, format);
	if (*(format + skip + 1) == 'p')
		return (2 + skip + pointer_conv(va_arg(ap, void *), total, &sp));
	if (*(format + skip + 1) == '%')
		return (2 + skip) + percent_conv(total, &sp);
	if (*(format + skip + 1) == 'd' || *(format + skip + 1) == 'i' ||
		*(format + skip + 1) == 'o' || *(format + skip + 1) == 'u' ||
		*(format + skip + 1) == 'x' || *(format + skip + 1) == 'X' ||
		*(format + skip + 1) == 'D' || *(format + skip + 1) == 'O' ||
		*(format + skip + 1) == 'U')
		return (2 + skip + manage_d(&sp, total, ap, *(format + skip + 1)));
	if (*(format + skip + 1) == 's')
		return (2 + skip + string_conv(total, &sp, va_arg(ap, char *)));
	if (*(format + skip + 1) == 'c')
		return (2 + skip + char_conv(total, &sp, va_arg(ap, unsigned int)));
	if (*(format + skip + 1) == 'f')
		return (2 + skip + manage_f(total, ap, &sp));
	return (1 + skip);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	size_t	total;

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	total = 0;
	while (*format)
	{
		i = 0;
		while (format[i] && format[i] != '%')
			i++;
		if (i > 0)
			write(1, (format), i);
		if (format[i] == '%')
			format += manage_flag(format + i, ap, &total);
		total += i;
		format += i;
	}
	va_end(ap);
	return (total);
}

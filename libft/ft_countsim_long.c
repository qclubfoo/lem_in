/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countsim_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 19:46:49 by sbrella           #+#    #+#             */
/*   Updated: 2019/03/17 22:41:20 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_countsim_long(long long int n, char sign)
{
	int						h;
	int						sym;
	unsigned long long int	u;

	if (sign == 'd' || sign == 'i' || sign == 'u' || sign == 'D' || sign == 'U')
		sym = 10;
	else if (sign == 'o' || sign == 'O')
		sym = 8;
	else
		sym = 16;
	h = 0;
	if (n < 0 && (sign == 'd' || sign == 'i' || sign == 'D'))
		h++;
	if (sign == 'd' || sign == 'i' || sign == 'D')
		while ((n = (n / sym)))
			h++;
	else
	{
		u = (unsigned long long)n;
		while ((u = (u / sym)))
			h++;
	}
	return (h + 2);
}

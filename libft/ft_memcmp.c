/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:21:55 by sbrella           #+#    #+#             */
/*   Updated: 2019/01/25 17:16:19 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a1;
	unsigned char	*a2;

	if (!s1 && !s2)
		return (0);
	a1 = (unsigned char*)s1;
	a2 = (unsigned char*)s2;
	i = 0;
	while ((a1[i] == a2[i]) && (n > 1))
	{
		n--;
		i++;
	}
	if (n == 0)
		return (0);
	else
		return ((int)a1[i] - (int)a2[i]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countsim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:57:47 by sbrella           #+#    #+#             */
/*   Updated: 2019/03/14 21:24:37 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_countsim(int n)
{
	int h;

	h = 0;
	if (n < 0)
		h++;
	while ((n = (n / 10)))
		h++;
	return (h + 2);
}

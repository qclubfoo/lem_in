/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:10:34 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/22 14:59:31 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		 main(void)
{
	t_map   *map;

	map = validate();
	if ((connected(map)))
		ft_printf("%s\n", map->file);
	else
	{
		/* error */
		exit (0);
	}
	free(map->file);
	return (0);
}

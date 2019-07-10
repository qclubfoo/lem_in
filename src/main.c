/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:10:34 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/10 19:19:25 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int main(void)
{
	t_map   *map;
	t_map	*way;

	map = validate();
	if ((way = connected(map)) != NULL)
		ft_printf("%s\n", map->file);
	else
	{
		/* code */
		exit (0);
	}
	free(map->file);
	return (0);
}
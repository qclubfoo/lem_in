/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:39:17 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/02 13:37:29 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	ft_exit(char *str)
{
	free(str);
	str = NULL;
	write(2, "Error\n", 6);
	exit(0);
}

int 	main(void)
{
	char	*str;
	t_map	*map;

	str = ft_read();
	ft_check_map(str) == 1 ? ft_exit(str) : 0;
	// map = ft_make_map(str, check);
	// map == NULL ? ft_exit(str) : 0;
	write(1, "OK\n", 3);
	free(str);
	str = NULL;
	// ft_make_map(&map, str);
	return (0);
}

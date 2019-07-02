/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:39:17 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/01 15:12:28 by qclubfoo         ###   ########.fr       */
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
	t_check	*check;
	t_map	*map;

	str = ft_read();
	check = ft_check_map;
	check == NULL ? ft_exit(str) : 0;
	map = ft_make_map(str, check);
	map == NULL ? ft_exit(str) : 0;
	write(1, "OK\n", 3);
	// ft_make_map(&map, str);
	return (0);
}

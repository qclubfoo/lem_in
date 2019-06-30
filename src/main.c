/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:39:17 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/30 23:10:40 by qclubfoo         ###   ########.fr       */
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
	char    *str;

	str = ft_read();
	if (ft_check_map(str))
		ft_exit(str); // написать функцию для выхода с очисткой строки
	write(1, "OK\n", 3);
	// ft_make_map(&map, str);
	return (0);
}

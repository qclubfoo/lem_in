/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonds_adding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:47:27 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/02 18:08:28 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_bond		*add_first_bond(void)
{
	t_bond	*first_bond;

	first_bond = (t_bond*)malloc(sizeof(t_bond));
	first_bond->next = NULL;
	return (first_bond);
}

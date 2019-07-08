/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:33:10 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/08 12:20:54 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

char	*ft_realloc(char *str, int re)
{
	char	*tmp;
	int		len;

	if (str == NULL)
	{
		if (!(str = (char*)malloc(sizeof(char) * (re + 1))))
			exit(0);
		str[re] = '\0';
		return (str);
	}
	len = ft_strlen(str);
	if (!(tmp = (char*)malloc(sizeof(char) * (len + re + 1))))
		exit(0);
	ft_bzero(tmp, len + re);
	ft_strncpy(tmp, str, 0);
	free(str);
	str = NULL;
	return (tmp);
}

char	*ft_read(void)
{
	char	*str;
	char	buf[BUFF_SIZE + 1];
	int		re;
	int		i;

	re = 0;
	i = 0;
	ft_bzero(buf, BUFF_SIZE);
	str = NULL;
	while ((re = read(0, buf, BUFF_SIZE)) > 0)
	{
		str = ft_realloc(str, re);
		i = ft_strncpy(str, buf, i);
		ft_bzero(buf, BUFF_SIZE);
		re = 0;
	}
	return (str);
}

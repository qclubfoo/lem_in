/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:25:20 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/26 15:03:54 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define BUFF_SIZE 8
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct  s_map
{
    char        *name;
    char        *neigh;
    int         x;
    int         y;
}               t_map;

int				ft_strncpy(char *dst, char *src, int i);
int				ft_strlen(char *str);
void			ft_bzero(char *str, int len);

char	        *ft_read(void);
char	        *ft_realloc(char *str, int re);

#endif

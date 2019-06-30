/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:25:20 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/30 23:19:31 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define BUFF_SIZE 128
# define MAX_I 214748364
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct			s_check
{
	int					err;
	int					start;
	int					end;
	int					rooms;
	int					bonds;
	int					check_type;
}						t_check;

int						ft_strncpy(char *dst, char *src, int i);
int						ft_strlen(char *str);
void					ft_bzero(char *str, int len);
char					**ft_strsplit(char *str, char del);
int						ft_atoi_err(char *str, int *err);
int						ft_strcmp(char *str, char *find);

char					*ft_read(void);
char					*ft_realloc(char *str, int re);

int						ft_check_map(char *input);
void					ft_init_check(t_check *check);
int						ft_check_hash(char **str, int *i, t_check *check);
void					check_room(char *str, int *check_type, int *rooms, int *err);
void					check_bond(char *str, int *bonds, int *err);
int						ft_return (char **str, int err);


#endif

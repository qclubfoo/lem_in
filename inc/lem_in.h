/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:25:20 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/30 09:00:58 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define BUFF_SIZE 128
# define MAX_I 214748364
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct			s_room
{
	char				*name;
	struct s_sosedi		*neigh;
	int					start;
	int					finish;
	int					x;
	int					y;
	struct s_room		*next;
}						t_room;

typedef struct			s_sosedi
{
	struct s_sosedi		*neigh;
	struct s_sosedi		*next;
}						t_sosedi;

typedef struct			s_map
{
	int					ants;
	struct s_room		*rooms;
}						t_map;

int						ft_strncpy(char *dst, char *src, int i);
int						ft_strlen(char *str);
void					ft_bzero(char *str, int len);
char					**ft_strsplit(char *str, char del);
int						ft_atoi_err(char *str, int *err);
int						ft_strcmp(char *str, char *find);

char					*ft_read(void);
char					*ft_realloc(char *str, int re);

int						ft_check_map(char *input);

t_room					*add_first_room(void);
t_room					*add_new_room(t_room *head);

#endif

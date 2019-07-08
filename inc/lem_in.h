/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:25:20 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/08 12:56:22 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define BUFF_SIZE 256
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
	int					comments;
	int					check_type;
}						t_check;

typedef struct			s_bond
{
	struct s_room		*bond;
	struct s_bond		*next;
}						t_bond;

typedef struct			s_room
{
	char				*name;
	int					se;
	struct s_bond		*bonds;
	struct s_room		*next;
	int					x;
	int					y;
}						t_room;

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
int						ft_atoi(char *str);
int						ft_printf(const char *restrict format, ...);
int						ft_strchr(char *str, char c);

char					*ft_read(void);
char					*ft_realloc(char *str, int re);

t_check					*ft_check_map(char *input);
void					ft_checking(t_check *check, char **str);
int						ft_check_hash(char **str, int *i, t_check *check);
void					check_room(char *str, t_check *check);
void					check_bond(char *str, t_check *check);

void					ft_init_check(t_check *check);
void					ft_return (char **str);
int						ft_count_del(char *str, char del);
void					*exit_checking(t_check *check, char **str);

t_room					*add_first_room(void);
t_room					*add_new_room(t_room *head);
int						ft_make_map(char *input, t_map *map);

void					ft_free_map(t_map *map);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:25:20 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/07/10 19:13:20 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_check
{
	int				err;
	int				start;
	int				end;
	int				rooms;
	int				bonds;
	int				comments;
	int				check_type;
	int				flag;
}					t_check;

typedef struct		s_bond
{
	struct s_room	*bond;
	struct s_bond	*next;
}					t_bond;

typedef struct		s_room
{
	char			*name;
	int				se;
	struct s_bond	*bonds;
	struct s_room	*next;
	int				x;
	int				y;
}					t_room;

typedef struct		s_map
{
	int				ants;
	char			*file;
	struct s_room	*rooms;
}					t_map;

char				*ft_read(void);
char				*ft_realloc(char *str, int re);

t_check				*ft_check_map(char *input);
void				ft_checking(t_check *check, char **str);
int					ft_check_hash(char **str, int *i, t_check *check);
void				check_room(char *str, t_check *check);
void				check_bond(char *str, t_check *check);

void				ft_init_check(t_check *check);
void				ft_return (char **str);
int					ft_count_del(char *str, char del);
void				*exit_checking(t_check *check, char **str);

int					ft_make_map(char *input, t_map *map);
char				**ft_init_making_map(char *input, t_map *map,
														int *i, int *se);
int					ft_make_hash(char **str, int *i, int *se);

void				ft_make_room(char *str, t_map *map, int *check_type,
																int *se);
void				ft_write_room(t_map *map, char **make_room, int *se);
t_room				*add_first_room(void);
t_room				*add_new_room(t_room *head);

int					ft_make_bond(char *str, t_map *map);
void				ft_find_bond(char *str, t_map *map,
											t_room **dst, t_room **src);
int					ft_check_repeat(t_room *src, t_room *dst, int flag);
void				ft_add_bond(t_room *src, t_room *dst);

void				ft_check_el(t_check *check, char *str);
int					ft_check_rep_rooms(t_room *rooms);

void				ft_exit(char *str);
void				ft_free_map(t_map *map);
void				ft_free_and_exit(t_map *map, t_check *check, char *str);
t_map				*validate(void);

#endif

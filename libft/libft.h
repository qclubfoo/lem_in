/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:08:54 by sbrella           #+#    #+#             */
/*   Updated: 2019/07/10 18:52:38 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>
# define MIN(Val1, Val2) Val1 > Val2 ? Val2 : Val1
# define BUFF_SIZE 256
# define MAX_I 214748364

typedef struct			s_specs
{
	char				*str;
	void				*ptr;
	int					i;
	int					hash;
	int					minus;
	int					zero;
	int					space;
	int					point;
	int					atoi;
	int					lng;
	int					precision;
	int					plus;
	int					lnglng;
	int					shrt;
	int					shrtshrt;
	int					bigl;
}						t_specs;

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_datalist
{
	int					label;
	void				*data;
	size_t				size;
	struct s_datalist	*next;
}						t_dlist;

typedef struct			s_stack
{
	int					i;
	struct s_stack		*next;
}						t_stack;

void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(char *str, int len);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, \
						int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
int						ft_strncpy(char *dst, char *src, int i);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
int						ft_strchr(const char *str, char c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack, \
						const char *needle, size_t len);
int						ft_strcmp(char *str, char *find);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, \
						char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, \
						unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char *str, char del);
char					*ft_itoa(int n);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, \
						void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void					ft_lstadd(t_list **alst, t_list *neww);
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
unsigned int			ft_countsim(int n);
size_t					ft_strlen(const char *str);
size_t					ft_safelen(const char *s);
size_t					ft_strcopy(char *dst, const char *src, size_t size);
t_dlist					*ft_dlstadd(int fd, t_dlist *next);
void					ft_dlstcut(t_dlist *prev);
void					*ft_smemmove(void *dst, \
						const void *src, size_t n);
int						ft_dlstdellbl(int label, t_dlist **begin);
int						ft_get_next_line(const int fd, char **line);
int						ft_sqrt(int nb);
int						ft_putstr_mod(char const *s);
int						ft_printf(const char *format, ...);
int						ft_putnstr(char *str, size_t lim);
void					ft_putnbr_long(long long int n, char sign);
unsigned int			ft_countsim_long(long long int n, char sign);
void					put_symb(size_t a, char b);
void					cut_int(long double *a);
unsigned int			ft_put_int(long double a);
void					manage_fli(char sign, t_specs *sp,
						int *i, long long int a);
void					man_form(t_specs *sp, const char
						**format, size_t *skip);
int						manage_f(size_t *total, va_list ap, t_specs *sp);
int						char_conv(size_t *total,
						t_specs *sp, unsigned int ch);
void					ft_round(int precision, int point, long double *a);
int						string_conv(size_t *total, t_specs *sp, char *ptr);
void					manage_dpoint(t_specs *sp, size_t *total, char sign,
						long long int a);
int						man_len(t_specs *sp, const char *format);
long long int			convert_d(va_list ap, t_specs *sp, char sign);
int						ft_putpoint(int precision, int point, long double a);
int						pointer_conv(void *ptr, size_t *total, t_specs *sp);
int						manage_d(t_specs *sp, size_t *total,
						va_list ap, char sign);
int						ft_abs(int a);
int						ft_atoi_err(char *str, int *err);
#endif

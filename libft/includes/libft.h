/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:12:38 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/02/25 20:49:30 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "ft_printf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(char const *str);
char				*ft_strcpy(char *dst, char const *src);
char				*ft_strncpy(char *dst, char const *src, size_t n);
char				*ft_strstr(char const *s1, char const *s2);
char				*ft_strnstr(char const *s1, char const *s2, size_t n);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strdup(char const *s1);
void				ft_putchar(wchar_t c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long n);
char				*ft_itoau(unsigned long long n);
void				ft_strclr(char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
long long int		ft_atoi(char const *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strncat(char *s1, char const *s2, size_t n);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
char				*ft_strchr(char const *s, int c);
char				*ft_strrchr(char const *s, int c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, void const *src, size_t n);
void				*ft_memccpy (void *dest, void const *src, int c, size_t n);
void				*ft_memmove(void *dst, void const *src, size_t len);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				**ft_tab_char(int line, int *col);
char				*ft_strrev(char *str);
int					ft_lstlen(t_list *lst);
void				ft_lst_backadd(t_list **alst, t_list *new);
void				ft_puttabl(char **tab);
void				ft_putnbrl(int n);
int					ft_sizeint(long long n);
void				ft_putstr_uni(wchar_t *str);
char				*ft_putfloat(double n, int p);
char				*ft_itoa_base(unsigned long long n, int base, int i);
char				*ft_print_mem(void *adress);
char				*ft_wconvchar(wchar_t wc, int *len);
char				*ft_wconvstr(wchar_t *wstr, int *len);
int					ft_sizeintu(unsigned long long n);
int					ft_strchr_c(char const *s, int c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:12:16 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/01/06 17:12:17 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define FMT format[s->i + 1]
# define RED "\e[0;31m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define WHITE "\e[0;21m"

typedef struct		s_mod
{
	int		i;
	int		champ;
	int		count;
	int		prec;
	char	space;
	int		len;
	char	zero;
	char	hash;
	char	plus;
	char	minus;
	int		null;
	char	zeroc;
	char	fla;
	char	l;
	char	j;
	char	h;
	char	z;
	char	wild;
}					t_mod;

typedef struct		s_flag
{
	char	c;
	char	*(*p)(t_mod *s, va_list ap);
}					t_flag;

int					ft_printf(const char *format, ...);
t_flag				*initiate_tab(void);
void				reset_struck(t_mod *s);
char				*decimal(t_mod *s, va_list ap);
char				*string(t_mod *s, va_list ap);
char				*string_uni(t_mod *s, va_list ap);
char				*carac(t_mod *s, va_list ap);
char				*carac_uni(t_mod *s, va_list ap);
char				*decimal_long(t_mod *s, va_list ap);
char				*decimal_usgn(t_mod *s, va_list ap);
char				*decimal_usgn_long(t_mod *s, va_list ap);
char				*pointer(t_mod *s, va_list ap);
char				*octal(t_mod *s, va_list ap);
char				*octal_m(t_mod *s, va_list ap);
char				*hexa(t_mod *s, va_list ap);
char				*hexa_m(t_mod *s, va_list ap);
char				*tab(t_mod *s, va_list ap);
char				*strfloat(t_mod *s, va_list ap);
char				*strfloatg(t_mod *s, va_list ap);
char				*float_e(t_mod *s, va_list ap);
char				*float_big_e(t_mod *s, va_list ap);
char				*binaire(t_mod *s, va_list ap);
char				*binaire_str(t_mod *s, va_list ap);
char				*tab_int(t_mod *s, va_list ap);
char				*minus_tmp(char **str, char **tmp, t_mod *s);
char				*tmp_zero(char **tmp, t_mod *s, char a);
char				*tmp_space(char **tmp, t_mod *s, char a);
char				*tmp_join(char **tmp, char *c, char a, char b);
char				*tmp_str_join(char **str, char *tmp);
char				*for_carac(t_mod *s, char *str, char *tmp);
char				*for_string(t_mod *s, char *str, char *tmp);
char				*for_octal(t_mod *s, char *str, char *tmp);
char				*for_hexa(t_mod *s, char *str, char **tmp, char a);
char				*for_dec(t_mod *s, char *str, long int a);
long int			octal_a(va_list ap, t_mod *s);
long int			dec_a(va_list ap, t_mod *s);
long int			decu_a(va_list ap, t_mod *s);
void				analyse_nbr(t_mod *s, char const *format, va_list ap);
int					final_print(char *final, t_mod *s);
void				na_mod(char **final, t_mod *s, char const *fmt);
char				*number_afterflag(t_mod *s);
int					is_flag(char **final, t_mod *s, t_flag *flags, va_list ap);
int					is_mod(t_mod *s, char **final);
char				*final_str(char const *format,
	t_mod *s, t_flag *flags, va_list ap);
int					cpy_fmt(char const *format,
	char **final, t_mod *s, va_list ap);
char				*temp_free(char **str);
char				*sub_free(char **str, char a);
int					putcolors(char *final, t_mod *s);
void				final_print_tmp(char *final, t_mod *s);
void				search_for_colors(char *final, int *i);
void				print_tmp(char *tmp, t_mod *s, char *final, int j);

#endif

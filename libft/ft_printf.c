/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:36:49 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/01/06 16:36:55 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		analyse_fmt(char const *format, int *i)
{
	while (format[*i])
	{
		if (format[*i] == '%')
			break ;
		++*i;
	}
}

static t_mod	*initiate_struck(void)
{
	t_mod *s;

	s = (t_mod*)malloc(sizeof(t_mod));
	s->i = 0;
	s->len = -1;
	s->count = 0;
	s->zero = 0;
	s->zeroc = 0;
	s->champ = -1;
	s->prec = -1;
	s->space = 0;
	s->hash = 0;
	s->plus = 0;
	s->minus = 0;
	s->wild = 0;
	s->j = 0;
	s->l = 0;
	s->h = 0;
	s->z = 0;
	s->null = 0;
	return (s);
}

void			reset_struck(t_mod *s)
{
	s->zeroc = 0;
	s->plus = 0;
	s->minus = 0;
	s->hash = 0;
	s->champ = -1;
	s->prec = -1;
	s->space = 0;
	s->zero = 0;
	s->fla = 0;
	s->j = 0;
	s->l = 0;
	s->h = 0;
	s->z = 0;
}

int				cpy_fmt(char const *format, char **final, t_mod *s, va_list ap)
{
	char *tmp;

	s->i = 0;
	analyse_fmt(format, &s->i);
	if (s->i > 0)
	{
		tmp = ft_strnew(s->i);
		tmp = ft_strncpy(tmp, format, s->i);
		*final = tmp_str_join(final, tmp);
	}
	analyse_nbr(s, format, ap);
	s->fla = FMT;
	if (!(FMT))
		return (0);
	return (1);
}

int				ft_printf(const char *format, ...)
{
	va_list ap;
	t_flag	*flags;
	char	*final;
	t_mod	*s;

	s = initiate_struck();
	while (format[s->i])
	{
		if (format[s->i] == '%')
			s->count++;
		++s->i;
	}
	va_start(ap, format);
	flags = initiate_tab();
	final = final_str(format, s, flags, ap);
	free(flags);
	va_end(ap);
	return (final_print(final, s));
}

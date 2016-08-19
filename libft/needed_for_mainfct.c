/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed_for_mainfct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 21:57:13 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/02/01 21:57:14 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			final_print(char *final, t_mod *s)
{
	int		l;

	if (s->len == -1)
		s->len = 0;
	else
		final_print_tmp(final, s);
	if (s->len == 0 && putcolors(final, s))
		l = s->len;
	else if (s->len == 0)
		ft_putstr(final);
	if (s->len <= 1)
		l = s->len + ft_strlen(final);
	free(final);
	free(s);
	return (l);
}

void		na_mod(char **final, t_mod *s, char const *fmt)
{
	char *tp;

	tp = NULL;
	if (s->champ > 1 && !s->minus)
		tp = number_afterflag(s);
	if (s->minus)
	{
		tp = ft_strsub(fmt, s->i + 1, 1);
		tp = tmp_str_join(&tp, number_afterflag(s));
		s->i++;
	}
	if (tp)
		*final = tmp_str_join(final, tp);
}

static void	null_carac(char **final, t_mod *s)
{
	if (s->null > 0)
		s->len = s->null + ft_strlen(*final);
	else
		s->len = ft_strlen(*final);
	s->null = 0;
}

int			is_flag(char **final, t_mod *s, t_flag *flags, va_list ap)
{
	int		l;
	char	*tmp;

	tmp = NULL;
	l = 0;
	while (l < 25)
	{
		if (s->fla == flags[l].c)
		{
			tmp = flags[l].p(s, ap);
			if (tmp[0] == '-' && s->prec > (int)ft_strlen(tmp))
				s->champ--;
			if (s->null)
				null_carac(final, s);
			reset_struck(s);
			*final = tmp_str_join(final, tmp);
			++s->i;
			return (1);
		}
		++l;
	}
	return (0);
}

int			is_mod(t_mod *s, char **final)
{
	char *tmp;

	tmp = NULL;
	if (s->fla == '%')
	{
		tmp = number_afterflag(s);
		s->count--;
		if (!s->minus)
			tmp = tmp_join(&tmp, "%", 0, 0);
		else
			tmp = tmp_join(&tmp, "%", 1, 0);
		*final = tmp_str_join(final, tmp);
		++s->i;
		reset_struck(s);
		return (1);
	}
	return (0);
}

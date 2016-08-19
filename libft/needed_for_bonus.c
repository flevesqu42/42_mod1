/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed_for_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 06:51:51 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/02/04 06:51:51 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	final_print_tmp(char *final, t_mod *s)
{
	char	c;
	char	*tmp;

	c = 0;
	tmp = ft_strnew(s->len + 2);
	tmp = ft_strsub(final, 0, s->len);
	ft_putstr(tmp);
	free(tmp);
	write(1, &c, 1);
	tmp = ft_strsub(final, s->len, ft_strlen(final));
	ft_putstr(tmp);
	free(tmp);
	s->len = 1;
}

void	search_for_colors(char *final, int *i)
{
	while (final[*i])
	{
		if (final[*i] == '{' && final[*i + 1] == 'C')
			break ;
		++*i;
	}
}

void	print_tmp(char *tmp, t_mod *s, char *final, int j)
{
	s->len = s->len + ft_strlen(final) - j;
	ft_putstr(tmp);
	free(tmp);
}

char	*tab_int(t_mod *s, va_list ap)
{
	char	*str;
	int		*i;
	int		j;

	(void)s;
	i = va_arg(ap, int*);
	j = 0;
	str = ft_strnew(0);
	while (s->champ > 0)
	{
		str = tmp_str_join(&str, ft_itoa(i[j]));
		++j;
		--s->champ;
		if (s->champ > 0)
			str = tmp_join(&str, " ", 0, 0);
	}
	return (str);
}

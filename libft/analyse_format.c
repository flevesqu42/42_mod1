/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 21:38:06 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/02/01 21:38:08 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision(t_mod *s, char const *format, va_list ap)
{
	while (format[s->i + 1] >= '0' && format[s->i + 1] <= '9')
	{
		s->prec = s->prec * 10 + (format[s->i + 1] - '0');
		++s->i;
	}
	if (FMT == '*')
	{
		s->prec = va_arg(ap, int);
		if (s->prec < 0)
			s->prec = s->champ;
		s->i++;
		s->wild = 1;
	}
}

static void	analyse_nbr_three(t_mod *s, char const *format, va_list ap)
{
	if (FMT == '#')
		s->hash = 1;
	if (FMT == ' ')
		s->space = 1;
	if (FMT == '+')
		s->plus = 1;
	if (FMT == '-')
		s->minus = 1;
	if (FMT == '*')
	{
		s->champ = va_arg(ap, int);
		if (s->champ < 0)
		{
			s->minus = 1;
			s->champ = -s->champ;
		}
		s->wild = 1;
	}
}

static void	analyse_nbr_two(t_mod *s, char const *format, va_list ap)
{
	while ((FMT >= '0' && FMT <= '9') || FMT == '+' || FMT == '-'
		|| FMT == '#' || FMT == ' ' || FMT == '*')
	{
		analyse_nbr_three(s, format, ap);
		if (FMT == '+' || FMT == '-' || FMT == '#' || FMT == ' '
			|| FMT == '*')
		{
			++s->i;
			continue ;
		}
		if (!ft_isdigit(format[s->i]))
			s->champ = 0;
		if (!ft_isdigit(format[s->i]) && format[s->i + 1] == '0')
		{
			s->zeroc = 1;
			s->zero = 1;
		}
		s->champ = s->champ * 10 + (format[s->i + 1] - '0');
		++s->i;
	}
}

static void	analyse_nbr_four(t_mod *s, char const *format)
{
	if (s->l)
		s->h = 0;
	if (s->j || s->z)
	{
		s->l = 0;
		s->h = 0;
	}
	while ((FMT >= '0' && FMT <= '9') || FMT == '+'
		|| FMT == '-' || FMT == '#' || FMT == ' ')
	{
		if (FMT == '#')
			s->hash = 1;
		if (FMT == ' ')
			s->space = 1;
		if (FMT == '+')
			s->plus = 1;
		if (FMT == '-')
			s->minus = 1;
		s->i++;
	}
}

void		analyse_nbr(t_mod *s, char const *format, va_list ap)
{
	analyse_nbr_two(s, format, ap);
	while (format[s->i + 1] == '.')
	{
		++s->i;
		s->zero = 0;
		s->prec = 0;
		precision(s, format, ap);
	}
	while (FMT == 'l' || FMT == 'h' || FMT == 'j' || FMT == 'z')
	{
		if (FMT == 'l')
			s->l++;
		if (FMT == 'h')
			s->h++;
		if (FMT == 'j')
			s->j++;
		if (FMT == 'z')
			s->z++;
		if (s->j > 1 || s->z > 1 || s->h > 2 || s->l > 2)
			break ;
		s->i++;
	}
	analyse_nbr_four(s, format);
}

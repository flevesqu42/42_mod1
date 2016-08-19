/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:57:00 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/02/03 19:57:01 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*tab(t_mod *s, va_list ap)
{
	char	**tab;
	int		i;
	char	*str;
	char	*temp;
	char	*tmp;

	i = 0;
	(void)s;
	tab = va_arg(ap, char**);
	str = ft_strnew(1);
	while (tab[i])
	{
		tmp = ft_strdup(tab[i]);
		temp = str;
		str = ft_strjoin(str, tmp);
		free(temp);
		free(tmp);
		temp = str;
		str = ft_strjoin(str, "\n");
		free(temp);
		++i;
	}
	return (str);
}

char		*strfloat(t_mod *s, va_list ap)
{
	double	a;
	char	*str;

	a = va_arg(ap, double);
	str = ft_putfloat(a, s->prec);
	return (str);
}

char		*strfloatg(t_mod *s, va_list ap)
{
	double	a;
	char	*str;
	int		i;
	char	*temp;

	a = va_arg(ap, double);
	str = ft_putfloat(a, s->prec);
	str = ft_strrev(str);
	i = 0;
	while (str[i] == '0' || str[i] == '.')
	{
		if (str[i] == '0')
			;
		else
		{
			++i;
			break ;
		}
		++i;
	}
	temp = str;
	str = ft_strdup(str + i);
	free(temp);
	str = ft_strrev(str);
	return (str);
}

char		*float_e(t_mod *s, va_list ap)
{
	double	a;
	char	*str;
	int		ep;
	int		epm;

	a = va_arg(ap, double);
	ep = 0;
	epm = 0;
	while (a <= -10.0 || a >= 10.0)
	{
		a = a / 10;
		++ep;
	}
	while (a > -1.0 && a < 1.0)
	{
		a = a * 10;
		epm++;
	}
	str = ft_putfloat(a, s->prec);
	(epm) ? tmp_join(&str, "e-", 0, 0) : tmp_join(&str, "e+", 0, 0);
	if (ep < 10 && epm < 10)
		str = tmp_zero(&str, s, 0);
	(epm) ? tmp_str_join(&str, ft_itoa(epm)) : tmp_str_join(&str, ft_itoa(ep));
	return (str);
}

char		*float_big_e(t_mod *s, va_list ap)
{
	double	a;
	char	*str;
	int		ep;
	int		epm;

	a = va_arg(ap, double);
	ep = 0;
	epm = 0;
	while (a <= -10.0 || a >= 10.0)
	{
		a = a / 10;
		++ep;
	}
	while (a > -1.0 && a < 1.0)
	{
		a = a * 10;
		epm++;
	}
	str = ft_putfloat(a, s->prec);
	(epm) ? tmp_join(&str, "E-", 0, 0) : tmp_join(&str, "E+", 0, 0);
	if (ep < 10 && epm < 10)
		str = tmp_zero(&str, s, 0);
	(epm) ? tmp_str_join(&str, ft_itoa(epm)) : tmp_str_join(&str, ft_itoa(ep));
	return (str);
}

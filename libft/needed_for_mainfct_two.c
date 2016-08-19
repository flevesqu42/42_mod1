/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed_for_mainfct_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:12:56 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/02/02 17:12:57 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	decu_a(va_list ap, t_mod *s)
{
	long int a;

	if (s->z)
		a = va_arg(ap, size_t);
	else if (s->j)
		a = va_arg(ap, intmax_t);
	else
		a = va_arg(ap, unsigned int);
	if (s->h == 1)
		a = (unsigned short int)a;
	if (s->h == 2)
		a = (unsigned char)a;
	return (a);
}

char		*number_afterflag(t_mod *s)
{
	char *final;

	final = ft_strnew(1);
	while (s->champ > 1 && s->zeroc == 0 && !s->minus)
		final = tmp_space(&final, s, 0);
	while (s->champ > 1 && s->zeroc && !s->minus)
		final = tmp_zero(&final, s, 0);
	while (s->champ > 1)
		final = tmp_space(&final, s, 0);
	return (final);
}

char		*final_str(char const *format, t_mod *s, t_flag *flags, va_list ap)
{
	char	*final;

	final = ft_strnew(1);
	while (format)
	{
		if (!(cpy_fmt(format, &final, s, ap)))
			break ;
		if (s->count > 0)
		{
			if (is_mod(s, &final))
				;
			else if (is_flag(&final, s, flags, ap))
				;
			else
				na_mod(&final, s, format);
			s->count--;
			if (!(format + s->i + 1))
				break ;
			else
				format = format + s->i + 1;
		}
		else
			break ;
	}
	return (final);
}

char		*temp_free(char **str)
{
	char	*temp;

	temp = *str;
	*str = ft_strdup(*str + 1);
	free(temp);
	return (*str);
}

char		*sub_free(char **str, char a)
{
	char	*temp;

	temp = *str;
	if (!a)
		*str = ft_strsub(*str, 0, 2);
	else
		*str = ft_strsub(*str, 2, ft_strlen(*str));
	free(temp);
	return (*str);
}

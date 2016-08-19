/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed_for_argstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:30:08 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/02/01 17:30:10 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*for_carac(t_mod *s, char *str, char *tmp)
{
	if (((s->champ - (int)ft_strlen(str)) > 0) && !s->zero
		&& s->prec < s->champ)
		tmp = ft_strnew(s->champ - (int)ft_strlen(str));
	while (s->champ > (int)ft_strlen(str) && s->minus)
		tmp = tmp_space(&tmp, s, 0);
	if (s->champ > (int)ft_strlen(str) && s->zeroc && !s->minus)
		tmp = ft_strnew(s->champ);
	while (s->champ > (int)ft_strlen(str) && s->zeroc && !s->minus)
		tmp = tmp_zero(&tmp, s, 0);
	while (s->champ > (int)ft_strlen(str))
		tmp = tmp_space(&tmp, s, 0);
	if (s->null && ft_strlen(str) > 0 && s->wild)
		s->null = ft_strlen(str);
	if (s->null && !ft_strlen(str) && s->wild)
		s->null = -1;
	str = minus_tmp(&str, &tmp, s);
	if (s->null && ft_strlen(str) > 0 && !s->wild)
		s->null = ft_strlen(str);
	if (s->null && !ft_strlen(str) && !s->wild)
		s->null = -1;
	s->wild = 0;
	return (str);
}

char		*for_octal(t_mod *s, char *str, char *tmp)
{
	if (((s->champ - (int)ft_strlen(str)) > 0)
		&& !s->zero && s->prec < s->champ)
		tmp = ft_strnew(s->champ - (int)ft_strlen(str));
	while (s->champ > (int)ft_strlen(str) && s->prec < s->champ && !s->zero)
		tmp = tmp_space(&tmp, s, 0);
	if (s->hash && str[0] != '0' && !s->minus)
		tmp = tmp_join(&tmp, "0", 0, 0);
	if (s->hash && str[0] != '0' && s->minus)
		str = tmp_join(&str, "0", 1, 0);
	if (!tmp && !str[0])
		tmp = ft_strnew(1);
	while (((s->champ > (int)ft_strlen(str) && s->zero)
		|| (s->prec > (int)ft_strlen(str))) && !s->minus)
		tmp = tmp_zero(&tmp, s, 0);
	while (s->prec > (int)ft_strlen(str))
		str = tmp_join(&str, "0", 1, 0);
	while (s->champ > (int)ft_strlen(str))
		tmp = tmp_space(&tmp, s, 0);
	str = minus_tmp(&str, &tmp, s);
	return (str);
}

static char	*for_hexa_two(t_mod *s, char *str, char **tmp, char a)
{
	if (s->hash && ((int)ft_strlen(str) >= 1
		&& str[0] != '0') && s->minus && !a)
	{
		s->champ += 2;
		str = tmp_join(&str, "0x", 1, 0);
	}
	if (s->hash && ((int)ft_strlen(str) >= 1
		&& str[0] != '0') && !s->minus && a)
		*tmp = tmp_join(tmp, "0X", 0, 0);
	if (s->hash && ((int)ft_strlen(str) >= 1
		&& str[0] != '0') && s->minus && a)
	{
		s->champ += 2;
		str = tmp_join(&str, "0X", 1, 0);
	}
	return (str);
}

char		*for_hexa(t_mod *s, char *str, char **tmp, char a)
{
	if (((s->champ - (int)ft_strlen(str)) > 0)
		&& !s->zero && s->prec < s->champ)
		*tmp = ft_strnew(s->champ - (int)ft_strlen(str));
	while (s->champ > (int)ft_strlen(str)
		&& s->prec < s->champ && !s->zero)
		*tmp = tmp_space(tmp, s, 0);
	if (s->hash && ((int)ft_strlen(str) >= 1
		&& str[0] != '0') && !s->minus && !a)
		*tmp = tmp_join(tmp, "0x", 0, 0);
	str = for_hexa_two(s, str, tmp, a);
	while (((s->champ > (int)ft_strlen(str) && s->zero)
		|| s->prec > (int)ft_strlen(str)) && !s->minus)
		*tmp = tmp_zero(tmp, s, 0);
	while (s->champ > (int)ft_strlen(str))
		*tmp = tmp_space(tmp, s, 0);
	return (str);
}

long int	octal_a(va_list ap, t_mod *s)
{
	long int a;

	if (s->z)
		a = va_arg(ap, size_t);
	else if (s->j)
		a = va_arg(ap, uintmax_t);
	else
	{
		a = va_arg(ap, long long);
		a = (unsigned int)a;
	}
	if (s->h == 1)
		a = (unsigned short int)a;
	if (s->h == 2)
		a = (unsigned char)a;
	return (a);
}

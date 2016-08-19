/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_base_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:32:42 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/01/13 19:32:44 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pointer(t_mod *s, va_list ap)
{
	char	*str;
	int		i;
	char	*tmp;

	str = ft_print_mem(va_arg(ap, void*));
	if (str[2] == '0' && !str[3] && !s->hash && s->prec == 0)
		str = sub_free(&str, 0);
	tmp = ft_strnew(s->champ + s->prec + 3);
	while (s->champ > (int)ft_strlen(str) && s->prec < s->champ && !s->zero)
		tmp = tmp_space(&tmp, s, 0);
	i = ft_strlen(str);
	if ((s->champ > i && s->zero) || (s->prec > i - 2))
		str = sub_free(&str, 1);
	while ((s->champ > i && s->zero) || (s->prec > i - 2))
		str = tmp_zero(&str, s, 1);
	if (str[1] != 'x')
		str = tmp_join(&str, "0x", 1, 0);
	str = minus_tmp(&str, &tmp, s);
	return (str);
}

char		*octal(t_mod *s, va_list ap)
{
	char		*str;
	char		*tmp;
	long int	a;

	if (s->l)
		return (octal_m(s, ap));
	a = octal_a(ap, s);
	str = ft_itoa_base(a, 8, 0);
	tmp = ft_strnew(s->champ + s->prec + 3);
	if (str[0] == '0' && !str[1] && !s->hash)
	{
		if (s->prec > s->champ && s->champ > 0)
			s->prec--;
		if (s->prec >= 0)
			str = temp_free(&str);
	}
	if (s->hash && str[0] != '0')
	{
		s->prec--;
		s->champ--;
	}
	str = for_octal(s, str, tmp);
	return (str);
}

char		*octal_m(t_mod *s, va_list ap)
{
	char				*str;
	char				*tmp;
	unsigned long long	a;

	tmp = NULL;
	a = va_arg(ap, unsigned long long int);
	if (s->h)
		a = (unsigned int)a;
	str = ft_itoa_base(a, 8, 1);
	tmp = ft_strnew(s->champ + s->prec + 3);
	if (str[0] == '0' && !str[1] && !s->hash)
	{
		if (s->prec > s->champ && s->champ > 0)
			s->prec--;
		if (s->prec >= 0)
			str = temp_free(&str);
	}
	str = for_octal(s, str, tmp);
	return (str);
}

char		*hexa(t_mod *s, va_list ap)
{
	char					*str;
	char					*tmp;
	unsigned long long int	a;

	if (s->l)
		a = va_arg(ap, unsigned long long int);
	else if (s->z)
		a = va_arg(ap, size_t);
	else if (s->j)
		a = va_arg(ap, uintmax_t);
	else
		a = va_arg(ap, unsigned int);
	if (s->h == 1)
		a = (unsigned short int)a;
	if (s->h == 2)
		a = (unsigned char)a;
	tmp = ft_strnew(s->champ + s->prec + 3);
	str = ft_itoa_base(a, 16, 0);
	if (str[0] == '0' && !str[1] && s->prec >= 0)
		str = temp_free(&str);
	if (s->hash && ((int)ft_strlen(str) >= 1 && str[0] != '0'))
		s->champ = s->champ - 2;
	str = for_hexa(s, str, &tmp, 0);
	str = minus_tmp(&str, &tmp, s);
	return (str);
}

char		*hexa_m(t_mod *s, va_list ap)
{
	char				*str;
	char				*tmp;
	unsigned long long	a;

	if (s->l)
		a = va_arg(ap, unsigned long long);
	else if (s->z)
		a = va_arg(ap, size_t);
	else if (s->j)
		a = va_arg(ap, uintmax_t);
	else
		a = va_arg(ap, unsigned int);
	if (s->h == 1)
		a = (unsigned short int)a;
	if (s->h == 2)
		a = (unsigned char)a;
	str = ft_itoa_base(a, 16, 1);
	tmp = ft_strnew(s->champ + s->prec + 3);
	if (s->hash && ((int)ft_strlen(str) >= 1 && str[0] != '0'))
		s->champ = s->champ - 2;
	if (str[0] == '0' && !str[1] && s->prec >= 0)
		str = temp_free(&str);
	str = for_hexa(s, str, &tmp, 1);
	str = minus_tmp(&str, &tmp, s);
	return (str);
}

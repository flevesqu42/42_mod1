/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:30:38 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/01/13 17:30:39 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*decimal(t_mod *s, va_list ap)
{
	char			*str;
	long int		a;

	if (s->l)
		return (decimal_long(s, ap));
	a = dec_a(ap, s);
	if ((str = ft_itoa(a)) == NULL)
		return (NULL);
	if (str[0] == '0' && !str[1] && s->prec >= 0)
		str = temp_free(&str);
	if (str[0] == '0' && !str[1] && s->zero && !s->plus
		&& !s->minus && s->space)
		--s->champ;
	if (str[0] == '-' && (s->prec >= (int)ft_strlen(str)))
		s->champ--;
	str = for_dec(s, str, a);
	reset_struck(s);
	return (str);
}

char	*decimal_long(t_mod *s, va_list ap)
{
	char		*str;
	long int	a;

	a = va_arg(ap, long int);
	if (a < 0)
		s->space = 0;
	if (s->h)
		a = (int)a;
	if ((str = ft_itoa(a)) == NULL)
		return (NULL);
	if (str[0] == '0' && !str[1] && s->prec >= 0)
		str = temp_free(&str);
	if (str[0] == '0' && !str[1] && s->zero && !s->plus && !s->minus)
		--s->champ;
	if (str[0] == '-' && (s->prec >= (int)ft_strlen(str)))
		s->champ--;
	str = for_dec(s, str, a);
	reset_struck(s);
	return (str);
}

char	*decimal_usgn(t_mod *s, va_list ap)
{
	char			*str;
	long int		a;
	char			*tmp;

	if (s->l)
		return (decimal_usgn_long(s, ap));
	a = decu_a(ap, s);
	if ((str = ft_itoau(a)) == NULL)
		return (NULL);
	tmp = ft_strnew(s->champ + s->prec + 3);
	if (str[0] == '0' && !str[1] && s->prec >= 0)
		str = temp_free(&str);
	if (((s->champ - (int)ft_strlen(str)) > 0)
		&& !s->zero && s->prec < s->champ)
		tmp = ft_strnew(s->champ - (int)ft_strlen(str));
	while (s->champ > (int)ft_strlen(str) && s->prec < s->champ && !s->zero)
		tmp = tmp_space(&tmp, s, 0);
	while ((s->champ > (int)ft_strlen(str) && s->zero)
		|| s->prec > (int)ft_strlen(str))
		tmp = tmp_zero(&tmp, s, 0);
	str = minus_tmp(&str, &tmp, s);
	return (str);
}

char	*decimal_usgn_long(t_mod *s, va_list ap)
{
	char					*str;
	long long unsigned int	a;
	char					*tmp;

	if (s->l)
		a = va_arg(ap, unsigned long long);
	else
		a = va_arg(ap, long unsigned int);
	tmp = ft_strnew(s->champ + s->prec + 3);
	if ((str = ft_itoau(a)) == NULL)
		return (NULL);
	if (str[0] == '0' && !str[1] && s->prec >= 0)
		str = temp_free(&str);
	if (((s->champ - (int)ft_strlen(str)) > 0)
		&& !s->zero && s->prec < s->champ)
		tmp = ft_strnew(s->champ - (int)ft_strlen(str));
	while (s->champ > (int)ft_strlen(str) && s->prec < s->champ && !s->zero)
		tmp = tmp_space(&tmp, s, 0);
	while ((s->champ > (int)ft_strlen(str) && s->zero)
		|| s->prec > (int)ft_strlen(str))
		tmp = tmp_zero(&tmp, s, 0);
	str = minus_tmp(&str, &tmp, s);
	return (str);
}

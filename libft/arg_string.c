/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:31:14 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/01/13 17:31:16 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*string(t_mod *s, va_list ap)
{
	char	*str;
	char	*tmp;

	if (s->l)
		return (string_uni(s, ap));
	str = va_arg(ap, char*);
	tmp = NULL;
	if (str == NULL)
		str = "(null)";
	str = ft_strdup(str);
	str = for_string(s, str, tmp);
	return (str);
}

char	*string_uni(t_mod *s, va_list ap)
{
	char	*str;
	char	*tmp;
	int		len;

	str = ft_wconvstr(va_arg(ap, wchar_t*), &len);
	tmp = NULL;
	if (str == NULL)
		str = ft_strdup("(null)");
	while (s->prec > 0 && (s->prec % len) != 0)
		s->prec--;
	str = for_string(s, str, tmp);
	return (str);
}

char	*carac(t_mod *s, va_list ap)
{
	char	*c;
	char	*str;
	char	*tmp;

	if (s->l)
		return (carac_uni(s, ap));
	tmp = NULL;
	c = ft_strnew(1);
	c[0] = va_arg(ap, int);
	str = (char*)c;
	if (!str[0])
	{
		s->null++;
		s->champ--;
		s->prec--;
		tmp = ft_strnew(s->champ);
	}
	str = for_carac(s, str, tmp);
	return (str);
}

char	*carac_uni(t_mod *s, va_list ap)
{
	char	*str;
	char	*tmp;
	int		len;

	tmp = NULL;
	str = ft_wconvchar(va_arg(ap, wchar_t), &len);
	if (!str[0])
	{
		s->null++;
		s->champ--;
		s->prec--;
		tmp = ft_strnew(s->champ);
	}
	str = for_carac(s, str, tmp);
	return (str);
}

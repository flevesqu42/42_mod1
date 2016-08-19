/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed_for_argstr_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 19:37:05 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/03/20 02:13:58 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*for_string(t_mod *s, char *str, char *tmp)
{
	if ((int)ft_strlen(str) > s->prec && s->prec >= 0)
		str = ft_strsub(str, 0, s->prec);
	if ((s->champ - (int)ft_strlen(str)) > 0)
		tmp = ft_strnew(s->champ - (int)ft_strlen(str));
	while (s->champ > (int)ft_strlen(str) && !s->zeroc)
		tmp = tmp_space(&tmp, s, 0);
	while (s->champ > (int)ft_strlen(str) && s->zeroc && !s->minus)
		tmp = tmp_zero(&tmp, s, 0);
	while (s->champ > (int)ft_strlen(str))
		tmp = tmp_space(&tmp, s, 0);
	str = minus_tmp(&str, &tmp, s);
	return (str);
}

long int	dec_a(va_list ap, t_mod *s)
{
	long int a;

	if (s->z)
		a = va_arg(ap, size_t);
	else if (s->j)
		a = va_arg(ap, intmax_t);
	else
		a = va_arg(ap, int);
	if (a < 0)
		s->space = 0;
	if (s->h == 1)
		a = (short int)a;
	if (s->h == 2)
		a = (char)a;
	return (a);
}

static char	*for_dec_three(t_mod *s, char *str, char *tmp, long int a)
{
	char *temp;
	char *temp2;

	while (((s->champ > (int)ft_strlen(str) + s->space && s->zero)
		|| (s->prec > (int)ft_strlen(str))) && !s->minus)
		tmp = tmp_zero(&tmp, s, 0);
	while (s->champ > (int)ft_strlen(str) && s->zeroc && !s->minus)
		tmp = tmp_zero(&tmp, s, 1);
	while (s->champ > (int)ft_strlen(str))
		tmp = tmp_space(&tmp, s, 0);
	temp = tmp;
	temp2 = str;
	if (tmp && !s->minus)
		str = ft_strjoin(tmp, str);
	if (tmp && s->minus)
		str = ft_strjoin(str, tmp);
	free(temp2);
	free(temp);
	if (s->space && a >= 0 && !s->plus && str[0] != ' ')
		str = tmp_space(&str, s, 1);
	if (s->plus && s->minus && a >= 0)
		str = tmp_join(&str, "+", 1, 0);
	return (str);
}

static char	*for_dec_two(t_mod *s, char *str, char *tmp, long int a)
{
	if (s->null)
	{
		str = tmp_join(&str, "-", 1, 0);
		s->null = 0;
	}
	if (s->plus && a >= 0 && !s->minus)
	{
		if (tmp)
			tmp++;
		if (!s->zeroc)
			tmp = tmp_join(&tmp, "+", 0, 1);
		else
			tmp = tmp_join(&tmp, "+", 1, 1);
		s->champ--;
	}
	if (s->plus && a >= 0 && s->minus)
	{
		s->champ--;
		if (tmp)
			tmp = temp_free(&tmp);
	}
	str = for_dec_three(s, str, tmp, a);
	return (str);
}

char		*for_dec(t_mod *s, char *str, long int a)
{
	char *tmp;

	tmp = ft_strdup("");
	while (s->champ > (int)ft_strlen(str) && s->prec < s->champ && !s->zero)
		tmp = tmp_space(&tmp, s, 0);
	if (str[0] == '-' && !s->minus)
	{
		tmp = tmp_join(&tmp, "-", 0, 0);
		str = temp_free(&str);
		s->champ--;
	}
	if (str[0] == '-' && s->minus && s->prec > (int)ft_strlen(str) - 1)
	{
		str = temp_free(&str);
		s->champ--;
		s->null = 1;
	}
	if (s->minus && s->prec > (int)ft_strlen(str))
	{
		while (s->prec > (int)ft_strlen(str))
			str = tmp_zero(&str, s, 1);
	}
	str = for_dec_two(s, str, tmp, a);
	return (str);
}

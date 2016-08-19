/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_bonus_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 03:23:58 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/02/06 15:17:50 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*binaire(t_mod *s, va_list ap)
{
	long long int	a;
	char			*str;

	(void)s;
	a = va_arg(ap, long long);
	str = ft_itoa_base(a, 2, 0);
	return (str);
}

char		*binaire_str(t_mod *s, va_list ap)
{
	char	*str;
	char	*tmp;
	int		i;
	char	*temp;

	(void)s;
	tmp = va_arg(ap, char*);
	i = 0;
	str = ft_strnew(1);
	while (tmp[i])
	{
		temp = ft_itoa_base(tmp[i], 2, 0);
		while (ft_strlen(temp) != 8)
			tmp_zero(&temp, s, 1);
		str = tmp_str_join(&str, temp);
		++i;
	}
	return (str);
}

void		ft_free_colors(char **tmp, int i)
{
	char *temp;

	temp = *tmp;
	*tmp = ft_strdup(*tmp + i);
	free(temp);
}

static void	endcolors(char *temp, t_mod *s)
{
	if (ft_strnstr(temp, "{CRED", 5))
	{
		ft_free_colors(&temp, 5);
		temp = tmp_join(&(temp), RED, 1, 0);
		temp = tmp_join(&temp, WHITE, 0, 0);
		ft_putstr(temp);
		s->len = s->len - 5;
	}
	else if (ft_strnstr(temp, "{CBLUE", 6))
	{
		ft_free_colors(&temp, 6);
		temp = tmp_join(&temp, BLUE, 1, 0);
		temp = tmp_join(&temp, WHITE, 0, 0);
		ft_putstr(temp);
		s->len = s->len - 6;
	}
	else if (ft_strnstr(temp, "{CGREEN", 7))
	{
		ft_free_colors(&temp, 7);
		temp = tmp_join(&temp, GREEN, 1, 0);
		temp = tmp_join(&temp, WHITE, 0, 0);
		ft_putstr(temp);
		s->len = s->len - 7;
	}
	free(temp);
}

int			putcolors(char *final, t_mod *s)
{
	int		i;
	char	*temp;
	int		j;

	i = 0;
	search_for_colors(final, &i);
	if (!final[i] || !ft_strchr(final, '}'))
		return (0);
	temp = ft_strsub(final, 0, i);
	ft_putstr(temp);
	s->len = s->len + i;
	free(temp);
	j = ft_strlen(final) - i - ft_strlen(ft_strchr(final, '}'));
	s->len = s->len + j;
	temp = ft_strsub(final, i, j);
	endcolors(temp, s);
	j = ft_strlen(final) - ft_strlen(ft_strchr(final, '}')) + 1;
	temp = ft_strsub(final, j, ft_strlen(final));
	if (!ft_strchr(temp, '{'))
		print_tmp(temp, s, final, j);
	else
		putcolors(temp, s);
	return (1);
}

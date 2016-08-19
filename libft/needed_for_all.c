/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed_for_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:04:52 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/01/30 15:04:53 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*minus_tmp(char **str, char **tmp, t_mod *s)
{
	char *temp;
	char *str2;

	temp = NULL;
	str2 = NULL;
	if (*tmp && !s->minus)
	{
		temp = *tmp;
		str2 = *str;
		*str = ft_strjoin(temp, str2);
	}
	if (*tmp && s->minus)
	{
		temp = *tmp;
		str2 = *str;
		*str = ft_strjoin(str2, temp);
	}
	free(temp);
	free(str2);
	reset_struck(s);
	return (*str);
}

char	*tmp_zero(char **tmp, t_mod *s, char a)
{
	char *temp;

	temp = NULL;
	temp = *tmp;
	if (!a)
		*tmp = ft_strjoin(*tmp, "0");
	else
		*tmp = ft_strjoin("0", *tmp);
	s->champ--;
	s->prec--;
	if (temp)
		free(temp);
	temp = NULL;
	return (*tmp);
}

char	*tmp_space(char **tmp, t_mod *s, char a)
{
	char *temp;

	temp = NULL;
	temp = *tmp;
	if (!a)
		*tmp = ft_strjoin(temp, " ");
	else
		*tmp = ft_strjoin(" ", temp);
	s->champ--;
	free(temp);
	temp = NULL;
	return (*tmp);
}

char	*tmp_join(char **tmp, char *c, char a, char b)
{
	char *temp;

	temp = NULL;
	temp = *tmp;
	if (!a)
		*tmp = ft_strjoin(temp, c);
	else
		*tmp = ft_strjoin(c, temp);
	if (b)
		temp--;
	if (temp)
		free(temp);
	temp = NULL;
	return (*tmp);
}

char	*tmp_str_join(char **str, char *tmp)
{
	char *temp;
	char *str2;

	temp = tmp;
	str2 = *str;
	*str = ft_strjoin(str2, temp);
	free(temp);
	free(str2);
	return (*str);
}

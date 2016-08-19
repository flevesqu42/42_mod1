/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:02:19 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/04/15 08:47:23 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_fill_tab(char const *s, char c, int col)
{
	int		max;
	int		i;

	i = 0;
	max = 0;
	while (s[i])
	{
		col = 0;
		while (s[i] != c && s[i])
		{
			++i;
			++col;
		}
		if (col > max)
		{
			max = col;
		}
		else
			++i;
	}
	return (max);
}

static char		**ft_make_matrix(char const *s, char c, int j, int i)
{
	int		tab_i[2];
	char	**matrix;

	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				++i;
			if (s[i])
				++j;
		}
		++i;
	}
	tab_i[0] = -ft_fill_tab(s, c, 0);
	matrix = ft_tab_char(j, tab_i);
	if (matrix == NULL)
		return (NULL);
	return (matrix);
}

static char		**ft_fill_matrix(char const *s, char c, char **split, int j)
{
	unsigned int		i;
	size_t				len;
	char				*tmp;

	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			++i;
		if (s[i])
		{
			len = 0;
			while (s[i] != c && s[i])
			{
				++i;
				++len;
			}
			tmp = split[j];
			split[j] = ft_strsub(s, i - len, len);
			free(tmp);
			++j;
		}
	}
	split[j] = NULL;
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;

	if (s == NULL)
		return (NULL);
	split = ft_make_matrix(s, c, 0, 0);
	if (split == NULL)
		return (NULL);
	split = ft_fill_matrix(s, c, split, 0);
	return (split);
}

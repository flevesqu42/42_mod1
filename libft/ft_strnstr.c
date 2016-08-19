/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:57:06 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/11/26 12:20:48 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] && i < n)
	{
		while (s1[i] == s2[j] && s2[j] && i < n)
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char*)s1 + (i - j));
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:30:49 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/02/27 05:29:46 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *s1, char const *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1[i] == '\0' && s2[j] == '\0')
		return ((char*)s1);
	while (s1[i])
	{
		while (s1[i] == s2[j] && s2[j] && s1[i])
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:30:05 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/11/28 13:50:59 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t		i;

	i = 0;
	while (dst[i])
	{
		++i;
		if (i > size)
			return (size + ft_strlen(src));
	}
	while (*src && i < size - 1)
	{
		dst[i] = *src;
		++i;
		src++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}

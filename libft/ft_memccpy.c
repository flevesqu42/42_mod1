/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:32:19 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/12/07 19:46:48 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	size_t			i;

	dest2 = dst;
	src2 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dest2[i] = src2[i];
		if (dest2[i] == (unsigned char)c)
			return (dest2 + i + 1);
		++i;
	}
	return (NULL);
}

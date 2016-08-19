/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:00:54 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/12/10 17:32:57 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	size_t			i;

	dest2 = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return ((void*)dest2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:26:04 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/11/26 20:34:20 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char	*chr;
	size_t			i;

	chr = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (chr[i] == (unsigned char)c)
			return ((void*)chr + i);
		i++;
	}
	return (NULL);
}

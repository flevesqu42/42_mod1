/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:14:17 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/12/07 19:22:59 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t n)
{
	size_t		i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = (unsigned char)src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

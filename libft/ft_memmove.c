/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 21:20:03 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/12/10 17:32:32 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	char *temp;

	temp = ft_strnew(len);
	temp = ft_memcpy(temp, src, len);
	dst = ft_memcpy(dst, temp, len);
	free(temp);
	temp = NULL;
	return (dst);
}

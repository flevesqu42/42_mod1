/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:51:04 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/11/29 19:15:25 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *s1, void const *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	if (n == i)
		return (0);
	while (i < n && str1[i] == str2[i])
		i++;
	if (str1[i - 1] == str2[i - 1] && i == n)
		return (0);
	return (str1[i] - str2[i]);
}

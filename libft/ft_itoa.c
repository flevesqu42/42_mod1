/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 22:23:24 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/11/26 14:43:23 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_transformation(char *itoa, long long n, int size)
{
	int		i;
	int		max;

	max = size + 1;
	i = 0;
	if (n < 0)
	{
		itoa[i] = '-';
		i++;
		n = -n;
	}
	while (n > 9)
	{
		itoa[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	itoa[size] = n + '0';
	itoa[max] = '\0';
	return (itoa);
}

char			*ft_itoa(long long n)
{
	char	*itoa;
	int		size;

	if (n == (-9223372036854775807) - 1)
	{
		itoa = ft_strdup("-9223372036854775808");
		return (itoa);
	}
	size = ft_sizeint(n);
	itoa = ft_strnew(size);
	if (itoa == NULL)
		return (NULL);
	itoa = ft_transformation(itoa, n, size - 1);
	return (itoa);
}

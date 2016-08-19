/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoau.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 22:01:10 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/01/22 22:02:09 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

static char		*ft_transformation(char *itoa, unsigned long long n, int size)
{
	int		i;
	int		max;

	max = size + 1;
	i = 0;
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

char			*ft_itoau(unsigned long long n)
{
	char	*itoa;
	int		size;

	if (n == ULONG_MAX)
		return (ft_strdup("18446744073709551615"));
	size = ft_sizeint(n);
	itoa = ft_strnew(size);
	if (itoa == NULL)
		return (NULL);
	itoa = ft_transformation(itoa, n, size - 1);
	return (itoa);
}

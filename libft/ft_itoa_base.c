/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:56:42 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/01/11 13:56:47 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_transformation(char *itoa, unsigned long long n,
	unsigned long long base, int j)
{
	int i;

	i = 0;
	while (n >= base)
	{
		if ((n % base) <= 9)
			itoa[i] = (n % base) + '0';
		else if (j)
			itoa[i] = ((n % base) - 10) + 'A';
		else
			itoa[i] = ((n % base) - 10) + 'a';
		n = n / base;
		++i;
	}
	if ((n % base) <= 9)
		itoa[i] = (n % base) + '0';
	else if (j)
		itoa[i] = ((n % base) - 10) + 'A';
	else
		itoa[i] = ((n % base) - 10) + 'a';
	itoa = ft_strrev(itoa);
	return (itoa);
}

char		*ft_itoa_base(unsigned long long n, int base, int j)
{
	char *itoa;

	if (n == ULONG_MAX && base == 16 && !j)
		return (ft_strdup("ffffffffffffffff"));
	if (n == ULONG_MAX && base == 16 && j)
		return (ft_strdup("FFFFFFFFFFFFFFFF"));
	if (n == 0)
		return (ft_strdup("0"));
	if (base <= 1)
		return (NULL);
	if (base == 10)
		return (ft_itoa(n));
	if (base > 10)
		itoa = ft_strnew(ft_sizeintu(n));
	else
		itoa = ft_strnew(ft_sizeintu(n) * (10 - base));
	itoa = ft_transformation(itoa, n, base, j);
	return (itoa);
}

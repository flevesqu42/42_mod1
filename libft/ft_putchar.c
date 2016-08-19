/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:16:27 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/01/07 17:21:44 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_seven(unsigned int v, unsigned int d, unsigned int octet)
{
	d = 49280;
	octet = (d >> 8) | ((v >> 6) << 27) >> 27;
	write(1, &(octet), 1);
	octet = ((d << 24) >> 24) | (v << 26) >> 26;
	write(1, &octet, 1);
}

static void	ft_eleven(unsigned int v, unsigned int d, unsigned int octet)
{
	d = 14712960;
	octet = (d >> 16) | ((v >> 12) << 28) >> 28;
	write(1, &(octet), 1);
	octet = ((d << 16) >> 24) | ((v >> 6) << 26) >> 26;
	write(1, &(octet), 1);
	octet = ((d << 24) >> 24) | (v << 26) >> 26;
	write(1, &octet, 1);
}

static void	ft_sixteen(unsigned int v, unsigned int d, unsigned int octet)
{
	d = 4034953344;
	octet = (d >> 24) | ((v >> 18) << 29) >> 29;
	write(1, &(octet), 1);
	octet = (d >> 8) >> 24 | ((v >> 12) << 26) >> 26;
	write(1, &(octet), 1);
	octet = ((d << 16) >> 24) | ((v >> 6) << 26) >> 26;
	write(1, &(octet), 1);
	octet = ((d << 24) >> 24) | (v << 26) >> 26;
	write(1, &octet, 1);
}

static int	count_byte(wchar_t c)
{
	int				i;
	unsigned int	v;

	v = c;
	i = 0;
	while (v > 0)
	{
		v >>= 1;
		++i;
	}
	return (i);
}

void		ft_putchar(wchar_t c)
{
	unsigned int	v;
	int				i;
	unsigned char	octet;
	unsigned int	d;

	v = c;
	octet = 0;
	d = 0;
	i = count_byte(c);
	if (i > 16)
		ft_sixteen(v, 0, octet);
	if (i > 11 && i <= 16)
		ft_eleven(v, 0, octet);
	if (i > 7 && i <= 11)
		ft_seven(v, 0, octet);
	if (i <= 7)
	{
		octet = v;
		write(1, &octet, 1);
	}
}

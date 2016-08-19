/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wconvchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:37:05 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/01/13 16:37:10 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_seven(unsigned int v, int *len, unsigned int o, char *s)
{
	unsigned int d;

	d = 49280;
	o = (d >> 8) | ((v >> 6) << 27) >> 27;
	s[0] = o;
	o = ((d << 24) >> 24) | (v << 26) >> 26;
	s[1] = o;
	*len = 2;
}

static void	ft_eleven(unsigned int v, int *len, unsigned int o, char *s)
{
	unsigned int d;

	d = 14712960;
	o = (d >> 16) | ((v >> 12) << 28) >> 28;
	s[0] = o;
	o = ((d << 16) >> 24) | ((v >> 6) << 26) >> 26;
	s[1] = o;
	o = ((d << 24) >> 24) | (v << 26) >> 26;
	s[2] = o;
	*len = 3;
}

static void	ft_sixteen(unsigned int v, int *len, unsigned int o, char *s)
{
	unsigned int d;

	d = 4034953344;
	o = (d >> 24) | ((v >> 18) << 29) >> 29;
	s[0] = o;
	o = (d >> 8) >> 24 | ((v >> 12) << 26) >> 26;
	s[1] = o;
	o = ((d << 16) >> 24) | ((v >> 6) << 26) >> 26;
	s[2] = o;
	o = ((d << 24) >> 24) | (v << 26) >> 26;
	s[3] = o;
	*len = 4;
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

char		*ft_wconvchar(wchar_t wc, int *len)
{
	unsigned int	v;
	int				i;
	unsigned char	octet;
	char			*str;

	str = ft_strnew(4);
	v = wc;
	octet = 0;
	i = count_byte(wc);
	if (i > 16)
		ft_sixteen(v, len, octet, str);
	if (i > 11 && i <= 16)
		ft_eleven(v, len, octet, str);
	if (i > 7 && i <= 11)
		ft_seven(v, len, octet, str);
	if (i <= 7)
	{
		str[0] = v;
		*len = 1;
	}
	return (str);
}

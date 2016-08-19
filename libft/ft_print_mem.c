/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:53:28 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/01/11 16:53:30 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_print_mem(void *adress)
{
	unsigned long	i;
	char			*tmp;
	char			*mem;
	int				j;

	i = (unsigned long)adress;
	tmp = ft_itoa_base(i, 16, 0);
	mem = ft_strnew(ft_strlen(tmp) + 2);
	mem[0] = '0';
	mem[1] = 'x';
	i = 2;
	j = 0;
	while (tmp[j])
	{
		mem[i] = tmp[j];
		++i;
		++j;
	}
	free(tmp);
	return (mem);
}

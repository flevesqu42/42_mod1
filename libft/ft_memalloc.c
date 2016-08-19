/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:45:51 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/03/22 07:07:17 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size + 1);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, size + 1);
	return (mem);
}

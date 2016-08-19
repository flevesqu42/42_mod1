/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:40:26 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/12/10 17:33:21 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == i)
		return (0);
	if (s2[i] == '\0' && s1[i])
		return (1);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	if (s1[i] || s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}

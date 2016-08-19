/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:27:02 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/11/28 23:38:34 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	int		i;
	int		j;
	int		len;

	trim = ft_strnew(ft_strlen(s));
	len = ft_strlen(s) - 1;
	if (trim == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && len >= 0)
		len--;
	while (s[i] && i <= len)
	{
		trim[j] = s[i];
		j++;
		i++;
	}
	return (trim);
}

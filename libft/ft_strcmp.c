/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:04:16 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/12/10 17:31:55 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (s2[i] == '\0' && s1[i])
		return (1);
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] || s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}

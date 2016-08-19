/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:24:02 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/11/26 22:27:26 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_atoi(char const *str)
{
	long long int	i;
	long long int	nbr;
	long long int	sign;

	sign = 1;
	i = 0;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

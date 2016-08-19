/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_rangers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 10:44:46 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/04/14 11:55:06 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static void		first_rangers(t_gen *g, char *scream, int i)
{
	char	b;
	int		index;

	index = 0;
	b = 0;
	g->r = i;
	while (b < g->rang.nb && scream[(int)b] == 2)
		b += 1;
	if (b == g->rang.nb)
		g->rang.nb = -1;
	if (i == 0)
	{
		while (index < Y * g->w->size_line)
		{
			if (index % 4 == 3)
				g->rang.data[index] = 0xFF;
			else
				g->rang.data[index] = 0x0;
			index += 1;
		}
	}
}

static int		second_rangers(t_gen *g, float *z, char *scream, int i)
{
	char c;

	if (!(c = 0) && scream[i])
	{
		if (*z > 25 || scream[i] == 2)
		{
			scream[i] = 2;
			return (-1);
		}
		return ((int)*z - 5.5);
	}
	else if (*z > 4.5)
	{
		c = *z - 5.5;
		if (*z > 20 && !scream[i])
		{
			scream[i] = 1;
			(i == 0 || i == 1 || i == 2) ? enable_shoot(g, 2)
			: enable_shoot(g, 3);
		}
		else
			*z = 4.5;
	}
	return (c);
}

void			power_rangers(t_gen *g, int i, char c, float z)
{
	static char	scream[5] = {0, 0, 0, 0, 0};
	char		b[2];

	first_rangers(g, scream, i);
	if ((b[0] = second_rangers(g, &z, scream, i)) == -1)
		return ;
	c = (b[0] > 14) ? 1 : c;
	power(g, 2, -16 - b[0], (z > 3) ? 200 : 0);
	power(g, 2, -14 - b[0], (z > 2) ? 200 : 0);
	power(g, 2, -12 - b[0], (z > 2) ? 200 : 0);
	power(g, 2, -10 - b[0], (z > 1) ? 200 : 0);
	power(g, -2, -16 - b[0], (z > 3) ? 200 : 0);
	power(g, -2, -14 - b[0], (z > 2) ? 200 : 0);
	power(g, -2, -12 - b[0], (z > 2) ? 200 : 0);
	power(g, -2, -10 - b[0], (z > 1) ? 200 : 0);
	power(g, 2, -24 - b[0], (z > 4.5) ? 200 : 0);
	power(g, 4, -24 - b[0], (z > 4.5) ? 200 : 0);
	power(g, 5, ((c) ? -26 : -24) - b[0], (z > 5) ? 200 : 0);
	power(g, -2, -24 - b[0], (z > 4.5) ? 200 : 0);
	power(g, -4, -24 - b[0], (z > 4.5) ? 200 : 0);
	power(g, -5, ((c) ? -24 : -26) - b[0], (z > 5) ? 200 : 0);
	c = 0;
	b[1] = 3;
	while ((c += 2) < 14)
		power(g, 0, -16 - b[0] - c, (z > (b[1] += c / 10)) ? 200 : 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watermove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:35:08 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/04/14 15:57:20 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static int		watermove_condition(t_gen *g, int x, int y, int *d)
{
	float	tmp;

	tmp = g->w->tab[y + d[1]][x + d[0]] + g->t->tab[y + d[1]][x + d[0]];
	if (g->w->tab[y][x] + g->t->tab[y][x] > tmp
			&& (((d[1] == -1 && d[0] == 0) || y == 0)
				|| (tmp <= g->w->tab[y - 1][x] + g->t->tab[y - 1][x]))
			&& (((d[1] == +1 && d[0] == 0) || y == 299)
				|| (tmp <= g->w->tab[y + 1][x] + g->t->tab[y + 1][x]))
			&& (((d[1] == -1 && d[0] == -1) || y == 0 || x == 0)
				|| (tmp <= g->w->tab[y - 1][x - 1] + g->t->tab[y - 1][x - 1]))
			&& (((d[1] == +1 && d[0] == -1) || y == 299 || x == 0)
				|| (tmp <= g->w->tab[y + 1][x - 1] + g->t->tab[y + 1][x - 1]))
			&& (((d[1] == +1 && d[0] == +1) || y == 299 || x == 299)
				|| (tmp <= g->w->tab[y + 1][x + 1] + g->t->tab[y + 1][x + 1]))
			&& (((d[1] == -1 && d[0] == +1) || y == 0 || x == 299)
				|| (tmp <= g->w->tab[y - 1][x + 1] + g->t->tab[y - 1][x + 1]))
			&& (((d[1] == 0 && d[0] == +1) || x == 299)
				|| (tmp <= g->w->tab[y][x + 1] + g->t->tab[y][x + 1]))
			&& (((d[1] == 0 && d[0] == -1) || x == 0)
				|| (tmp <= g->w->tab[y][x - 1] + g->t->tab[y][x - 1])))
		return (1);
	return (0);
}

static int		watermove_bis(t_gen *g, int x, int y, int *d)
{
	if (!(g->w->tab[y][x] > 0) || (d[0] == -1 && x == 0)
			|| (d[0] == +1 && x == 299) || (d[1] == -1 && y == 0)
			|| (d[1] == +1 && y == 299))
		return (0);
	if (watermove_condition(g, x, y, d))
	{
		if (g->w->tab[y][x] >= 1.0)
		{
			g->w->tab[y][x] -= 1.0;
			g->w->tab[y + d[1]][x + d[0]] += 1.0;
		}
		else
		{
			g->w->tab[y][x] -= 0.1;
			g->w->tab[y + d[1]][x + d[0]] += 0.1;
		}
		return (1);
	}
	return (0);
}

void			watermove_mid(t_gen *g, int x, int y, int *d)
{
	d[0] = -1;
	d[1] = 1;
	watermove_bis(g, 299 - x, 299 - y, d);
	d[0] = 0;
	d[1] = -1;
	watermove_bis(g, x, y, d);
	d[1] = 1;
	watermove_bis(g, 299 - x, 299 - y, d);
	d[0] = 1;
	watermove_bis(g, x, y, d);
	d[0] = -1;
	d[1] = -1;
	watermove_bis(g, 299 - x, 299 - y, d);
	d[0] = 1;
	d[1] = 0;
	watermove_bis(g, x, y, d);
	d[0] = -1;
	watermove_bis(g, 299 - x, 299 - y, d);
	d[1] = 1;
	watermove_bis(g, x, y, d);
	d[0] = 1;
	d[1] = -1;
	watermove_bis(g, 299 - x, 299 - y, d);
	d[0] = -1;
	d[1] = 0;
}

void			watermove(t_gen *g)
{
	int		x;
	int		y;
	int		d[2];

	y = -1;
	while (++y < 300 && (x = -1))
		while (++x < 300 && (d[0] = -1))
		{
			d[1] = -1;
			watermove_bis(g, x, y, d);
			d[0] = 1;
			d[1] = 1;
			watermove_bis(g, 299 - x, 299 - y, d);
			d[1] = -1;
			watermove_bis(g, x, y, d);
			watermove_mid(g, x, y, d);
			watermove_bis(g, x, y, d);
			d[0] = 1;
			watermove_bis(g, 299 - x, 299 - y, d);
			d[0] = 0;
			d[1] = 1;
			watermove_bis(g, x, y, d);
			d[1] = -1;
			watermove_bis(g, 299 - x, 299 - y, d);
		}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   water_cooldown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 18:02:17 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/04/15 18:05:18 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static int		water_cooldown_first(t_thread *p, int *i)
{
	if (p->g->rep & 0x1)
		p->g->w->tab[i[3]][i[2]] += 0.1;
	if (p->g->rep & 0x200 && p->g->w->tab[i[3]][i[2]]
		+ p->g->t->tab[i[3]][i[2]] <= p->g->min_w)
		p->g->w->tab[i[3]][i[2]] = p->g->min_w - p->g->t->tab[i[3]][i[2]];
	if (p->g->rep & 0x8 && p->g->w->tab[i[3]][i[2]] >= 0.5
			&& (i[3] == 0 || i[3] == 299 || i[2] == 0 || i[2] == 299))
		p->g->w->tab[i[3]][i[2]] -= p->g->w->tab[i[3]][i[2]] >= 3.0
		? 3.0 : 0.5;
	if (p->g->rep & 0x40 && p->g->w->tab[i[3]][i[2]] >= 0.5)
		p->g->w->tab[i[3]][i[2]] -= 0.5;
	if (p->g->rep & 0x02 && abs(p->g->test[0]) < i[3] + 5
		&& abs(p->g->test[0]) > i[3] - 5)
	{
		p->g->wave[0][i[2]] += p->g->w->tab[i[3]][i[2]] > 0 ? 0
			: p->g->t->tab[i[3]][i[2]] / 1000;
		if (p->g->wave[0][i[2]] < 1.0)
			p->g->w->tab[i[3]][i[2]] += 1.0 - p->g->wave[0][i[2]];
		return (1);
	}
	return (0);
}

static int		water_cooldown_second(t_thread *p, int *i)
{
	if (p->g->rep & 0x04 && abs(p->g->test[1]) < i[2] + 5
			&& abs(p->g->test[1]) > i[2] - 5)
	{
		p->g->wave[1][i[3]] += p->g->w->tab[i[3]][i[2]] > 0 ? 0
			: p->g->t->tab[i[3]][i[2]] / 1000;
		if (p->g->wave[1][i[3]] < 1.0)
			p->g->w->tab[i[3]][i[2]] += 1.0 - p->g->wave[1][i[3]];
		return (1);
	}
	else if (p->g->rep & 0x10 && abs(p->g->test[2]) < i[3] + 5
			&& abs(p->g->test[2]) > i[3] - 5)
	{
		p->g->wave[2][i[2]] += p->g->w->tab[i[3]][i[2]] > 0 ? 0
			: p->g->t->tab[i[3]][i[2]] / 1000;
		if (p->g->wave[2][i[2]] < 1.0)
			p->g->w->tab[i[3]][i[2]] += 1.0 - p->g->wave[2][i[2]];
		return (1);
	}
	return (0);
}

void			*water_cooldown(void *d)
{
	int			i[4];
	t_thread	*p;

	p = (t_thread*)d;
	i[0] = p->lim[0];
	i[1] = p->lim[1];
	i[2] = p->lim[2];
	while (--i[2] >= i[0])
	{
		i[3] = p->lim[3];
		while (--i[3] >= i[1])
			if (!water_cooldown_first(p, i) && !water_cooldown_second(p, i))
			{
				if (p->g->rep & 0x20 && abs(p->g->test[3]) < i[2] + 5
					&& abs(p->g->test[3]) > i[2] - 5)
				{
					p->g->wave[3][i[3]] += p->g->w->tab[i[3]][i[2]] > 0 ? 0
						: p->g->t->tab[i[3]][i[2]] / 1000;
					if (p->g->wave[3][i[3]] < 1.0)
						p->g->w->tab[i[3]][i[2]] += 1.0 - p->g->wave[3][i[3]];
				}
			}
	}
	return (NULL);
}

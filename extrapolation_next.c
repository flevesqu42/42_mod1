/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrapolation_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 11:57:59 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/04/15 19:30:28 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

t_tab		*init_tab(t_gen *g)
{
	t_tab	*w;
	int		i;

	i = -1;
	if (!(w = (t_tab*)malloc(sizeof(t_tab))))
		error(3);
	if (!(w->tab = (float**)ft_memalloc(sizeof(float*) * 300)))
		error(3);
	while (++i < 300)
		if (!(w->tab[i] = (float*)ft_memalloc(sizeof(float) * 300)))
			error(3);
	if (!(w->img = mlx_new_image(g->mlx, X, Y)))
		error(4);
	w->data = mlx_get_data_addr(w->img, &w->bpp, &w->size_line
			, &w->endian);
	return (w);
}

void		set_transparency(t_gen *gen)
{
	int	index;

	index = 0;
	while (index < Y * gen->w->size_line)
	{
		if (index % 4 == 3)
			gen->w->data[index] = 0xFF;
		else
			gen->w->data[index] = 0x0;
		index += 1;
	}
	if (gen->w->tab[299][299] > gen->min_w)
		gen->min_w = gen->w->tab[299][299];
	if (gen->w->tab[299][0] > gen->min_w)
		gen->min_w = gen->w->tab[299][0];
	if (gen->w->tab[0][299] > gen->min_w)
		gen->min_w = gen->w->tab[0][299];
	if (gen->w->tab[0][0] > gen->min_w)
		gen->min_w = gen->w->tab[0][0];
}

int			set_max(t_gen *gen, t_hill *c)
{
	t_hill	*act;
	int		max;
	float	sq;

	max = 300;
	act = gen->list;
	while (act)
	{
		if (act != c)
		{
			sq = sqrt(((c->y - act->y) * (c->y - act->y))
				+ ((c->x - act->x) * (c->x - act->x)));
			if ((int)sq < max)
				max = (int)sq;
		}
		act = act->next;
	}
	return (max);
}

void		set_rec_2(t_gen *gen, int y, int x, t_hill *c)
{
	float t;
	float diff_x;
	float diff_y;
	float result;

	diff_y = c->y - y;
	diff_x = c->x - x;
	t = sqrt(diff_x * diff_x + diff_y * diff_y);
	if (t > c->max_z)
		return ;
	result = c->z + (t / 4) * c->max_z * ((cos((M_PI * t / c->max_z)
					+ M_PI) + 1) / 2);
	if (result > 150 || !(x < 300 && y < 300 && x >= 0 && y >= 0
				&& result < gen->t->tab[y][x]))
		return ;
	gen->t->tab[y][x] = result;
	set_rec_2(gen, y - 1, x, c);
	set_rec_2(gen, y + 1, x, c);
	set_rec_2(gen, y, x + 1, c);
	set_rec_2(gen, y, x - 1, c);
}

void		sleepy_hollow(t_gen *gen)
{
	t_hill	*c;

	c = gen->list;
	while (c)
	{
		c->max_z = set_max(gen, c);
		if (gen->t->tab[c->y][c->x] != c->z)
			set_rec_2(gen, c->y, c->x, c);
		c = c->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrapolation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 14:56:40 by flevesqu          #+#    #+#             */
/*   Updated: 2016/04/14 11:59:35 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static void	set_max_xyz(t_hill *c, t_gen *gen)
{
	if (c->z * 2 > gen->max_x)
		gen->max_x = c->z * 2;
	if (c->z * 2 > gen->max_y)
		gen->max_y = c->z * 2;
	if (c->x + (c->z) > gen->max_x)
		gen->max_x = c->x + (c->z);
	if (c->y + (c->z) > gen->max_y)
		gen->max_y = c->y + (c->z);
}

static void	check_same_xy(t_gen *gen)
{
	t_hill	*c;
	t_hill	*check;

	gen->max_y = 0;
	gen->max_x = 0;
	c = gen->list;
	while (c)
	{
		set_max_xyz(c, gen);
		check = gen->list;
		while (check)
		{
			if (check != c && check->x == c->x && check->y == c->y)
				error(9);
			check = check->next;
		}
		c = c->next;
	}
}

void		set_rec(t_gen *gen, int y, int x, t_hill *c)
{
	float t;
	float diff_x;
	float diff_y;
	float result;

	diff_y = c->y - y;
	diff_x = c->x - x;
	t = sqrt(diff_x * diff_x + diff_y * diff_y);
	if (t > c->z)
		return ;
	result = c->z * ((cos(M_PI * t / c->z) + 1) / 2);
	if (!(x < 300 && y < 300 && x >= 0 && y >= 0
				&& (result > gen->t->tab[y][x])))
		return ;
	gen->t->tab[y][x] = result;
	set_rec(gen, y - 1, x, c);
	set_rec(gen, y + 1, x, c);
	set_rec(gen, y, x + 1, c);
	set_rec(gen, y, x - 1, c);
}

void		set_hills(t_gen *gen)
{
	t_hill	*c;

	c = gen->list;
	while (c)
	{
		if (c->y == gen->max_y)
			c->y *= 2;
		else
			c->y = c->y > c->z ? (c->y) / gen->ratio
				: c->z / gen->ratio;
		if (c->x == gen->max_x)
			c->x *= 2;
		else
			c->x = c->x > c->z ? c->x / gen->ratio
				: c->z / gen->ratio;
		c->z = c->z / gen->ratio;
		set_rec(gen, c->y, c->x, c);
		c = c->next;
	}
}

void		extrapolation(t_gen *gen)
{
	size_t	i;

	i = -1;
	if (!gen->list)
		error(8);
	check_same_xy(gen);
	gen->ratio = gen->max_y > gen->max_x ? ((float)gen->max_y) / 300
		: ((float)gen->max_x) / 300;
	if (!gen->ratio)
		gen->ratio = 1;
	gen->t = init_tab(gen);
	set_hills(gen);
	sleepy_hollow(gen);
}

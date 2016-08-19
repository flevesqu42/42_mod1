/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 14:28:05 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/04/14 14:31:00 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static t_xy		display_plan_second(t_gen *g, int x, int y, int i)
{
	t_xy	co;

	if (i == 2)
	{
		co.sx = define_x(x, y + 1);
		co.sy = define_y(g->t, x, y + 1);
		co.dx = define_x(x + 1, y);
		co.dy = define_y(g->t, x + 1, y);
		return (co);
	}
	co.sx = define_x(x, y);
	co.sy = define_y(g->t, x, y);
	co.dx = define_x(x + 1, y + 1);
	co.dy = define_y(g->t, x + 1, y + 1);
	return (co);
}

void			display_plan(t_gen *g, int x, int y, int (*f)(float, t_gen*))
{
	t_xy	co;

	co = display_plan_second(g, x, y, 0);
	trace_line(g, co, (f)(g->t->tab[y][x], g), (y < 299 && x < 299
				? (f)(g->t->tab[y + 1][x + 1], g) : (f)(g->t->tab[y][x], g)));
	co.sx = define_x(x, y) + 1;
	co.dx = define_x(x + 1, y + 1) + 1;
	trace_line(g, co, (f)(g->t->tab[y][x], g), (y < 299 && x < 299
				? (f)(g->t->tab[y + 1][x + 1], g) : (f)(g->t->tab[y][x], g)));
	co = display_plan_second(g, x, y, 2);
	trace_line(g, co, y < 299 ? (f)(g->t->tab[y + 1][x], g) :
		(f)(g->t->tab[y][x], g), (x < 299 ? (f)(g->t->tab[y][x + 1], g)
			: (f)(g->t->tab[y][x], g)));
	co.sx = define_x(x, y);
	co.sy = define_y(g->t, x, y);
	co.dx = define_x(x + 1, y);
	co.dy = define_y(g->t, x + 1, y);
	trace_line(g, co, (f)(g->t->tab[y][x], g), (x < 299
				? (f)(g->t->tab[y][x + 1], g) : (f)(g->t->tab[y][x], g)));
	co.dx = define_x(x, y + 1);
	co.dy = define_y(g->t, x, y + 1);
	trace_line(g, co, (f)(g->t->tab[y][x], g), (y < 299
				? (f)(g->t->tab[y + 1][x], g) : (f)(g->t->tab[y][x], g)));
}

void			aff_graph(t_gen *gen)
{
	int	x;
	int y;

	y = -1;
	while (++y < 300 && (x = -1))
		while (++x < 300)
			display_plan(gen, x, y, &color);
}

static int		first_call(t_gen *g)
{
	t_hill	*tmp;
	int		max;

	max = -1;
	tmp = g->list;
	while (tmp)
	{
		if (tmp->z > max)
			max = tmp->z;
		tmp = tmp->next;
	}
	g->rang.nb = -1;
	if (max < 50)
		return (1);
	return (0);
}

void			calling_rangers(t_gen *g)
{
	int		i;
	t_hill	*tmp;

	i = 0;
	if (first_call(g))
		return ;
	tmp = g->list;
	while (tmp)
	{
		if (i < 5 && tmp->z > 40)
		{
			g->rang.nb = i + 1;
			if (i == 0)
			{
				if (!(g->rang.img = mlx_new_image(g->mlx, X, Y)))
					error(4);
				g->rang.data = mlx_get_data_addr(g->rang.img, &g->rang.bpp,
					&g->rang.size_line, &g->rang.endian);
			}
			g->rang.x[i] = tmp->x;
			g->rang.y[i] = tmp->y;
			++i;
		}
		tmp = tmp->next;
	}
}

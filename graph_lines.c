/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 14:31:27 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/04/14 14:32:27 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

float			define_x(float x, float y)
{
	return (X / 2 - ((150 - x + (y - 150)) * 1.8));
}

float			define_y(t_tab *t, float x, float y)
{
	if (x >= 300)
		x = 299;
	if (y >= 300)
		y = 299;
	return (Y / 2 - ((150 - y - (x - 150)) + (t->tab[(int)y][(int)x]) * 1.8));
}

static float	init_rep(float diff_x, float diff_y)
{
	float	rep;

	rep = 0;
	if ((diff_x < 0 ? -diff_x : diff_x) < (diff_y < 0 ? -diff_y : diff_y))
		rep = (diff_y / diff_x) / 2;
	else if ((diff_y < 0 ? -diff_y : diff_y) < (diff_x < 0 ? -diff_x : diff_x))
		rep = (diff_x / diff_y) / 2;
	return (rep);
}

static void		trace_line_bis(float diff_a, float diff_b, float *mod
		, float *rep)
{
	if ((diff_a < 0 ? -diff_a : diff_a) < (diff_b < 0 ? -diff_b : diff_b))
		*rep += diff_b / diff_a;
	if (*mod < diff_a)
		*mod += 1;
	else if (*mod > diff_a)
		*mod -= 1;
}

void			trace_line(t_gen *g, t_xy co, size_t color1, size_t color2)
{
	float	x;
	float	y;
	float	rep;
	float	diff_y;
	float	diff_x;

	x = 0;
	y = 0;
	diff_y = (float)(co.sy - co.dy);
	diff_x = (float)(co.sx - co.dx);
	rep = init_rep(diff_x, diff_y);
	while (x != diff_x || y != diff_y)
	{
		img_pixel_put(g, co.sx - x, co.sy - y, fabs(y) + fabs(x)
				< (fabs(diff_y) + fabs(diff_x)) / 2 ? color1 : color2);
		if (((diff_x < 0 ? -diff_x : diff_x) >= (diff_y < 0 ? -diff_y : diff_y))
				|| (y < 0 ? -y : y) >= (rep < 0 ? -rep : rep))
			trace_line_bis(diff_x, diff_y, &x, &rep);
		if (((diff_y < 0 ? -diff_y : diff_y) >= (diff_x < 0 ? -diff_x : diff_x))
				|| (x < 0 ? -x : x) >= (rep < 0 ? -rep : rep))
			trace_line_bis(diff_y, diff_x, &y, &rep);
	}
	img_pixel_put(g, co.dx, co.dy, color2);
}

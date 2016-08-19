/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_rangers_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 11:23:17 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/04/14 14:32:51 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static int	rangers_colors(t_gen *g)
{
	if (g->r == 0)
		return (0x0000FF00);
	if (g->r == 1)
		return (0xFF000000);
	if (g->r == 2)
		return (0x00FF0000);
	if (g->r == 3)
		return (0x00FFFF00);
	return (0xFF00FF00);
}

static int	rangers_attributes(t_gen *g, int x, int y)
{
	int dx;
	int dy;

	dx = define_x(g->rang.x[(int)g->r], g->rang.y[(int)g->r]) + x;
	dy = define_y(g->t, g->rang.x[(int)g->r], g->rang.y[(int)g->r]) + y;
	return (dy * g->t->size_line + dx * (g->t->bpp / 8));
}

static void	power_reinforcement(t_gen *g, int index, int paste, int paste_s)
{
	g->rang.data[paste] = g->rang.data[index];
	g->rang.data[paste + 1] = g->rang.data[index + 1];
	g->rang.data[paste + 2] = g->rang.data[index + 2];
	g->rang.data[paste + 3] = g->rang.data[index + 3];
	g->rang.data[paste_s - 4] = g->rang.data[index];
	g->rang.data[paste_s - 3] = g->rang.data[index + 1];
	g->rang.data[paste_s - 2] = g->rang.data[index + 2];
	g->rang.data[paste_s - 1] = g->rang.data[index + 3];
}

void		power_inforcement(t_gen *g, int index, int paste, int paste_s)
{
	g->w->data[paste] = g->w->data[index];
	g->w->data[paste + 1] = g->w->data[index + 1];
	g->w->data[paste + 2] = g->w->data[index + 2];
	g->w->data[paste + 3] = g->w->data[index + 3];
	g->w->data[paste_s - 4] = g->w->data[index];
	g->w->data[paste_s - 3] = g->w->data[index + 1];
	g->w->data[paste_s - 2] = g->w->data[index + 2];
	g->w->data[paste_s - 1] = g->w->data[index + 3];
}

void		power(t_gen *g, int x, int y, char z)
{
	int index;
	int color;

	index = rangers_attributes(g, x, y);
	color = rangers_colors(g);
	g->rang.data[index] = color >> 24;
	g->rang.data[index + 1] = color >> 16;
	g->rang.data[index + 2] = color >> 8;
	g->rang.data[index + 3] = z;
	power_reinforcement(g, index, index + 4, index);
	power_reinforcement(g, index, index - g->rang.size_line,
		index - g->rang.size_line);
	power_reinforcement(g, index, index + g->rang.size_line,
		index + g->rang.size_line);
	power_reinforcement(g, index, index + g->rang.size_line + 4,
		index + g->rang.size_line + 4);
	power_reinforcement(g, index, index - g->rang.size_line + 4,
		index - g->rang.size_line + 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:12:51 by flevesqu          #+#    #+#             */
/*   Updated: 2016/04/15 17:11:08 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void			img_two_pixel_put(t_gen *g, int x, int y, size_t color)
{
	int	index;

	if (y >= Y || x >= X || x < 0 || y < 0)
		return ;
	index = (y * g->w->size_line) + x * (g->w->bpp / 8);
	g->w->data[index + 3] = (color & 0xFF000000) >> 24;
	g->w->data[index + 2] = (color & 0x00FF0000) >> 16;
	g->w->data[index + 1] = (color & 0x0000FF00) >> 8;
	g->w->data[index] = color & 0x000000FF;
	if (!(g->rep & 0x800))
		return ;
	power_inforcement(g, index, index + 4, index);
	power_inforcement(g, index, index - g->w->size_line,
		index - g->w->size_line);
	power_inforcement(g, index, index + g->w->size_line,
		index + g->w->size_line);
	power_inforcement(g, index, index + g->w->size_line + 4,
		index + g->w->size_line + 4);
	power_inforcement(g, index, index - g->w->size_line + 4,
		index - g->w->size_line + 4);
}

int				color(float z, t_gen *g)
{
	g->tmp = z;
	if (g->rep & 0x2000)
		return (ft_colors_mag(((z * 6))));
	if (g->rep & 0x1000)
		return (ft_colors_ice(((z * 6))));
	return (ft_colors_earth(((z * 6))));
}

void			img_pixel_put(t_gen *g, int x, int y, size_t color)
{
	size_t	index;

	if (y >= Y - 1 || x >= X - 1 || x < 0 || y < 0)
		return ;
	index = (y * g->t->size_line) + x * (g->t->bpp / 8);
	g->t->data[index + 3] = (color & 0xFF000000) >> 24;
	g->t->data[index + 2] = (color & 0x00FF0000) >> 16;
	g->t->data[index + 1] = (color & 0x0000FF00) >> 8;
	g->t->data[index] = color & 0x000000FF;
	g->d_cmp[index] = (int)(g->tmp / 2);
	g->d_cmp[index + 1] = (int)(g->tmp / 2);
	g->d_cmp[index + 2] = (int)(g->tmp / 2);
	g->d_cmp[index + 3] = (int)(g->tmp / 2);
}

void			enter_mod1(t_gen *gen)
{
	gen->w = init_tab(gen);
	if (!(gen->d_cmp = (char*)ft_memalloc(sizeof(char)
		* Y * gen->t->size_line)))
		error(3);
	aff_graph(gen);
	gen->m = NULL;
	gen->min_w = 1;
	calling_rangers(gen);
	mlx_put_image_to_window(gen->mlx, gen->win, gen->t->img, 0, 0);
	if (!(gen->rep & 0x80))
		mlx_loop_hook(gen->mlx, watermaker, gen);
	free(gen->m);
}

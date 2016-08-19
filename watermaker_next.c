/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watermaker_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:33:05 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/04/15 19:30:44 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static int	cmp_data(int x, int y, t_gen *g, float z)
{
	int index;

	index = (y * g->t->size_line) + x * (g->t->bpp / 8);
	if (g->d_cmp[index] * 2 >= z)
		return (0);
	return (1);
}

void		init_thread(t_thread *t, t_gen *gen)
{
	int i;
	int j;

	i = 0;
	j = 300 / sqrt(MT);
	while (i < MT)
	{
		t[i].nb = i;
		t[i].lim[0] = i % (int)sqrt(MT) * j;
		t[i].lim[1] = (int)(i / sqrt(MT)) * j;
		t[i].lim[2] = i % (int)sqrt(MT) * j + j;
		t[i].lim[3] = (int)(i / sqrt(MT)) * j + j;
		t[i].g = gen;
		++i;
	}
}

static void	put_tab_bis(size_t *t, t_thread *z)
{
	int			index;

	if (z->g->w->tab[t[1]][t[0]] >= 1.0 && cmp_data(define_x(t[0], t[1]),
			define_y(z->g->t, t[0], t[1]) - (z->g->w->tab[t[1]][t[0]])
			* 1.8, z->g,
			z->g->w->tab[t[1]][t[0]] + z->g->t->tab[t[1]][t[0]]))
		img_two_pixel_put(z->g, define_x(t[0], t[1]),
			define_y(z->g->w, t[0], t[1]) - z->g->t->tab[t[1]][t[0]] * 1.8
				, ft_colors_wat((z->g->w->tab[t[1]][t[0]]) * 6));
	if ((t[0] == 299 || t[1] == 299) && (index = z->g->w->tab[t[1]][t[0]]))
		while (--index)
			img_two_pixel_put(z->g, define_x(t[0], t[1])
					, define_y(z->g->w, t[0], t[1]) + (index * 1.8)
					, ft_colors_wat(((z->g->w->tab[t[1]][t[0]]) * 6)));
}

static void	put_tab_next(size_t *t, t_thread *z)
{
	float		w;

	while (t[0] < t[2])
	{
		if (z->g->rep & 0x1 && !(t[0] % 7) && !(t[1] % 7)
			&& (w = (z->g->w->tab[t[1]][t[0]] -
			(int)z->g->w->tab[t[1]][t[0]])) > 0.0 && w < 1)
		{
			img_two_pixel_put(z->g, define_x(t[1], t[0]) + (cos(t[1]) * 5),
				define_y(z->g->w, t[1], t[0]) - (z->g->t->tab[t[1]][t[0]] * 1.8)
				- (-fabs((cos(t[0] * t[1])) - w) * 400) - 800
					, ft_colors_wat((z->g->w->tab[t[1]][t[0]]) * 6));
		}
		put_tab_bis(t, z);
		t[0]++;
	}
}

void		*put_tab(void *p)
{
	t_thread	*z;
	size_t		t[4];

	z = (t_thread*)(p);
	t[2] = z->lim[2];
	t[3] = z->lim[3];
	t[1] = z->lim[1];
	while (t[1] < t[3])
	{
		t[0] = z->lim[0];
		put_tab_next(t, z);
		t[1]++;
	}
	return (NULL);
}

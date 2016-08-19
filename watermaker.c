/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watermaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 06:41:48 by flevesqu          #+#    #+#             */
/*   Updated: 2016/04/15 19:55:54 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static void		watermaker_thread(t_gen *g)
{
	pthread_t	p[MT];
	int			j;
	int			i;

	if (g->rep & 0x48)
		g->min_w -= 0.5;
	else if ((g->rep & 0x200))
		g->min_w += 0.5;
	else if ((g->rep & 0x23e) == 0x200 && g->w->tab[0][0] != g->min_w)
		g->min_w = g->w->tab[0][0];
	i = -1;
	while (++i < MT)
		pthread_create(&p[i], NULL, water_cooldown, &g->m[i]);
	j = -1;
	while (++j < MT)
		pthread_join(p[j], NULL);
	i = -1;
	watermove(g);
	while (++i < MT)
		pthread_create(&p[i], NULL, put_tab, &g->m[i]);
	j = -1;
	while (++j < MT)
		pthread_join(p[j], NULL);
}

static void		watermaker_second(t_gen *g)
{
	if (g->rep & 0x02)
		g->test[0]--;
	if (g->rep & 0x04)
		g->test[1]--;
	if (g->rep & 0x10)
		g->test[2]++;
	if (g->rep & 0x20)
		g->test[3]++;
	if (g->test[0] <= 0)
	{
		init_wave(g->wave[0]);
		g->test[0] = 299;
	}
	if (g->test[1] <= 0)
	{
		init_wave(g->wave[1]);
		g->test[1] = 299;
	}
	if (g->test[2] >= 299)
	{
		init_wave(g->wave[2]);
		g->test[2] = 0;
	}
}

static void		watermaker_first(t_gen *g)
{
	if (g->w->tab[299][299] > 151 || g->w->tab[0][0] > 151 ||
		g->w->tab[299][0] > 151 || g->w->tab[0][299] > 151
		|| g->w->tab[150][150] + g->t->tab[150][150] > 151)
		g->rep &= 0x40;
	if (!g->m)
	{
		if (!(g->m = (t_thread*)malloc(sizeof(t_thread) * MT)))
			error(3);
		init_thread(g->m, g);
		enable_music(g);
	}
	mlx_put_image_to_window(g->mlx, g->win, g->t->img, 0, 0);
	set_transparency(g);
	if (g->rep & 0x36)
	{
		watermaker_second(g);
		if (g->test[3] >= 299)
		{
			init_wave(g->wave[3]);
			g->test[3] = 0;
		}
	}
	watermaker_thread(g);
	mlx_put_image_to_window(g->mlx, g->win, g->w->img, 0, 0);
}

int				watermaker(t_gen *g)
{
	int			i;
	static char c = 0;

	if (g->rep & 0x80)
		return (0);
	watermaker_first(g);
	if (!c)
		++c;
	else
		c = 0;
	i = -1;
	if (g->rep & 0x100)
	{
		if (g->rang.nb < 0)
			Mix_PlayMusic(g->music[0], -1);
		while (++i < g->rang.nb)
			power_rangers(g, i, c,
				g->w->tab[g->rang.y[i]][g->rang.x[i]]);
		if (g->rang.nb > 0)
			mlx_put_image_to_window(g->mlx, g->win, g->rang.img, 0, 0);
	}
	return (0);
}

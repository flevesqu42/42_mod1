/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:15:55 by flevesqu          #+#    #+#             */
/*   Updated: 2016/04/15 15:29:16 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void			enable_shoot(t_gen *g, int i)
{
	if (g->sound[i] == NULL)
	{
		if (i == 0)
			g->sound[i] = Mix_LoadWAV("./sounds/rain.wav");
		if (i == 1)
			g->sound[i] = Mix_LoadWAV("./sounds/wave.wav");
		if (i == 2)
			g->sound[i] = Mix_LoadWAV("./sounds/malescream.wav");
		if (i == 3)
			g->sound[i] = Mix_LoadWAV("./sounds/femalescream.wav");
	}
	if (i == 1)
		Mix_PlayChannel(i + 1, g->sound[i], -1);
	else
		Mix_PlayChannel(i + 1, g->sound[i], 0);
}

void			enable_music(t_gen *g)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,
		1024) < 0)
		error(10);
	g->music[0] = Mix_LoadMUS("./sounds/seagull");
	g->music[1] = Mix_LoadMUS("./sounds/zik");
	Mix_PlayMusic(g->music[0], -1);
}

static void		writing_window(t_gen *g)
{
	void *window;

	if (!(window = mlx_new_window(g->mlx, 300, 200, "Menu")))
		error(2);
	mlx_string_put(g->mlx, window, 0, 20,
		ft_colors_wat(500), " Rising water  ~~> [ U ]");
	mlx_string_put(g->mlx, window, 0, 40,
		ft_colors_wat(500), " Falling water ~~> [ 0 ]");
	mlx_string_put(g->mlx, window, 0, 60,
		ft_colors_wat(500), " Waves         ~~> [ 1 <-> 4 ]");
	mlx_string_put(g->mlx, window, 0, 80,
		ft_colors_wat(300), " Time stop     ~~> [ SPACE ]");
	mlx_string_put(g->mlx, window, 0, 100,
		ft_colors_earth(400), " Earthmaker    ~~> [ H - J ]");
	mlx_string_put(g->mlx, window, 0, 120,
		ft_colors_earth(600), " Emptying      ~~> [ V ]");
	mlx_string_put(g->mlx, window, 0, 140,
		ft_colors_earth(700), " Heating       ~~> [ C ]");
}

int				main(int ac, char **av)
{
	char	*tmp;
	t_gen	*gen;
	int		i;

	if (ac != 2)
		error(5);
	if (!(tmp = ft_strstr(av[1], ".mod1")) || tmp[5])
		error(9);
	gen = acquisition_gen(av[1]);
	writing_window(gen);
	if (!(gen->win = mlx_new_window(gen->mlx, X, Y, ft_strrchr(av[1], '/')
					? ft_strrchr(av[1], '/') + 1 : av[1])))
		error(2);
	Mix_AllocateChannels(32);
	i = -1;
	while (++i < 5)
		gen->sound[i] = NULL;
	enter_mod1(gen);
	mlx_hook(gen->win, 2, (1l << 0), key_functions, gen);
	mlx_loop(gen->mlx);
	return (0);
}

void			error(int i)
{
	if (i == 1)
		ft_putstr_fd("Error : mlx_init() fail.\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error : mlx_new_window() fail.\n", 2);
	else if (i == 3)
		ft_putstr_fd("Error : malloc() fail.\n", 2);
	else if (i == 4)
		ft_putstr_fd("Error : mlx_new_image() fail.\n", 2);
	else if (i == 5)
		ft_putstr_fd("Usage : ./mod1 <map>\n", 2);
	else if (i == 6)
		ft_putstr_fd("No file.\n", 2);
	else if (i == 7)
		ft_putstr_fd("No file.\n", 2);
	else if (i == 8)
		ft_putstr_fd("No data.\n", 2);
	else if (i == 9)
		ft_putstr_fd("Bad file.\n", 2);
	else if (i == 10)
		ft_putstr_fd("Error : SDL fail.\n", 2);
	exit(1);
}

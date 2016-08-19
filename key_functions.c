/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 13:56:24 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/04/15 17:13:50 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static int		key_function_waves(t_gen *gen, int i)
{
	if (i == 0)
		gen->rep ^= 0x02;
	else if (i == 1)
		gen->rep ^= 0x04;
	else if (i == 2)
		gen->rep ^= 0x10;
	else if (i == 3)
		gen->rep ^= 0x20;
	if (i == 0)
		gen->test[0] = 299;
	if (i == 1)
		gen->test[1] = 299;
	if (i == 2)
		gen->test[2] = 0;
	if (i == 3)
		gen->test[3] = 0;
	if (!(gen->rep & 0x02) && !(gen->rep & 0x04)
			&& !(gen->rep & 0x10) && !(gen->rep & 0x20))
	{
		Mix_FreeChunk(gen->sound[1]);
		gen->sound[1] = NULL;
	}
	else
		enable_shoot(gen, 1);
	return (0);
}

static int		key_functions_bis(int key, t_gen *gen)
{
	if (key == 83)
		key_function_waves(gen, 0);
	if (key == 84)
		key_function_waves(gen, 1);
	if (key == 85)
		key_function_waves(gen, 2);
	if (key == 86)
		key_function_waves(gen, 3);
	return (0);
}

static int		key_functions_next(int key, t_gen *gen)
{
	if (key == 8)
		gen->rep ^= 0x40;
	if (key == 49)
		gen->rep ^= 0x80;
	if (key == 35)
	{
		if (gen->rang.nb < 0)
			return (0);
		gen->rep ^= 0x100;
		if (gen->rep & 0x100)
			Mix_PlayMusic(gen->music[1], 0);
		else
			Mix_PlayMusic(gen->music[0], -1);
	}
	if (key == 38)
	{
		gen->rep ^= 0x2000;
		aff_graph(gen);
	}
	return (key_functions_bis(key, gen));
}

int				key_functions(int key, t_gen *gen)
{
	if (key == 53)
		exit(1);
	if (key == 82)
	{
		gen->rep ^= 0x01;
		if (gen->rep & 0x01)
			enable_shoot(gen, 0);
	}
	if (key == 9)
		gen->rep ^= 0x08;
	if (key == 3)
		gen->rep ^= 0x800;
	if (key == 4)
	{
		if (gen->rep & 0x2000)
			gen->rep ^= 0x2000;
		gen->rep ^= 0x1000;
		aff_graph(gen);
	}
	if (key == 32)
		gen->rep ^= 0x200;
	return (key_functions_next(key, gen));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acquisition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 13:08:42 by flevesqu          #+#    #+#             */
/*   Updated: 2016/04/15 15:54:46 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static int	mod1_atoi(char *str)
{
	long	ret;

	ret = 0;
	if (!str)
		error(9);
	if (*str == '+')
		str += 1;
	while (*str >= '0' && *str <= '9')
	{
		ret = (ret * 10) + *str - '0';
		if (ret > 2147483647)
			error(9);
		str += 1;
	}
	if (*str || ret > 2147483647)
		error(9);
	return (ret);
}

static void	acquisition(t_gen *gen, char *name)
{
	int		ret;
	int		fd;
	char	*line;
	char	**data;
	t_hill	*new;

	gen->list = NULL;
	!(fd = open(name, O_RDONLY)) ? error(6) : 1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		!(data = ft_strsplit(line, ' ')) ? error(3) : 1;
		!(new = (t_hill*)malloc(sizeof(t_hill))) ? error(3) : 1;
		data[3] ? error(9) : 1;
		new->x = mod1_atoi(data[0]);
		new->y = mod1_atoi(data[1]);
		new->z = mod1_atoi(data[2]);
		new->next = gen->list;
		gen->list = new;
		free(data[0]);
		free(data[1]);
		free(data[2]);
		free(data);
		free(line);
	}
	ret == -1 ? error(7) : 1;
}

void		init_wave(float *wave)
{
	int	index;

	index = -1;
	while (++index < 300)
		wave[index] = 0;
}

t_gen		*acquisition_gen(char *av)
{
	t_gen	*new;

	if (!(new = (t_gen*)malloc(sizeof(t_gen))))
		error(3);
	if (!(new->music = (Mix_Music**)malloc(sizeof(Mix_Music*) * 2)))
		error(3);
	if (!(new->mlx = mlx_init()))
		error(1);
	init_wave(new->wave[0]);
	init_wave(new->wave[1]);
	init_wave(new->wave[2]);
	init_wave(new->wave[3]);
	new->rep = 0;
	new->test[0] = 299;
	new->test[1] = 299;
	new->test[2] = 0;
	new->test[3] = 0;
	acquisition(new, av);
	extrapolation(new);
	return (new);
}

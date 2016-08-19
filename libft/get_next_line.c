/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:04:22 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/02/26 02:27:41 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		merge_line(char **line, char **rest, char **tmp)
{
	if (!ft_strchr(*rest, '\n'))
	{
		*line = ft_strdup(*rest);
		*rest = NULL;
		free(*tmp);
	}
	else
	{
		*line = ft_strsub(*rest, 0, ft_strlen(*rest) -
			ft_strlen(ft_strchr(*rest, '\n')));
		*rest = ft_strsub(*rest, ft_strlen(*line) + 1, ft_strlen(*rest));
		free(*tmp);
	}
}

static int		merge(char **line, char **rest, int const fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	tmp = *rest;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*rest = ft_strjoin(*rest, buf);
		free(tmp);
		ft_bzero(buf, BUFF_SIZE + 1);
		tmp = *rest;
		if (ft_strchr(*rest, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (!ft_strlen(*rest))
		return (0);
	merge_line(line, rest, &tmp);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char	*rest;
	int			i;
	char		*tmp;

	i = 1;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (rest)
	{
		if (!ft_strchr(rest, '\n'))
			i = merge(line, &rest, fd);
		else
		{
			tmp = rest;
			*line = ft_strsub(rest, 0, ft_strlen(rest) -
				ft_strlen(ft_strchr(rest, '\n')));
			rest = ft_strsub(rest, ft_strlen(*line) + 1, ft_strlen(rest));
			free(tmp);
		}
		return ((i > 0 && ft_strlen(*line) > 0) ? 1 : i);
	}
	rest = ft_strnew(1);
	i = merge(line, &rest, fd);
	return ((i > 0 && ft_strlen(*line) > 0) ? 1 : i);
}

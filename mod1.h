/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:16:36 by flevesqu          #+#    #+#             */
/*   Updated: 2016/04/15 18:02:03 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD1_H
# define MOD1_H
# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <sys/types.h>
# include <SDL.h>
# include <SDL_mixer.h>
# include <pthread.h>
# define X 1600
# define Y 1200
# define MT 25
# define THE struct s_thread

typedef struct	s_hill
{
	int				x;
	int				y;
	int				z;
	int				max_z;
	struct s_hill	*next;
}				t_hill;

typedef struct	s_tab
{
	float	**tab;
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_tab;

typedef struct	s_pw
{
	void	*img;
	char	*data;
	int		x[5];
	int		y[5];
	int		bpp;
	int		size_line;
	int		endian;
	char	nb;
}				t_pw;

typedef struct	s_gen
{
	void		*mlx;
	void		*win;
	t_hill		*list;
	char		*d_cmp;
	char		r;
	int			test[4];
	float		wave[4][300];
	long int	rep;
	long		max_x;
	long		max_y;
	float		ratio;
	float		tmp;
	float		min_w;
	t_tab		*w;
	t_tab		*t;
	t_pw		rang;
	Mix_Chunk	*sound[5];
	Mix_Music	**music;
	THE			*m;
}				t_gen;

typedef struct	s_thread
{
	int		nb;
	int		lim[4];
	t_gen	*g;
}				t_thread;

typedef struct	s_xy
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}				t_xy;

float			define_x(float x, float y);
float			define_y(t_tab *t, float x, float y);
void			trace_line(t_gen *g, t_xy co, size_t color1, size_t color2);
void			aff_graph(t_gen *g);
void			error(int i);
int				key_functions(int key, t_gen *gen);
void			extrapolation(t_gen *gen);
void			enter_mod1(t_gen *gen);
int				color(float z, t_gen *g);
void			img_pixel_put(t_gen *gen, int x, int y, size_t color);
void			img_two_pixel_put(t_gen *g, int x, int y, size_t color);
void			datatest(t_gen *im, int x, int y, float z);
int				ft_colors_earth(int i);
int				ft_colors_ice(int i);
int				ft_colors_wat(int i);
int				ft_colors_mag(int i);
int				watermaker(t_gen *g);
t_tab			*init_tab(t_gen *g);
void			display_plan(t_gen *gen,
					int x, int y, int(*color)(float, t_gen *));
t_gen			*acquisition_gen(char *av);
void			set_transparency(t_gen *gen);
void			calling_rangers(t_gen *g);
void			power_rangers(t_gen *g, int i, char c, float z);
void			power_inforcement(t_gen *g, int index, int paste, int paste_s);
void			enable_music(t_gen *g);
void			enable_shoot(t_gen *g, int i);
int				watermaker_bis(t_gen *g);
void			power(t_gen *g, int x, int y, char z);
void			sleepy_hollow(t_gen *gen);
int				key_functions(int key, t_gen *gen);
void			init_thread(t_thread *t, t_gen *gen);
void			*put_tab(void *p);
void			watermove(t_gen *g);
void			*water_cooldown(void *d);
void			init_wave(float *wave);

#endif

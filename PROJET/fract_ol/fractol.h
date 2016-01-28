/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 18:31:41 by jromagna          #+#    #+#             */
/*   Updated: 2015/07/01 18:31:44 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include "libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <time.h>
# include <stdio.h>
# include <pthread.h>
# define H_SIZE		1080
# define L_SIZE		1920

# define TRNBR		4

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*image;
	char			*img; 
	int				**t;
	int				bpp;
	int				endiant;
	int				sline;
	int				pressed;
	double			mx;
	double			my;
	int				maxite;
	char			*name;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				mox;
	int				moy;
	int				movbool;
	int				zoombool;
	double			tot;
	int				xmin;
	int				xmax;
	int				ymin;
	int				ymax;
	int				i;
	int				tbool;
	int				tnbr;
	int				msmove;
	int				threadcount;
	unsigned int	*color_tab;
	unsigned int	color;
}					t_env;

typedef struct		s_point
{
	double			r;
	double			i;
}					t_point;

typedef struct		s_frct
{
	t_point		z;
	t_point		c;
	int			i;
	double		tmp;
	int			x;
	int			y;
	double		zoomx;
	double		zoomy;
	int			minx;
	int			maxx;
	int			miny;
	int			maxy;
}					t_frct;

enum				e_name
{
	UP = 0,
	DOWN = 1,
	RAN = 2,
	RIGHT = 3,
	TURN = 4,
	ITEP = 5,
	ITEM = 6
};

void			pixel_to_image(t_env *s, int x, int y, unsigned int color);
int				key_up_hook(int keycode, t_env *env);
int				key_down_hook(int keycode, t_env *env);
void			mandel(t_env *env);
int				mouse_hook(int button, int x, int y, t_env *env);
unsigned int	get_color(int r, int g, int b);
void			julia(t_env *env);
void			ship(t_env *env);
int				thread_master(t_env *env);
int				thread_overseer(t_env *env);
double			mandelship_move(t_env *env, double x);
unsigned int	color(int i, double c, double z);
void			color_tab(t_env *env);
void			color_tab2(t_env *env);
int				ft_color_loop(int i);
int				ft_color_loop2(int i);
void			t_env_init(t_env *env);
void			randomisator(t_env *env);
unsigned int	prism(double hue, double sat, double val);

#endif
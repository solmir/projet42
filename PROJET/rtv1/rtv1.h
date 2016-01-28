/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 21:22:47 by jromagna          #+#    #+#             */
/*   Updated: 2015/09/24 21:22:49 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include "libft/libft.h"
# include <unistd.h>
# include <math.h>

#include <stdio.h>

# define L_SIZE		1280
# define H_SIZE		960
# define L_RES		640
# define H_RES		480

# define SCR_L		0.35
# define SCR_H		0.5
# define SCR_DIST	1
# define L_IND		L_RES / L_SIZE
# define H_IND		H_RES / H_SIZE

typedef	struct		s_color
{
	double				r;
	double				g;
	double				b;
}					t_color;

typedef	struct		s_mat
{
	char			*name;
	t_color			*spec;
	t_color			*diff;
	t_color			*amb;
	t_color			*selfi;
	float			shiny;
	float			shinystr;
	float			trans;
	float			ref;
}					t_mat;

typedef	struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef	struct		s_light
{
	t_vec			*pos;
	unsigned int	color;
}					t_light;

typedef	struct		s_sphere
{
	t_vec			*c;
	double			ray;
}					t_sphere;

typedef	struct		s_plane
{
	t_vec			*p;
	t_vec			*d;
}					t_plane;

typedef	struct		s_lst
{
	t_sphere		*sp;
	t_plane			*pl;
}					t_lst;

typedef	struct		s_pd
{
	t_vec			*pos;
	t_vec			*dir;
}					t_pd;

typedef	struct		s_env
{
	void			*mlx;
	void			*win;
	void			*image;
	char			*img; 
	int				**t;
	int				bpp;
	int				endiant;
	int				sline;


	unsigned int	color;

	t_vec			*norm;
	t_vec			*pos;

	double			ttmp;
	double			ti;
	double			tl;
	
	t_light			*light;


	t_vec			*screen;

	t_pd			*cam;
	t_mat			*mat;

	t_lst			*lst;
	int				done;
}					t_env;

int					creator(t_env *env);
void				pixel_to_image(t_env *s, int x, int y, unsigned int color);
t_color				*new_t_color(double r, double g, double b);
t_mat				*new_t_mat(char *name);
t_pd				*new_t_pd();
t_vec				*new_t_vec(double x, double y, double z);
t_lst				*new_t_list();
t_light				*new_t_light();
void				get_light(t_env *e);
double				carre(double x);
double				check_stuff(t_env *env, t_pd *s);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 23:40:20 by jromagna          #+#    #+#             */
/*   Updated: 2015/04/10 23:40:21 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>

# include <mlx.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# define BUFF_SIZE 100
# define H_SIZE 1000
# define L_SIZE 1600
# define X_POS L_SIZE / 8
# define Y_POS H_SIZE / 8
# define ABS(x) (x < 0) ? -x : x



typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*image;
	int			**tab;
	int			maplx;
	int			maply;
}				t_env;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	unsigned int color;
}				t_point;

typedef struct	s_img
{
	char		*img;
	int			bpp;
	int			endiant;
	int			sline;
	int			hte;
	int			lge;
	int			mvx;
	int			mvy;
	unsigned int rcolor;
	unsigned int lcolor;
}				t_img;

typedef struct	s_sup
{
	int			xl;
	int			yl;
	int			zmult;
	int			SCALE;
	t_env		*env;
	t_img		*simg;
	int			type;
}				t_sup;

void			calculator(t_sup *sup);
int				**recuperator(char *name, t_env *s);
void			*ftm(size_t size);
void			put_endl_in_file(char *name);
int				count_word_makina(char *s);
int				ft_error(char *str);
int				verifL(int i);
int				verifH(int i);
void			la_magicienne(char *name, int *x, int *y);
int				expose_hook(t_sup *s);
void			ft_put_line(t_sup *e, t_point *p1, t_point *p2);
void			pixel_to_image(t_sup *s, int x, int y, unsigned int color);
void			puttabint(int **tabint, int x, int y);

#endif
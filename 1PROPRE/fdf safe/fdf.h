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
#include <errno.h>  
# define BUFF_SIZE 100
# define H_SIZE 1000
# define L_SIZE 1600
# define X_POS L_SIZE / 8
# define Y_POS H_SIZE / 8



typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*image;
	int			**tab;
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

char			***tabsplit(char **tab);
void 			ft_puttab(char **tab);
int				expose_hook(t_sup *s);
int 			key_hook(int *keycode, t_sup *sup);
t_sup 			*put_pixel(float x1, float y1, float x2, float y2, t_sup *sup);
void			director(int x1, int y1, int x2, int y2, t_env *env);
int				ft_tablen(char **tab);
int				ft_error(char *str);
void			creator(t_sup *sup);
int				**recuperator(char *name , t_sup *s);
void			pixel_to_image(t_sup *s, int x, int y, unsigned int color);
void 			ft_putcoolnbr(int i, char *c);
t_sup			*swap_master(float x1, float y1, float x2, float y2, t_sup *sup);
void			overputtab(char ***tab);
int 			verifH(int i);
int 			verifL(int i);
void			calculator(t_sup *sup);
void			calculator2(t_sup *sup);
void			ft_put_line(t_sup *e, t_point *p1, t_point *p2);
int				count_word_makina(char *s);
void 			puttabint(int **tabint, int x, int y);
void			put_endl_in_file(char *name);
void			ft_puttab(char **tab);
int				read_count(char *name);


#endif
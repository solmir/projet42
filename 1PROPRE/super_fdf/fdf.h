/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 23:45:09 by jromagna          #+#    #+#             */
/*   Updated: 2015/06/07 23:45:11 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "fdf.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# define BUFF_SIZE 100
# define H_SIZE 1080
# define L_SIZE 1960
# define X_POS L_SIZE / 8
# define Y_POS H_SIZE / 8
# define ABS(x) (x < 0) ? -x : x

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
	int				b;
	int				mvx;
	int				mvy;
	int				scale;
	int				zmult;
	unsigned int	rcolor;
	unsigned int	lcolor;
	int				maplx;
	int				maply;
	int				pressed;
	int				scalespeed;
	int				type;
}					t_env;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}					t_point;

typedef struct		s_cal
{
	double		dy;
	t_point		p1;
	t_point		p2;
}					t_cal;

enum				e_name
{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3,
	BIG = 4,
	SMALL = 5,
	ZP = 6,
	ZM = 7
};

void				calculator(t_env *e);
void				calculator2(t_env *e);
int					**recuperator(char *name, t_env *s);
void				la_magicienne(char *name, int *x, int *y);
void				put_endl_in_file(char *name);
void				pixel_to_image(t_env *s, int x, int y, unsigned int color);
int					ft_error(char *str);
void				move(t_env *e);
int					key_up_hook(int keycode, t_env *env);
int					key_down_hook(int keycode, t_env *env);
void				ft_put_line(t_env *e, t_point *p1, t_point *p2);
int					count_word_makina(char *s);
int					verifh(int i);
int					verifl(int i);
void				ft_print_instr(void);
void				tabint_init(int **tabint, int x, int y);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 07:51:32 by jromagna          #+#    #+#             */
/*   Updated: 2015/06/05 13:50:20 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <mlx.h>
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# define BUFF_SIZE	100
# define H_SIZE		1000
# define L_SIZE		1600
# define BLUE		0x0000FF
# define BLUE2		0x0083fb
# define GREEN		0x00FF00
# define GREEN2		0x28a55f
# define RED		0xFF0000
# define RED2		0x8b2500
# define BLACK		0x000000
# define PURPLE		0xc30a55
# define PURPLE2	0xb000ff
# define ROTG		-0.10
# define ROTD		0.10

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
	double			x;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			w;
	double			h;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			stepx;
	double			stepy;
	double			deltax;
	double			deltay;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				maplx;
	int				maply;
	int				side;
	int				hit;
	double			vitrot;
	int				pressed;
	double			real;
	int				hauteur;
	int				run;
	int				drawstart;
	int				drawend;
	unsigned int	color;
	int				oldmy;
	int				oldmx;
	int				oldside;
	int				juke;
}					t_env;

enum				e_name
{
	FORWARD = 0,
	BACK = 1,
	LEFT = 2,
	RIGHT = 3,
	TURN = 4
};

int					key_up_hook(int keycode, t_env *env);
int					key_down_hook(int keycode, t_env *env);
void				calculator(t_env *env);
void				pixel_to_image(t_env *s, int x, int y, unsigned int color);
void				move(t_env *env);
int					**recuperator(char *name, t_env *s);
void				ft_error(char *str);
void				put_endl_in_file(char *name);
void				*ftm(size_t size);
int					count_word_makina(char *s);
void				map_verif(int **tabbint, int x, int y);
void				ft_print_instr();
void				gen_check(t_env *env);
void				valor_init(t_env *env);
void				get_h(t_env *env);
void				la_magicienne(char *name, int *x, int *y);
void				ft_putinttab(int **tabint, int x, int y);
void				preparator(t_env *e);
void				start_pos(t_env *env);

#endif

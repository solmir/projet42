/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 19:08:33 by jromagna          #+#    #+#             */
/*   Updated: 2015/11/12 17:24:41 by jromagna         ###   ########.fr       */
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
# define H_SIZE		1000		
# define L_SIZE		1000
# define CNBR		50
# define SIZE		5

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
	int				tab[CNBR][CNBR];
	int				dir;
	int				posx;
	int				posy;
	int				val;
	int				bouffe;
	double			speed;
}					t_env;

enum				e_name
{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3,
};

#endif

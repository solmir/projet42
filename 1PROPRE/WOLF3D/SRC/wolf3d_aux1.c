/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_aux1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 07:53:23 by jromagna          #+#    #+#             */
/*   Updated: 2015/05/19 07:53:25 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void		start_pos(t_env *env)
{
	double	x;
	double	y;

	x = 0;
	y = 0;
	while (y < env->maply && env->t[(int)y][(int)x] != 0)
	{
		x++;
		if (x == env->maplx - 1)
		{
			x = 0;
			y++;
		}
	}
	if (x >= env->maplx || y >= env->maply)
		ft_error("la zone est trop encombree pour etre exploree");
	env->posx = x + 0.5;
	env->posy = y + 0.5;
}

inline void	norma(t_env *e, int y, int z)
{
	int x;
	int c;

	while (++y < H_SIZE)
	{
		x = -1;
		while (++x < L_SIZE)
		{
			z = z + 2011;
			c = (z * x * y * (int)((e->dirx + 10324) * 10000)
				* (int)e->posx * (int)e->posy) % 3;
			e->color = (c) ? 0x28a55f : 0x850072;
			e->color = (c == 2) ? 0x0146bd : e->color;
			pixel_to_image(e, x, y, e->color);
		}
	}
}

void		preparator(t_env *e)
{
	int x;
	int y;
	int z;

	z = 0;
	y = 0;
	while (++y < (H_SIZE / 2))
	{
		x = 0;
		while (++x < L_SIZE + 1)
		{
			z = z + 2011;
			e->color = !((z * x * y) % 600) ? 0x2fbf78 : 0x000099;
			if (e->color == 0x2fbf78 && z % 2 == 0)
				e->color = 0xc30a55;
			pixel_to_image(e, x - 1, y - 1, e->color);
		}
	}
	y--;
	y--;
	norma(e, y, z);
}

void		ft_error(char *str)
{
	ft_putendl_fd("-> WOLF3D: \"ERROR :3 try again <3\"", 2);
	ft_putendl_fd("-> you : let's do this !", 2);
	ft_putstr_fd("ERROR is : ", 2);
	ft_putendl_fd(str, 2);
	exit (1);
	return ;
}

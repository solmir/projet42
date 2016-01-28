/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 22:34:08 by jromagna          #+#    #+#             */
/*   Updated: 2015/07/29 22:34:09 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	get_color(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void		mandel(t_env *env)
{
	t_frct		f;

	while (env->i != 0)
	{
	}
	f.minx = env->xmin;
	f.maxx = env->xmax;
	f.miny = env->ymin;
	f.maxy = env->ymax;
	env->i = 1;
	while (env->tbool == 1)
	{
		f.x = f.minx - 1;
		f.zoomx = L_SIZE / (env->tot);
		f.zoomy = H_SIZE / (env->tot);
		while (++f.x < f.maxx)
		{
			f.y = f.miny - 1;
			while (++f.y < f.maxy) 
			{
				f.c.r = (f.x / f.zoomx) + env->x1;
				f.c.i = (f.y / f.zoomy) + env->y1;
				f.z.r = mandelship_move(env, (double)(env->mox * 2 / (double)L_SIZE - 1));
				f.z.i = mandelship_move(env, (double)(env->moy * 2 / (double)H_SIZE - 1));
				f.i = 0;
				while ((((f.z.r * f.z.r) + (f.z.i * f.z.i)) < 4) && (f.i < env->maxite))
				{
					f.tmp = f.z.r;
					f.z.r = (f.z.r * f.z.r) - (f.z.i * f.z.i) + f.c.r;
					f.z.i = (2 * f.z.i * f.tmp) + f.c.i;
					f.i++;
				}
				if (f.i != env->maxite)
				{
					pixel_to_image(env, f.x, f.y, env->color_tab[ft_color_loop2(f.i)]);
				}
				else
					pixel_to_image(env, f.x, f.y, get_color(0, 0, 0));
			}
		}
	}
	env->threadcount--;
	pthread_exit(NULL);
}
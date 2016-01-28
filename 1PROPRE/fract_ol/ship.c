/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 23:58:36 by jromagna          #+#    #+#             */
/*   Updated: 2015/08/11 23:58:37 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		mandelship_move(t_env *env, double x)
{
	if (env->msmove == 1)
		return (x);
	return (0);
}

void		ship(t_env *env)
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
	while(env->tbool == 1)
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
					f.z.r = fabs(f.z.r);
					f.z.i = (2 * f.z.i * f.tmp) + f.c.i;
					f.z.i = fabs(f.z.i);
					f.i++;
				}
				if (f.i == env->maxite)
				{
					pixel_to_image(env, f.x, f.y, get_color(30, 2, 2));
				}
				else if (f.i % 2 == 0)
					pixel_to_image(env, f.x, f.y, 0x200000 + get_color(f.i * 255 / env->maxite, 0, 0));
				else
					pixel_to_image(env, f.x, f.y, 0x110000 + get_color(f.i * 255 / env->maxite, 0, 0));
			}
		}
	}
	env->threadcount--;
	pthread_exit(NULL);
}
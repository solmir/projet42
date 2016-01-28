/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 21:03:38 by jromagna          #+#    #+#             */
/*   Updated: 2015/06/03 21:03:39 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

inline void		valor_init(t_env *env)
{
	env->camerax = (2 * env->x / env->w) - 1;
	env->rayposx = env->posx;
	env->rayposy = env->posy;
	env->raydirx = env->dirx + env->planex * env->camerax;
	env->raydiry = env->diry + env->planey * env->camerax;
	env->mapx = (int)env->rayposx;
	env->mapy = (int)env->rayposy;
	env->deltax = sqrt(1 + (env->raydiry * env->raydiry)
		/ (env->raydirx * env->raydirx));
	env->deltay = sqrt(1 + (env->raydirx * env->raydirx)
		/ (env->raydiry * env->raydiry));
	env->hit = 0;
}

inline void		cell_tracer(t_env *env)
{
	int	y;

	y = env->drawstart;
	while (y < env->drawend)
	{
		pixel_to_image(env, env->x, y, env->color);
		y++;
	}
	y = env->drawend;
	env->drawend = (env->drawend < 0) ? env->h : env->drawend;
	pixel_to_image(env, env->x, H_SIZE - y + 1, 0x000000);
	pixel_to_image(env, env->x, H_SIZE - y, 0x000000);
	pixel_to_image(env, env->x, y - 2, 0x000000);
	pixel_to_image(env, env->x, y - 1, 0x000000);
}

inline void		gen_check(t_env *env)
{
	if (env->oldside != env->side || env->oldmy != env->mapy
		|| env->oldmx != env->mapx)
	{
		env->oldside = env->side;
		env->oldmy = env->mapy;
		env->oldmx = env->mapx;
		env->color = 0X000000;
	}
	else
	{
		env->oldside = env->side;
		env->oldmy = env->mapy;
		env->oldmx = env->mapx;
	}
	cell_tracer(env);
}

inline void		get_h(t_env *env)
{
	env->hauteur = abs((int)(env->h / env->real));
	env->drawstart = (int)(-env->hauteur / 2 + env->h / 2);
	env->drawend = (int)(env->hauteur / 2 + env->h / 2);
	env->drawstart = (env->drawstart < 0) ? 0 : env->drawstart;
	env->drawend = (env->drawend > env->h) ? env->h : env->drawend;
}

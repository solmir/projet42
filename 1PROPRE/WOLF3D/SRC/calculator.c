/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 12:51:48 by jromagna          #+#    #+#             */
/*   Updated: 2015/05/29 12:51:49 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

inline void		get_dir(t_env *env)
{
	if (env->raydirx < 0)
	{
		env->stepx = -1;
		env->sidedistx = (env->rayposx - env->mapx) * env->deltax;
	}
	else
	{
		env->stepx = 1;
		env->sidedistx = (env->mapx + 1 - env->rayposx) * env->deltax;
	}
	if (env->raydiry < 0)
	{
		env->stepy = -1;
		env->sidedisty = (env->rayposy - env->mapy) * env->deltay;
	}
	else
	{
		env->stepy = 1;
		env->sidedisty = (env->mapy + 1 - env->rayposy) * env->deltay;
	}
}

inline void		get_dist(t_env *env)
{
	while (env->hit == 0)
	{
		if (env->sidedistx < env->sidedisty)
		{
			env->sidedistx += env->deltax;
			env->mapx += env->stepx;
			env->side = (env->raydirx < 0) ? 0 : 2;
		}
		else
		{
			env->sidedisty += env->deltay;
			env->mapy += env->stepy;
			env->side = (env->raydiry < 0) ? 1 : 3;
		}
		if (env->t[env->mapx][env->mapy] > 0)
			env->hit = 1;
	}
}

inline void		get_real_dist(t_env *e)
{
	if (e->side == 0 || e->side == 2)
		e->real = fabs(((e->mapx - e->rayposx) + (1 - e->stepx)
			/ 2) / e->raydirx);
	else
		e->real = fabs(((e->mapy - e->rayposy) + (1 - e->stepy)
			/ 2) / e->raydiry);
}

inline void		get_color(t_env *env)
{
	if (env->t[env->mapx][env->mapy] == 3 && env->side == 0)
		env->color = RED;
	if (env->t[env->mapx][env->mapy] == 3 && env->side == 1)
		env->color = RED2;
	if (env->t[env->mapx][env->mapy] == 3 && env->side == 2)
		env->color = GREEN;
	if (env->t[env->mapx][env->mapy] == 3 && env->side == 3)
		env->color = GREEN2;
	if (env->t[env->mapx][env->mapy] == 5 && env->side == 0)
		env->color = BLUE;
	if (env->t[env->mapx][env->mapy] == 5 && env->side == 1)
		env->color = BLUE2;
	if (env->t[env->mapx][env->mapy] == 5 && env->side == 2)
		env->color = PURPLE;
	if (env->t[env->mapx][env->mapy] == 5 && env->side == 3)
		env->color = PURPLE2;
}

void			calculator(t_env *env)
{
	env->oldside = 0;
	env->oldmx = 0;
	env->oldmy = 0;
	env->x = 0;
	while (env->x < env->w)
	{
		valor_init(env);
		get_dir(env);
		get_dist(env);
		get_real_dist(env);
		get_color(env);
		get_h(env);
		gen_check(env);
		env->x++;
	}
}

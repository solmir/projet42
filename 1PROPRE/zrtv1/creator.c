/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 18:10:49 by jromagna          #+#    #+#             */
/*   Updated: 2015/11/12 18:10:50 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		impactor(t_env *env, t_pd *pd, t_inter *inter)
{
	t_item	*lst;

	lst = env->item;
	while (env->item != NULL)
	{
		if (env->item->sp != NULL)
		{
			check_sphere(env->item, pd, inter);
		}
		else if (env->item->pl != NULL)
		{
			check_plane(env->item, pd, inter);
		}
		env->item = env->item->next;
	}
	env->item = lst;
}

void		t_inter_set(t_inter *inter)
{
	inter->norm->x = 0;
	inter->norm->y = 0;
	inter->norm->z = 0;
	inter->pos->x = 0;
	inter->pos->y = 0;
	inter->pos->z = 0;
}

void		creator(t_env *env)
{
	int		x;
	int		y;
	t_pd	*pd;

	y = 0;
	pd = new_t_pd();
	//ft_putendl("creator");
	while (y < H_SIZE)
	{
		x = 0;
		while (x < L_SIZE)
		{
			env->fcolor = 0x000000;
			env->inter = new_t_inter();
			t_inter_set(env->inter);
		//	ft_putendl("boucle");
			pd->pos = env->cam->pos;
		//	printf("env->cam->pos x%f\n",env->cam->pos->x );
		//	printf("env->cam->dir x%f\n",env->screen->pos->y );
			pd->dir = env->screen->pos;
			impactor(env, pd, env->inter);
			set_inter_pos(env->inter, pd);
			luminator(env);
			pixel_to_image(env, x, y, env->fcolor);
			env->screen->pos->z = env->screen->dir->z + L_IND * x;
			x++;
		}
		env->screen->pos->z = env->screen->dir->z;
		env->screen->pos->y = env->screen->pos->y - L_IND;
		y++;
	}
}
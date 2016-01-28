/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 21:32:37 by jromagna          #+#    #+#             */
/*   Updated: 2015/08/23 21:32:39 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			thread_slave(t_env *env)
{

	while (42)
	{
		if (env->tbool == 0 && env->threadcount < 1)
		{
			env->tbool = 1;
			thread_master(env);
		}
		else
			ft_putstr("");
	}
	return (0);
}

int			thread_overseer(t_env *env)
{
		void		*pointf;
		pthread_t	thread;

		pointf = &(thread_slave);
		if (pthread_create(&thread, NULL, pointf, env) != 0)
				ft_error("creation de thread rate");
		return (0);
}

int			thread_master(t_env *env)
{
	void		*pointf;
	int			x;
	int			y;
	int			px;
	int			py;
	int			i;
	pthread_t	thread_ecran[5000];

	y = 0;
	i = 0;
	px = L_SIZE / env->tnbr;
	py = H_SIZE / env->tnbr;
	if (env->tnbr == 8 || env->tnbr == 4)
		px = px * 2;
	pointf = NULL;
	if (ft_strcmp("julia", env->name) == 0)
		pointf = &(julia);
	if (ft_strcmp("mandel", env->name) == 0)
		pointf = &(mandel);
	if (ft_strcmp("ship", env->name) == 0)
		pointf = &(ship);
	while (y < H_SIZE)
	{
		x = 0;
		while (x < L_SIZE)
		{
			while (env->i != 1)
			{
				ft_putstr("");
			}
			env->xmin = x;
			env->xmax = x + px;
			env->ymin = y;
			env->ymax = y + py;
			env->i = 0;
			if (pthread_create(&(thread_ecran[i]), NULL, pointf, env) != 0)
				ft_error("creation de thread rate");
			else
				env->threadcount++;
			x = x + px;
			i++;
		}
		y = y + py;
	}
	return (0);
}
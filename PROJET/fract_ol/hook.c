/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 17:34:25 by jromagna          #+#    #+#             */
/*   Updated: 2015/08/20 12:42:41 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				center_mouse(t_env *env)
{
	static double		pointx;
	static double		pointy;

	pointx = pointx + ((env->mx * env->tot) / L_SIZE) - (env->tot / 2);
	pointy = pointy + ((env->my * env->tot) / H_SIZE) - (env->tot / 2);
	env->x1 = pointx - (env->tot / 2);
	env->x2 = env->x1 + (2.4);
	env->y1 = pointy - (env->tot / 2);
	env->y2 = env->y1 + (2.4);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *env)
{
	if (env->zoombool == 1)
	{
		env->mx = x;
		env->my = y;
	}
	else
	{
		env->mx = L_SIZE / 2;
		env->my = H_SIZE / 2;
	}
	if (button == 4)
	{
		if (env->movbool != 1)
		{
			center_mouse(env);
			env->tot = env->tot * 0.98;
		}
	}
	if (button == 5)
	{
		if (env->movbool != 1)

		{
			center_mouse(env);
			env->tot = env->tot * 1.02;
		}
	}
	return (0);
}

int			key_down_hook(int keycode, t_env *env)
{
	if (keycode == 13 || keycode == 126)
		env->pressed &= ~(1 << UP);
	if (keycode == 15)
		env->pressed &= ~(1 << RAN);
	if (keycode == 1 || keycode == 125)
		env->pressed &= ~(1 << DOWN);
	if (keycode == 69)
		env->pressed &= ~(1 << ITEP);
	if (keycode == 78)
		env->pressed &= ~(1 << ITEM);
	return (0);
}

void		key_up_hook2(int keycode, t_env *env)
{
	if (keycode == 46)
	{
		if (env->movbool == 1)
			env->movbool = 0;
		else if (env->movbool == 0)
			env->movbool = 1;
	}
	if (keycode == 45)
		{
		if (env->zoombool == 1)
			env->zoombool = 0;
		else if (env->zoombool == 0)
			env->zoombool = 1;
	}
	if (keycode == 116)
	{
		if (env->tnbr == 4)
			env->tnbr = 8;
		else if (env->tnbr == 8)
			env->tnbr = 1;
		else if (env->tnbr == 1)
			env->tnbr = 2;
		else if (env->tnbr == 2)
			env->tnbr = 4;
		env->tbool = 0;
	}
}

int			key_up_hook(int keycode, t_env *env)
{
	if (keycode == 15)
		randomisator(env);
	if (keycode == 49)
		t_env_init(env);
	if (keycode == 11)
	{
		if (env->msmove == 1)
			env->msmove = 0;
		else
			env->msmove = 1;
	}
	if (keycode == 15)
		env->pressed |= 1 << RAN;
	if (keycode == 13 || keycode == 126)
		env->pressed |= 1 << UP;
	if (keycode == 1 || keycode == 125)
		env->pressed |= 1 << DOWN;
	if (keycode == 69)
		env->pressed |= 1 << ITEP;
	if (keycode == 78)
		env->pressed |= 1 << ITEM;
	if ((int)keycode == 53)
		exit (0);
	key_up_hook2(keycode, env);
	return (0);
}

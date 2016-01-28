/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 23:57:37 by jromagna          #+#    #+#             */
/*   Updated: 2015/06/07 23:57:38 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		key_up_hook4(int keycode, t_env *env)
{
	if (keycode == 85)
	{
		env->rcolor = 0x0000FF;
		env->lcolor = 0x0000FF;
	}
	if (keycode == 69)
	{
		env->pressed |= 1 << BIG;
		env->scalespeed = 5;
	}
	if (keycode == 11)
		env->b++;
	if (env->b == 2)
		env->b = 0;
}

void		key_up_hook3(int keycode, t_env *env)
{
	if (keycode == 86)
	{
		env->rcolor = 0xFF00FF;
		env->lcolor = 0x00FFFF;
	}
	if (keycode == 83)
	{
		env->rcolor = 0xFF0000;
		env->lcolor = 0xFF0000;
	}
	if (keycode == 84)
	{
		env->rcolor = 0x00FF00;
		env->lcolor = 0x00FF00;
	}
	key_up_hook4(keycode, env);
}

void		key_up_hook2(int keycode, t_env *env)
{
	if (keycode == 78)
	{
		env->pressed |= 1 << SMALL;
		env->scalespeed = 5;
	}
	if (keycode == 116)
	{
		env->pressed |= 1 << BIG;
		env->scalespeed = 1;
	}
	if (keycode == 121)
	{
		env->pressed |= 1 << SMALL;
		env->scalespeed = 1;
	}
	if (keycode == 115)
		env->pressed |= 1 << ZP;
	if (keycode == 119)
		env->pressed |= 1 << ZM;
	if (keycode == 263)
	{
		env->type++;
		if (env->type == 2)
			env->type = 0;
	}
}

int			key_up_hook(int keycode, t_env *env)
{
	if ((int)keycode == 53)
		exit (0);
	if (keycode == 123)
		env->pressed |= 1 << LEFT;
	if (keycode == 124)
		env->pressed |= 1 << RIGHT;
	if (keycode == 126)
		env->pressed |= 1 << UP;
	if (keycode == 125)
		env->pressed |= 1 << DOWN;
	if (keycode == 87)
	{
		env->rcolor = 0xFFFF00;
		env->lcolor = 0xFF00FF;
	}
	if (keycode == 88)
	{
		env->rcolor = 0x000000;
		env->lcolor = 0x000000;
	}
	key_up_hook2(keycode, env);
	key_up_hook3(keycode, env);
	return (0);
}

int			key_down_hook(int keycode, t_env *env)
{
	if (keycode == 126)
		env->pressed &= ~(1 << UP);
	if (keycode == 125)
		env->pressed &= ~(1 << DOWN);
	if (keycode == 124)
		env->pressed &= ~(1 << RIGHT);
	if (keycode == 123)
		env->pressed &= ~(1 << LEFT);
	if (keycode == 69)
		env->pressed &= ~(1 << BIG);
	if (keycode == 78)
		env->pressed &= ~(1 << SMALL);
	if (keycode == 116)
		env->pressed &= ~(1 << BIG);
	if (keycode == 121)
		env->pressed &= ~(1 << SMALL);
	if (keycode == 119)
		env->pressed &= ~(1 << ZM);
	if (keycode == 115)
		env->pressed &= ~(1 << ZP);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 21:38:39 by jromagna          #+#    #+#             */
/*   Updated: 2015/05/20 21:38:40 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

inline void	key_up_hook_3(int keycode, t_env *env)
{
	if (keycode == 123)
	{
		env->pressed |= 1 << TURN;
		env->vitrot += ROTG;
	}
	if (keycode == 124)
	{
		env->pressed |= 1 << TURN;
		env->vitrot += ROTD;
	}
}

inline void	key_up_hook_2(int keycode, t_env *env)
{
	if ((int)keycode == 53)
	{
		system("killall afplay");
		exit (0);
	}
	if (keycode == 257)
	{
		env->run++;
		env->run = (env->run == 3) ? 0 : env->run;
	}
	env->juke = (keycode == 18) ? 1 : env->juke;
	env->juke = (keycode == 19) ? 2 : env->juke;
	env->juke = (keycode == 20) ? 3 : env->juke;
	env->juke = (keycode == 21) ? 4 : env->juke;
	env->juke = (keycode == 23) ? 5 : env->juke;
	env->juke = (keycode == 22) ? 6 : env->juke;
	env->juke = (keycode == 26) ? 7 : env->juke;
	env->juke = (keycode == 28) ? 8 : env->juke;
	env->juke = (keycode == 25) ? 9 : env->juke;
	env->juke = (keycode == 29) ? 0 : env->juke;
	key_up_hook_3(keycode, env);
}

int			key_up_hook(int keycode, t_env *env)
{
	key_up_hook_2(keycode, env);
	if (keycode == 13 || keycode == 126)
		env->pressed |= 1 << FORWARD;
	if (keycode == 1 || keycode == 125)
		env->pressed |= 1 << BACK;
	if (keycode == 0)
	{
		env->pressed |= 1 << TURN;
		env->vitrot = ROTG;
	}
	if (keycode == 2)
	{
		env->pressed |= 1 << TURN;
		env->vitrot = ROTD;
	}
	if (keycode == 12)
		env->pressed |= 1 << LEFT;
	if (keycode == 14)
		env->pressed |= 1 << RIGHT;
	return (0);
}

int			key_down_hook(int keycode, t_env *env)
{
	if (keycode == 13 || keycode == 126)
		env->pressed &= ~(1 << FORWARD);
	if (keycode == 1 || keycode == 125)
		env->pressed &= ~(1 << BACK);
	if (keycode == 2 || keycode == 0)
		env->pressed &= ~(1 << TURN);
	if (keycode == 14)
		env->pressed &= ~(1 << RIGHT);
	if (keycode == 12)
		env->pressed &= ~(1 << LEFT);
	return (0);
}

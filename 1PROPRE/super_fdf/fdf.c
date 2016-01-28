/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 23:45:24 by jromagna          #+#    #+#             */
/*   Updated: 2015/06/07 23:45:26 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			expose_hook(t_env *env)
{
	move(env);
	if (env->b == 0)
		ft_bzero(env->img, H_SIZE * L_SIZE * 4);
	if (env->type == 0)
		calculator(env);
	else if (env->type == 1)
		calculator2(env);
	mlx_put_image_to_window (env->mlx, env->win, env->image, 0, 0);
	return (0);
}

void		t_env_init(t_env *env)
{
	env->mvx = 0;
	env->mvy = 0;
	env->scale = 5;
	env->zmult = 5;
	env->rcolor = 0xFFFF00;
	env->lcolor = 0xFF00FF;
	env->scalespeed = 0;
	env->type = 0;
	env->b = 0;
}

int			main(int argc, char **argv)
{
	t_env env;

	if (argc != 2)
		ft_error("nombre d'argument invalide");
	env.t = recuperator(argv[1], &env);
	t_env_init(&env);
	ft_print_instr();
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, L_SIZE, H_SIZE, "fdf");
	env.image = mlx_new_image(env.mlx, L_SIZE, H_SIZE);
	env.img = mlx_get_data_addr(env.image, &env.bpp, &env.sline,
		&env.endiant);
	mlx_hook(env.win, 3, 2, key_down_hook, &env);
	mlx_hook(env.win, 2, 1, key_up_hook, &env);
	mlx_loop_hook(env.mlx, expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}

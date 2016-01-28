/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 07:50:15 by jromagna          #+#    #+#             */
/*   Updated: 2015/05/19 07:50:16 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void		check_music(t_env *env)
{
	static int i;

	if (i == env->juke)
		return ;
	if (i != env->juke)
		i = env->juke;
	system("killall afplay");
	if (i == 1)
		system("afplay sound/1.mp3 &");
	if (i == 2)
		system("afplay sound/2.mp3 &");
	if (i == 3)
		system("afplay sound/3.mp3 &");
	if (i == 4)
		system("afplay sound/4.mp3 &");
	if (i == 5)
		system("afplay sound/5.mp3 &");
	if (i == 6)
		system("afplay sound/6.mp3 &");
	if (i == 7)
		system("afplay sound/7.mp3 &");
	if (i == 8)
		system("afplay sound/8.mp3 &");
	if (i == 9)
		system("afplay sound/9.mp3 &");
}

int			la_mecque_detect(t_env *env)
{
	int		x;
	int		y;

	x = (int)env->posx;
	y = (int)env->posy;
	if (env->t[x + 1][y] == 8 || env->t[x - 1][y] == 8 || env->t[x][y + 1] == 8
		|| env->t[x][y - 1] == 8 || env->t[x + 1][y + 1] == 8
		|| env->t[x - 1][y + 1] == 8 || env->t[x + 1][y - 1] == 8
		|| env->t[x - 1][y - 1] == 8)
		return (1);
	return (0);
}

int			expose_hook(t_env *env)
{
	move(env);
	if (la_mecque_detect(env) == 1)
		check_music(env);
	preparator(env);
	calculator(env);
	mlx_put_image_to_window (env->mlx, env->win, env->image, 0, 0);
	return (0);
}

void		t_env_init(t_env *env)
{
	start_pos(env);
	env->dirx = -1;
	env->diry = 0;
	env->planex = 0;
	env->planey = 1;
	env->w = L_SIZE;
	env->h = H_SIZE;
	env->pressed = 0;
	env->juke = 3;
	env->run = 1;
}

int			main(int argc, char **argv)
{
	t_env env;

	if (argc != 2)
		ft_error("nombre d'argument invalide");
	env.t = recuperator(argv[1], &env);
	map_verif(env.t, env.maplx, env.maply);
	t_env_init(&env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, L_SIZE, H_SIZE, "wolf3d");
	env.image = mlx_new_image(env.mlx, L_SIZE, H_SIZE);
	env.img = mlx_get_data_addr(env.image, &env.bpp, &env.sline, &env.endiant);
	ft_print_instr();
	mlx_hook(env.win, 3, 2, key_down_hook, &env);
	mlx_hook(env.win, 2, 1, key_up_hook, &env);
	mlx_loop_hook(env.mlx, expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}

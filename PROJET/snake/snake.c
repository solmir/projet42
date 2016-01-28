/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 19:05:14 by jromagna          #+#    #+#             */
/*   Updated: 2015/09/23 19:05:15 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

void		pixel_to_image(t_env *s, int x, int y, unsigned int color)
{
	unsigned int	off;

	off = y * s->sline + x * s->bpp / 8;
	if (x < 0 || y < 0 || y > H_SIZE || x > L_SIZE)
		return ;
	s->img[off] = color >> 0;
	s->img[off + 1] = color >> 8;
	s->img[off + 2] = color >> 16;
}

void		creator(t_env *env)
{
	int		px;
	int		py;
	int		x;
	int		y;
	unsigned int color;

	srand(clock());
	px = L_SIZE / CNBR;
	py = H_SIZE / CNBR;
	y = 0;
	color = (unsigned int)rand();
	while (y != H_SIZE)
	{
		x = 0;
		while (x != L_SIZE)
		{
			if (env->tab[x / px][y / py] > 0)
				pixel_to_image(env, x, y, color);
			else if (env->tab[x / px][y / py] == -1)
				pixel_to_image(env, x, y, 0xFF0000);
			else
				pixel_to_image(env, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void		t_env_init(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	while (x < CNBR)
	{
		y = 0;
		while (y < CNBR)
		{
			env->tab[x][y] = 0;
			y++;
		}
		x++;
	}
	env->posx = CNBR / 2;
	env->posy = CNBR / 2;
	env->pressed = 0;
	env->dir = 3;
	env->val = SIZE;
	env->bouffe = 0;
	env->speed = 0.5;
}

void		reduc(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	while (x < CNBR)
	{
		y = 0;
		while (y < CNBR)
		{
			if (env->tab[x][y] > 0)
				env->tab[x][y]--;
			y++;
		}
		x++;
	}
}

void		move(t_env *env)
{
	if (env->dir == 0)
	{
		if (env->posy == 0 || env->tab[env->posx][env->posy - 1] > 0)
			ft_error("YOU LOST");
		else
			env->posy--;
	}
	if (env->dir == 2)
	{
		if (env->posy == CNBR - 1 || env->tab[env->posx][env->posy + 1] > 0)
			ft_error("YOU LOST");
		else
			env->posy++;
	}
	if (env->dir == 1)
	{
		if (env->posx == 0 || env->tab[env->posx - 1][env->posy] > 0)
			ft_error("YOU LOST");
		else
			env->posx--;
	}
	if (env->dir == 3)
	{
		if (env->posx == CNBR - 1 || env->tab[env->posx + 1][env->posy] > 0)
			ft_error("YOU LOST");
		else
			env->posx++;
	}
	if (env->tab[env->posx][env->posy] == -1)
	{
		env->val += 2;
		env->bouffe = 0;
	}
	env->tab[env->posx][env->posy] = env->val;
	reduc(env);
}

void		food(t_env *env)
{
	int		x;
	int		y;

	srand(clock());
	x = rand() % CNBR;
	y = rand() % CNBR;
	while (env->tab[x][y] != 0)
	{
		x = rand() % CNBR;
		y = rand() % CNBR;
	}
	env->tab[x][y] = -1;
	env->bouffe = 1;
}

int			expose_hook(t_env *env)
{
	move(env);
	if (env->bouffe == 0)
		food(env);
	creator(env);
	mlx_put_image_to_window (env->mlx, env->win, env->image, 0, 0);
	return (0);
}

int			key_up_hook(int keycode, t_env *env)
{
	int		tmp;

	tmp =env->dir;
	if (keycode == 126)
		env->dir = 0;
	if (keycode == 125)
		env->dir = 2;
	if (keycode == 123)
		env->dir = 1;
	if (keycode == 124)
		env->dir = 3;
	if (abs(tmp - env->dir) == 2)
		env->dir = tmp;
	if ((int)keycode == 53)
		exit (0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_env env;

	(void)argc;
	(void)argv;
	t_env_init(&env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, L_SIZE, H_SIZE, "SUNAKU");
	env.image = mlx_new_image(env.mlx, L_SIZE, H_SIZE);
	env.img = mlx_get_data_addr(env.image, &env.bpp, &env.sline, &env.endiant);
	mlx_hook(env.win, 2, 1, key_up_hook, &env);
	mlx_loop_hook(env.mlx, expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
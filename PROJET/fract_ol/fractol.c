/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 18:31:26 by jromagna          #+#    #+#             */
/*   Updated: 2015/07/01 18:31:28 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		arg_error()
{
	ft_putendl("julia");
	ft_putendl("mandel");
	ft_putendl("ship");
	exit (0);
}

int			arg_check(char *name)
{
	if (ft_strcmp("julia", name) == 0)
		return (1);
	if (ft_strcmp("mandel", name) == 0)
		return (2);
	if (ft_strcmp("ship", name) == 0)
		return (3);
	return (0);
}

int			move(t_env *e)
{
	if (e->pressed & (1 << ITEP))
		e->maxite += 1;
	if (e->pressed & (1 << ITEM))
		e->maxite -= 1;
	if (e->maxite <= 0)
		e->maxite = 1;
	if (e->pressed & (1 << RAN))
		randomisator(e);
	return (0);
}

void		put_ite_back(t_env *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < 200)
	{
		y = 0;
		while (y < 80)
		{
			mlx_pixel_put (e->mlx, e->win, x, y, 0x000000);
			y++;
		}
		x++;
	}
}

void		put_ite(t_env *e)
{
	char	*s;
	int		i;
	char	*sub;

	s = ft_strjoin("iteration : " , ft_itoa(e->maxite));
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF, s);
	i = e->tnbr * e->tnbr;
	i = (i == 0)? 1 : i;
	if (e->tnbr == 8 || e->tnbr == 4)
		i = i / 2;
	s = ft_strjoin("thread : " , ft_itoa(i));
	mlx_string_put(e->mlx, e->win, 10, 25, 0xFFFFFF, s);
	sub = (e->movbool == 0) ? ft_strdup("on") : ft_strdup("off");
	s = ft_strjoin("zoom :" , sub);
	mlx_string_put(e->mlx, e->win, 10, 40, 0xFFFFFF, s);
	sub = (e->zoombool == 0) ? ft_strdup("on") : ft_strdup("off");
	s = ft_strjoin("zoom lock :" , sub);
	mlx_string_put(e->mlx, e->win, 10, 55, 0xFFFFFF, s);
}

void		draw_cross(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = H_SIZE / 2;
	while (x != L_SIZE)
	{
		pixel_to_image(env, x, y, 0xFFFFFF);
		x++;
	}
	x = L_SIZE / 2;
	y = 0;
	while (y != H_SIZE)
	{
		pixel_to_image(env, x, y, 0xFFFFFF);
		y++;
	}
}

void		color_check(t_env *env, unsigned int c)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	while (x < L_SIZE)
	{
		y = 0;
		while (y < H_SIZE)
		{
			pixel_to_image(env, x, y, c);
			y++;
		}
		i = (700 * x / L_SIZE);
		x++;
	}
}

int			expose_hook(t_env *env)
{
	move(env);
	//breath(env);
	//color_check(env);
	mlx_put_image_to_window (env->mlx, env->win, env->image, 0, 0);
	put_ite_back(env);
	put_ite(env);
	return (0);
}

void		t_env_init_mandel(t_env *env)
{
	env->x1 = -2.1;
	env->x2 = 0.6;
	env->y1 = -1.2;
	env->y2 = 1.2;
	env->tot = 3;
}

void		t_env_init_ship(t_env *env)
{
	env->x1 = -2.5;
	env->x2 = 1.7;
	env->y1 = -2.5;
	env->y2 = 2.5;
	env->tot = 4;
}

void		t_env_init_julia(t_env *env)
{
	env->x1 = -1.2;
	env->x2 = 1.2;
	env->y1 = -1.2;
	env->y2 = 1.2;
	env->tot = 2.4;
}

void		t_env_init(t_env *env)
{
	if (ft_strcmp("julia", env->name) == 0)
		t_env_init_julia(env);
	else if (ft_strcmp("mandel", env->name) == 0)
		t_env_init_mandel(env);
	else if (ft_strcmp("ship", env->name) == 0)
		t_env_init_ship(env);
	env->movbool = 1;
	env->mx = 0;
	env->my = 0;
	env->pressed = 0;
	env->i = 1;
	env->maxite = 50;
	env->mox = 0;
	env->moy = 0;
	env->tbool = 0;
	env->tnbr = TRNBR;
	env->msmove = 1;
	color_tab2(env);
}

int			mouse_move_hook(int x, int y, t_env *env)
{
	if (env->movbool == 1)
	{
		env->mox = x;
		env->moy = y;
	}
	return (0);
}

void		ft_put_instruction();

void		ft_hsl_test(t_env *e)
{
	unsigned int c;

	c = prism(315, 0.86, 0.43);
	printf("color = %#x\n", c);
	color_check(e, c);
}

int			main(int argc, char **argv)
{
	t_env env;
	if (argc != 2 || arg_check(argv[1]) == 0)
		arg_error();
	//ft_put_instruction();
	env.name = ft_strdup(argv[1]);
	t_env_init(&env);
	env.zoombool = 1;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, L_SIZE, H_SIZE, argv[1]);
	env.image = mlx_new_image(env.mlx, L_SIZE, H_SIZE);
	env.img = mlx_get_data_addr(env.image, &env.bpp, &env.sline, &env.endiant);
	thread_overseer(&env);
	//ft_hsl_test(&env);
	mlx_mouse_hook (env.win, mouse_hook, &env);
	mlx_hook(env.win, 3, 2, key_down_hook, &env);
	mlx_hook(env.win, 2, 1, key_up_hook, &env);
	mlx_hook(env.win, 6, 1L<<6, mouse_move_hook, &env);
	mlx_loop_hook(env.mlx, expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
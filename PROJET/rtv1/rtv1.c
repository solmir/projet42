/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 21:22:38 by jromagna          #+#    #+#             */
/*   Updated: 2015/09/24 21:22:39 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
/*
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

void		get_screen_pos(t_env *e)
{
	double	x;
	double	y;
	double	z;

	x = e->cam->pos->x + e->cam->dir->x * SCR_DIST;
	y = e->cam->pos->y + e->cam->dir->y * SCR_H / 2;
	z = e->cam->pos->z - e->cam->dir->z * SCR_L / 2;
	e->screen = new_t_vec(x, y, z);
}

void		t_env_init(t_env *env)
{
	env->cam = new_t_pd();
	env->color = 0xFFFFFF;
	env->cam->pos = new_t_vec(0, -5, -5);
	env->cam->dir = new_t_vec(1.0, 0.0, 0.0);
	//get_screen_pos(env);
	env->light = new_t_light();
	env->light->pos = new_t_vec(0, -5, -5);
	env->light->color = 0xFFFFFF;
	env->t = 0;
	env->mat = new_t_mat("test");
	env->mat->diff = new_t_color(1, 1, 1);
	env->norm = new_t_vec(0, 0, 0);
	env->pos = new_t_vec(0, 0, 0);
	env->done = 0;
}

int			expose_hook(t_env *env)
{
	if (env->done == 0)
		creator(env);
	mlx_put_image_to_window (env->mlx, env->win, env->image, 0, 0);
	env->done = 1;
	return (0);
}

t_plane	*t_plane_creator(double x, double y, double z, double dx, double dy, double dz)
{
	t_plane		*plane;

	plane = malloc(sizeof(t_plane));
	plane->p = new_t_vec(x, y, z);
	plane->d = new_t_vec(dx, dy, dz);
	return (plane);
}

t_sphere	*t_sphere_creator(double x, double y, double z, double r)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->c = new_t_vec(x, y, z);
	sphere->ray = r;
	return (sphere);
}

void		t_list_creator(t_env *env)
{
	t_lst *lst;

	lst = new_t_list();
	//
	//
	//lecture des truc ICI!
	//
	//
	lst->sp = t_sphere_creator(6, 0, 0, 1);
	lst->pl = t_plane_creator(10, 0, 0, 1, 1, 1);
	env->lst = lst;
}

int			key_down_hook(int keycode, t_env *env)
{
	(void)env;
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
	t_list_creator(&env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, L_SIZE, H_SIZE, "RTV1");
	env.image = mlx_new_image(env.mlx, L_SIZE, H_SIZE);
	env.img = mlx_get_data_addr(env.image, &env.bpp, &env.sline, &env.endiant);
	mlx_hook(env.win, 2, 1, key_down_hook, &env);
	mlx_loop_hook(env.mlx, expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}*/

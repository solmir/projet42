/* ************************************************************************** */
/*		                                                  */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 23:39:37 by jromagna          #+#    #+#             */
/*   Updated: 2015/04/10 23:39:39 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# include <stdio.h>

int 			key_hook(int *keycode, t_sup *sup)
{
	ft_putendl("KEY HOOK");
	printf("key : %d\n", (int)keycode);
	if ((int)keycode == 53)
		exit (0);
	if ((int)keycode == 126)
	{
		sup->simg->mvy = verifH(sup->simg->mvy - H_SIZE / 20);
		expose_hook(sup);
	}
	if ((int)keycode == 125)
	{
		sup->simg->mvy = verifH(sup->simg->mvy + H_SIZE / 20);
		expose_hook(sup);
	}
	if ((int)keycode == 123)
	{
		sup->simg->mvx = verifL(sup->simg->mvx - L_SIZE / 20);
		expose_hook(sup);
	}
	if ((int)keycode == 124)
	{
		sup->simg->mvx = verifL(sup->simg->mvx + L_SIZE / 20);
		expose_hook(sup);
	}
	if ((int)keycode == 87)
	{
		sup->simg->rcolor = 0xFFFF00;
		sup->simg->lcolor = 0xFF00FF;
		expose_hook(sup);
	}
	if ((int)keycode == 88)
	{
		sup->simg->rcolor = 0x00FFFF;
		sup->simg->lcolor = 0xFFFF00;
		expose_hook(sup);
	}
	if ((int)keycode == 86)
	{
		sup->simg->rcolor = 0xFF00FF;
		sup->simg->lcolor = 0x00FFFF;
		expose_hook(sup);
	}
	if ((int)keycode == 83)
	{
		sup->simg->rcolor = 0xFF0000;
		sup->simg->lcolor = 0xFF0000;
		expose_hook(sup);
	}
	if ((int)keycode == 84)
	{
		sup->simg->rcolor = 0x00FF00;
		sup->simg->lcolor = 0x00FF00;
		expose_hook(sup);
	}
	if ((int)keycode == 85)
	{
		sup->simg->rcolor = 0x0000FF;
		sup->simg->lcolor = 0x0000FF;
		expose_hook(sup);
	}
	if ((int)keycode == 69)
	{
		sup->SCALE += 5;
		expose_hook(sup);
	}
	if ((int)keycode == 78)
	{
		sup->SCALE -= 5;
		expose_hook(sup);
	}
	if ((int)keycode == 116)
	{
		sup->SCALE += 1;
		expose_hook(sup);
	}
	if ((int)keycode == 121)
	{
		sup->SCALE -= 1;
		expose_hook(sup);
	}
	if ((int)keycode == 115)
	{
		sup->zmult -= 1;
		if (sup->zmult == 0)
			sup->zmult = 1;
		ft_putnbr(sup->zmult);
		expose_hook(sup);
	}
	if ((int)keycode == 119)
	{
		sup->zmult += 1;
		if (sup->zmult == 51)
			sup->zmult = 50;
		ft_putnbr(sup->zmult);
		expose_hook(sup);
	}
	return (0);
}

void 		ft_putcoolnbr(int i, char *c)
{
	ft_putstr(c);
	ft_putstr(" : ");
	ft_putnbr(i);
	ft_putchar('\n');
}

void		pixel_to_image(t_sup *s, int x, int y, unsigned int color)
{
	unsigned int	off;

	x = verifL(x);
	y = verifH(y);
	off = y * s->simg->sline + x * s->simg->bpp / 8;
	if (x < 0 || y < 0 || y > s->simg->hte || x > s->simg->lge)
		return ;
	s->simg->img[off] = color >> 0;
	s->simg->img[off + 1] = color >> 8;
	s->simg->img[off + 2] = color >> 16;
}


void 	creator(t_sup *sup)
{
	calculator(sup);
}

int		expose_hook(t_sup *s)
{
	ft_putendl("EXPOSE_HOOK");
	ft_putcoolnbr(s->simg->mvx, "s->simg->mvx");
	ft_putcoolnbr(s->simg->mvy, "s->simg->mvy");
	ft_bzero(s->simg->img, s->simg->hte * s->simg->lge * 4);
	creator(s);
	mlx_put_image_to_window (s->env->mlx, s->env->win, s->env->image, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;
	t_img	simg;
	t_sup	sup;

	if (argc != 2)
		ft_error("nombre d'argument invalide");
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, L_SIZE, H_SIZE, "FDF");
	simg.lge = L_SIZE;
	simg.hte = H_SIZE;

	env.image = mlx_new_image(env.mlx, L_SIZE, H_SIZE);
	simg.img = mlx_get_data_addr(env.image, &simg.bpp, &simg.sline, &simg.endiant);
	env.tab = recuperator(argv[1], &sup);
	simg.mvx = X_POS;
	simg.mvy = Y_POS;
	sup.SCALE = 5;
	sup.zmult = 5;
	sup.env = &env;
	sup.simg = &simg;
	simg.rcolor = 0xFFFF00;
	simg.lcolor = 0xFF00FF;
	ft_putendl("HOOK");
	mlx_expose_hook(env.win, expose_hook, &sup);
	ft_putendl("KEY");
	mlx_hook(env.win, 2, 3, key_hook, &sup);
	ft_putendl("LOOP");
	mlx_loop(env.mlx);
	ft_putendl("LOOP");
	return (0);
}
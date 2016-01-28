/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/28 20:06:35 by jromagna          #+#    #+#             */
/*   Updated: 2015/08/28 20:06:38 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	randomisator(t_env *env)
{
	unsigned int 	tab[800];
	int						i;
	int						r;

	srand (time(NULL));
	i = -1;
	while (++i < 800)
		tab[i] = 0;
	i = 0;
	r = 0;
	while (i < 800)
	{
		while (tab[r] != 0)
			r = rand() % 800;
		tab[r] = env->color_tab[i];
		i++;
	}
	i = 0;
	while (i < 800)
	{
		env->color_tab[i] = tab[i];
		i++;
	}
}

int		scalor(int i)
{
	while (i > 100)
		i--;
	return (i * 255 / 100);
}

void	color_tab2(t_env *env)
{
	static unsigned int 	tab[800];
	int				i;
	int				r;
	int				g;
	int				b;

	i = 0;
	while (i < 800)
	{
		r = 0;
		g = 0;
		b = 0;
		if (i <= 100)
		{
			r = scalor(i);
		}
		else if (i > 100 && i <= 300)
		{
			r = scalor(i);
			g = scalor((i - 100) / 2);
		}
		else if (i > 300 && i <= 400)
		{
			g = scalor((i - 100) / 2);
			r = scalor(-i + 200);
		}
		else if (i > 400 && i <= 500)
		{
			b = scalor((i - 400));
			g = scalor(-i + 500);
		}
		else if (i > 500 && i <= 600)
		{
			r = scalor((i - 500) / 4);
			b = scalor((-i + 700) / 2);
		}
		else if (i > 600 && i <= 700)
		{
			r = scalor((i - 500) / 4);
			b = scalor(((-i + 700) / 2) + i - 600);
		}
		else if (i > 700 && i <= 800)
		{
			r = scalor((i - 600) / 2);
			g = scalor(i - 700);
			b = 255;
		}
		tab[i] = get_color(r, g ,b);
		i++;
	}
	env->color_tab = tab;
	return ;
}

void	color_tab(t_env *env)
{
	static unsigned int 	tab[767];
	int				i;
	int				r;
	int				g;
	int				b;

	i = 0;
	while (i < 768)
	{
		r = 0;
		g = 0;
		b = 0;
		if (i >= 512)
		{
			r = i - 512;
			g = 255 - r;
		}
		else if (i >= 256)
		{
			g = i - 256;
			b = 255 - g;
		}
		else
		{
			b = i;
		}
		tab[i] = get_color(r, g ,b);
		i++;
	}
	env->color_tab = tab;
	//check(env);
	return ;
}

double				ft_fabs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

double				scalor01(double x)
{
	while (x < 1)
		x++;
	while (x > 1)
		x--;
	return (x);
}

double				color_testator(double tr, double tmp1, double tmp2)
{
	if (6 * tr < 1)
		return (tmp2 + (tmp1 - tmp2) * 6 * tr);
	if (2 * tr < 1)
		return (tmp1);
	if (3 * tr < 2)
		return (tmp2 + (tmp1 - tmp2) * (0.666 - tr) * 6);
	return (tmp2);
}

unsigned int		prism(double hue, double sat, double lum)
{
	double	r;
	double	g;
	double	b;
	double	tr;
	double	tg;
	double	tb;
	double	tmp1;
	double	tmp2;

	if (sat == 0)
	{
		r = lum * 255;
		g = lum * 255;
		b = lum * 255;
		return (get_color(r, g ,b));
	}
	if (lum < 0.5)
		tmp1 = lum * (1 + sat);
	if (lum >= 0.5)
		tmp1 = lum + sat - (lum * sat);
	tmp2 = 2 * lum - tmp1;
	hue = hue / 360;
	tr = scalor01(hue + 0.333);
	tg = scalor01(hue);
	tb = scalor01(hue - 0.333);
	r = color_testator(tr, tmp1, tmp2);
	g = color_testator(tg, tmp1, tmp2);
	b = color_testator(tb, tmp1, tmp2);
	r = r * 255;
	g = g * 255;
	b = b * 255;
	return (get_color(r, g,b));
}

/*
unsigned int		escape_counter(int i, double zr, double zi)
{
	double ec;

	ec = i + 1 - log( log ( ))
	return (0);
}*/

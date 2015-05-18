/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 22:26:39 by jromagna          #+#    #+#             */
/*   Updated: 2015/05/08 22:26:41 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			p(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void		calculator2(t_sup *sup)
{
	static	int x;
	static	int y;
	double	dy;
	t_point	p1;
	t_point	p2;

	x = 0;
	y = 0;

	dy = tan(M_PI/5.5) * sup->SCALE;
	while (y < sup->yl)
	{
		x = 0;
		while (x < sup->xl)
		{
			p1.x = sup->simg->mvx + x * sup->SCALE + X_POS;
			p1.y = sup->simg->mvy + y * sup->SCALE - (sup->env->tab[y][x] * dy / p(sup->zmult));
			if (x + 1 < sup->xl)
			{
				p2.x = sup->simg->mvx + (x + 1) * sup->SCALE + X_POS ;
				p2.y = sup->simg->mvy + y * sup->SCALE - (sup->env->tab[y][x + 1] * dy / p(sup->zmult));
				ft_put_line(sup, &p1, &p2);
			}
			if (y + 1 < sup->yl)
			{
				p2.x = sup->simg->mvx + x * sup->SCALE + X_POS;
				p2.y = sup->simg->mvy + (y + 1) * sup->SCALE - (sup->env->tab[y + 1][x] * dy / p(sup->zmult));
				ft_put_line(sup, &p1, &p2);
			}
			x++;
		}
		y++;
	}
}




void		calculator(t_sup *sup)
{
	static	int x;
	static	int y;
	double	dy;
	t_point	p1;
	t_point	p2;

	x = 0;
	y = 0;

	dy = tan(M_PI/5.5) * sup->SCALE;
	//printf("%f\n", dy);
	while (y < sup->yl)
	{
		x = 0;
		while (x < sup->xl)
		{
			p1.x = sup->simg->mvx + x * sup->SCALE + X_POS - (sup->SCALE * y);
			p1.y = sup->simg->mvy + y * sup->SCALE + Y_POS + (dy * x) - (sup->env->tab[y][x] * dy / p(sup->zmult));
			if (x + 1 < sup->xl)
			{
				p2.x = sup->simg->mvx + (x + 1) * sup->SCALE + X_POS - (sup->SCALE * y);
				p2.y = sup->simg->mvy + y * sup->SCALE + Y_POS + (dy * (x + 1)) - (sup->env->tab[y][x + 1] * dy / p(sup->zmult));
				ft_put_line(sup, &p1, &p2);
			}
			if (y + 1 < sup->yl)
			{
				p2.x = sup->simg->mvx + x * sup->SCALE + X_POS - (sup->SCALE * (y + 1));
				p2.y = sup->simg->mvy + (y + 1) * sup->SCALE + Y_POS + (dy * x) - (sup->env->tab[y + 1][x] * dy / p(sup->zmult));
				ft_put_line(sup, &p1, &p2);
			}
			x++;
		}
		y++;
	}
}

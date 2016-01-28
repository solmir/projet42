/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 23:46:14 by jromagna          #+#    #+#             */
/*   Updated: 2015/06/07 23:46:15 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			p(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void		calculator2_aux(t_env *e, int x, int y, t_cal *c)
{
	c->p1.x = e->mvx + x * e->scale + X_POS;
	c->p1.y = e->mvy + y * e->scale - (e->t[y][x] * c->dy / p(e->zmult));
	if (x + 1 < e->maplx)
	{
		c->p2.x = e->mvx + (x + 1) * e->scale + X_POS;
		c->p2.y = e->mvy + y * e->scale - (e->t[y][x + 1] * c->dy
			/ p(e->zmult));
		ft_put_line(e, &c->p1, &c->p2);
	}
	if (y + 1 < e->maply)
	{
		c->p2.x = e->mvx + x * e->scale + X_POS;
		c->p2.y = e->mvy + (y + 1) * e->scale - (e->t[y + 1][x]
		* c->dy / p(e->zmult));
		ft_put_line(e, &c->p1, &c->p2);
	}
}

void		calculator2(t_env *e)
{
	static int	x;
	static int	y;
	t_cal		c;

	x = 0;
	y = 0;
	c.dy = tan(M_PI / 5.5) * e->scale;
	while (y < e->maply)
	{
		x = 0;
		while (x < e->maplx)
		{
			calculator2_aux(e, x, y, &c);
			x++;
		}
		y++;
	}
}

void		calculator_aux(t_env *e, int x, int y, t_cal *c)
{
	c->p1.x = e->mvx + x * e->scale + X_POS - (e->scale * y);
	c->p1.y = e->mvy + y * e->scale + Y_POS + (c->dy * x) -
	(e->t[y][x] * c->dy / p(e->zmult));
	if (x + 1 < e->maplx)
	{
		c->p2.x = e->mvx + (x + 1) * e->scale + X_POS - (e->scale * y);
		c->p2.y = e->mvy + y * e->scale + Y_POS + (c->dy * (x + 1)) -
		(e->t[y][x + 1] * c->dy / p(e->zmult));
		ft_put_line(e, &c->p1, &c->p2);
	}
	if (y + 1 < e->maply)
	{
		c->p2.x = e->mvx + x * e->scale + X_POS - (e->scale * (y + 1));
		c->p2.y = e->mvy + (y + 1) * e->scale + Y_POS + (c->dy * x) -
		(e->t[y + 1][x] * c->dy / p(e->zmult));
		ft_put_line(e, &c->p1, &c->p2);
	}
}

void		calculator(t_env *e)
{
	static int	x;
	static int	y;
	t_cal		c;

	x = 0;
	y = 0;
	c.dy = tan(M_PI / 5.5) * e->scale;
	while (y < e->maply)
	{
		x = 0;
		while (x < e->maplx)
		{
			calculator_aux(e, x, y, &c);
			x++;
		}
		y++;
	}
}

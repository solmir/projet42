/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 23:57:43 by jromagna          #+#    #+#             */
/*   Updated: 2015/06/07 23:57:45 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move2(t_env *e)
{
	if (e->pressed & (1 << BIG))
	{
		e->scale += e->scalespeed;
		e->scale = (e->scale > 100) ? 100 : e->scale;
	}
	if (e->pressed & (1 << SMALL))
	{
		e->scale -= e->scalespeed;
		e->scale = (e->scale < -100) ? -100 : e->scale;
	}
	if (e->pressed & (1 << ZP))
	{
		e->zmult -= 1;
		e->zmult = (e->zmult < 2) ? 2 : e->zmult;
	}
	if (e->pressed & (1 << ZM))
	{
		e->zmult += 1;
		e->zmult = (e->zmult > 100) ? 100 : e->zmult;
	}
}

void	move(t_env *e)
{
	if (e->pressed & (1 << DOWN))
		e->mvy = verifh(e->mvy + H_SIZE / 100);
	if (e->pressed & (1 << UP))
		e->mvy = verifh(e->mvy - H_SIZE / 100);
	if (e->pressed & (1 << RIGHT))
		e->mvx = verifl(e->mvx + L_SIZE / 100);
	if (e->pressed & (1 << LEFT))
		e->mvx = verifl(e->mvx - L_SIZE / 100);
	move2(e);
}

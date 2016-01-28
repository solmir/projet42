/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 22:22:05 by jromagna          #+#    #+#             */
/*   Updated: 2015/05/26 22:22:05 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	move2(t_env *e, double vitmarche)
{
	if (e->pressed & (1 << FORWARD))
	{
		if (e->t[(int)(e->posx + e->dirx * vitmarche)][(int)(e->posy)] == 0)
			e->posx += e->dirx * vitmarche;
		if (e->t[(int)(e->posx)][(int)(e->posy + e->diry * vitmarche)] == 0)
			e->posy += e->diry * vitmarche;
	}
	if (e->pressed & (1 << RIGHT))
	{
		if (e->t[(int)(e->posx + e->planex * vitmarche)][(int)(e->posy)] == 0)
			e->posx += e->planex * vitmarche;
		if (e->t[(int)(e->posx)][(int)(e->posy + e->planey * vitmarche)] == 0)
			e->posy += e->planey * vitmarche;
	}
	if (e->pressed & (1 << LEFT))
	{
		if (e->t[(int)(e->posx - e->planex * vitmarche)][(int)(e->posy)] == 0)
			e->posx -= e->planex * vitmarche;
		if (e->t[(int)(e->posx)][(int)(e->posy - e->planey * vitmarche)] == 0)
			e->posy -= e->planey * vitmarche;
	}
}

void	move(t_env *e)
{
	double	olddirx;
	double	oldplanex;
	double	vitmarche;

	vitmarche = 0;
	vitmarche = (e->run == 0) ? 0.1 : vitmarche;
	vitmarche = (e->run == 1) ? 0.2 : vitmarche;
	vitmarche = (e->run == 2) ? 0.4 : vitmarche;
	if (e->pressed & (1 << BACK))
	{
		if (e->t[(int)(e->posx - e->dirx * vitmarche)][(int)(e->posy)] == 0)
			e->posx -= e->dirx * vitmarche;
		if (e->t[(int)(e->posx)][(int)(e->posy - e->diry * vitmarche)] == 0)
			e->posy -= e->diry * vitmarche;
	}
	if (e->pressed & (1 << TURN))
	{
		olddirx = e->dirx;
		e->dirx = e->dirx * cos(-e->vitrot) - e->diry * sin(-e->vitrot);
		e->diry = olddirx * sin(-e->vitrot) + e->diry * cos(-e->vitrot);
		oldplanex = e->planex;
		e->planex = e->planex * cos(-e->vitrot) - e->planey * sin(-e->vitrot);
		e->planey = oldplanex * sin(-e->vitrot) + e->planey * cos(-e->vitrot);
	}
	move2(e, vitmarche);
}

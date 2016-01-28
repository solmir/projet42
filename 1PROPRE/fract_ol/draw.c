
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 16:57:59 by jromagna          #+#    #+#             */
/*   Updated: 2015/07/28 16:58:01 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

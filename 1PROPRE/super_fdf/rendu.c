/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 23:54:00 by jromagna          #+#    #+#             */
/*   Updated: 2015/06/07 23:54:02 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					verifh(int i)
{
	if (i > H_SIZE)
		return (i - H_SIZE);
	if (i < 0)
		return (i + H_SIZE);
	return (i);
}

int					verifl(int i)
{
	if (i > L_SIZE)
		return (i - L_SIZE);
	if (i < 0)
		return (i + L_SIZE);
	return (i);
}

inline static void	l_put_line(t_env *e, int i[10])
{
	i[5] = i[1] / 2;
	i[2] = 1;
	while (i[2] <= i[1])
	{
		i[7] += i[4];
		i[5] += i[0];
		if (i[5] >= i[1])
		{
			i[5] -= i[1];
			i[6] += i[3];
		}
		pixel_to_image(e, i[6], i[7], e->lcolor);
		i[2]++;
	}
}

inline static void	r_put_line(t_env *e, int i[10])
{
	i[5] = i[0] / 2;
	i[2] = 1;
	while (i[2] <= i[0])
	{
		i[6] += i[3];
		i[5] += i[1];
		if (i[5] >= i[0])
		{
			i[5] -= i[0];
			i[7] += i[4];
		}
		pixel_to_image(e, i[6], i[7], e->rcolor);
		i[2]++;
	}
}

inline void			ft_put_line(t_env *e, t_point *p1, t_point *p2)
{
	register int	i[8];

	i[6] = p1->x;
	i[7] = p1->y;
	i[0] = p2->x - p1->x;
	i[1] = p2->y - p1->y;
	i[3] = (i[0] > 0) ? 1 : -1;
	i[4] = (i[1] > 0) ? 1 : -1;
	i[0] = ABS(i[0]);
	i[1] = ABS(i[1]);
	if (p1 && p2)
	{
		if (i[0] > i[1])
			r_put_line(e, i);
		else
			l_put_line(e, i);
	}
}

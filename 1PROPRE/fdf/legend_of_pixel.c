/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend_of_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 18:32:02 by jromagna          #+#    #+#             */
/*   Updated: 2015/04/15 18:32:03 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>
#include <stdlib.h>
/*
#define BLUE(x)			(x & 0x0000FF)
#define GREEN(x)		((x >> 8) & 0x0000FF)
#define RED(x)			((x >> 16) & 0x0000FF)

#define RGB(r, g, b)	((b << 0) | (g << 8) | (r << 16))
#define RGBG(g)			((g << 0) | (g << 8) | (g << 16))

#define DELBLUE(x)		(x & ~0x0000FF)
#define DELGREEN(x)		(x & ~0x00FF00)
#define DELRED(x)		(x & ~0xFF0000)

#define GRAY(x)			RGBG(((BLUE(x) + GREEN(x) + RED(x)) / 3))

#define INCRED(x, i)	(RGB((RED(x) + i), GREEN(x), BLUE(x)))
#define INCGREEN(x, i)	(RGB(RED(x), (GREEN(x) + i), BLUE(x)))
#define INCBLUE(x, i)	(RGB(RED(x), GREEN(x), (BLUE(x) + i)))

int		main(void)
{
	unsigned long	a;
	printf("entrez un chiffre: 0x");
	scanf("%lx", &a);
	printf("red = %lu\n", RED(a));
	printf("green = %lu\n", GREEN(a));
	printf("blue = %lu\n", BLUE(a));
	printf("rgb = 0x%.6lX\n", RGB(RED(a), GREEN(a), BLUE(a)));
	printf("\ndelred = 0x%.6lX\n", DELRED(a));
	printf("delgreen = 0x%.6lX\n", DELGREEN(a));
	printf("delblue = 0x%.6lX\n", DELBLUE(a));
	printf("\ngray = 0x%.6lx\n", GRAY(a));
	printf("incred 5 = 0x%.6lx\n", INCRED(a, 5));
	printf("incgreen 5 = 0x%.6lx\n", INCGREEN(a, 5));
	printf("incblue 5 = 0x%.6lx\n", INCBLUE(a, 5));
}*/

int 		verifH(int i)
{
	if (i > H_SIZE)
		return (i - H_SIZE);
	if (i < 0)
		return (i + H_SIZE);
	return (i);
}

int 		verifL(int i)
{
	if (i > L_SIZE)
		return (i - L_SIZE);
	if (i < 0)
		return (i + L_SIZE);
	return (i);
}

#define ABS(x) (x < 0) ? -x : x

inline static void	l_put_line(t_sup *e, int i[10])
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
		pixel_to_image(e, i[6], i[7], e->simg->lcolor);
		i[2]++;
	}
}

inline static void	r_put_line(t_sup *e, int i[10])
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
		pixel_to_image(e, i[6], i[7], e->simg->rcolor);
		i[2]++;
	}
}

inline void		ft_put_line(t_sup *e, t_point *p1, t_point *p2)
{
	register int	i[10];

	i[6] = p1->x;
	i[7] = p1->y;
	i[0] = p2->x - p1->x;
	i[1] = p2->y - p1->y;
	i[3] = (i[0] > 0) ? 1 : -1;
	i[4] = (i[1] > 0) ? 1 : -1;
	i[0] = ABS(i[0]);
	i[1] = ABS(i[1]);
	i[8] = p1->z;
	i[9] = p2->z;
	if (p1 && p2)
	{
		//pixel_to_image(e->simg, i[6], i[7], 0xFF0000);
		if (i[0] > i[1])
			r_put_line(e, i);
		else
			l_put_line(e, i);
	}
}
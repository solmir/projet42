/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 18:37:33 by jromagna          #+#    #+#             */
/*   Updated: 2015/11/19 18:37:34 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"



double	fatoi_aux(char *str, double *si)
{
	int	i;
	double	k;

	i = 0;
	k = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	if (*si == 0)
		*si = (str[i - 1] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + str[i] - '0';
		i++;
	}
	return (k);
}

double	ft_fatoi(char *s)
{
	double	d1;
	double	d2;
	int		i;
	double	si;

	i = 0;
	d2 = 0;
	si = 0;
	d1 = fatoi_aux(s, &si);
	while(s[i] && s[i] != '.')
		i++;
	if (s[i] && s[i] == '.')
		d2 = fatoi_aux(&s[i + 1], &si);
	while (d2 > 1)
		d2 /= 10;
	//printf("s = %f d1 = %f d2 = %f\n",si, d1 ,d2);
	printf("fatoi = %f\n\n", si * (d1 + d2));
	return (si * (d1 + d2));
}

double	carre(double x)
{
	return (x * x);
}

void	set_inter_pos(t_inter *inter, t_pd *pd)
{
	inter->pos->x = (pd->pos->x + (pd->dir->x * inter->t));
	inter->pos->y = (pd->pos->y + (pd->dir->y * inter->t));
	inter->pos->z = (pd->pos->z + (pd->dir->z * inter->t));
}

int		check_t(t_inter *inter, double t)
{

	//ft_putendl("check t");
//	printf("IUHIPUHGIUO%f %f\n", inter->t, t);
	//ft_putendl("check t");
	if ((inter->t > t && t > 0) || inter->t < 0)
	{
		inter->t = t;
		//ft_putstr(".");
		//printf("%f\n", inter->t);
		return (1);
	}
	//ft_putendl("pas contact");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 21:32:53 by jromagna          #+#    #+#             */
/*   Updated: 2015/10/12 21:32:54 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
/*
double	l_color(double i, double a)
{
	if ((i - a) >= 0)
		return (i - a);
	return (i);
}
*//*
void	normalizator(t_vec *vec)
{
	double	lenght;

	lenght = sqrt(carre(vec->x) + carre(vec->y) + carre(vec->z));
	vec->x = vec->x / lenght;
	vec->y = vec->y / lenght;
	vec->z = vec->z / lenght;
}

unsigned int	get_color(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}
*/
int		interceptor(t_env *e, t_pd *l)
{
	double	x;
	double	y;
	double	z;

	x = (l->pos->x + (l->dir->x * e->tl));
	y = (l->pos->y + (l->dir->y * e->tl));
	z = (l->pos->z + (l->dir->z * e->tl));
//	printf("x = %f y = %f z = %f\nposx %f poxy%f posz%f\n ", x, y, z, e->pos->x, e->pos->y, e->pos->z);
	if (e->pos->x == x && e->pos->y == y && e->pos->z == z)
		return (1);
	return (0);
}

void	get_light(t_env *e)
{
	t_pd				*lvec;
	double				angle;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;

	lvec = new_t_pd();
	lvec->pos = e->light->pos;
	lvec->dir = new_t_vec(e->pos->x - e->light->pos->x, e->pos->y - e->light->pos->y, e->pos->z - e->light->pos->z);
	normalizator(lvec->dir);
	e->tl = check_stuff(e, lvec);
	//interceptor(e, lvec);
	if (interceptor(e, lvec) == 1)
	{
		//ft_putnbr(interceptor(e, lvec));
		e->color = 0xFF00FF;
		return ;
	}
	normalizator(e->norm);
	//printf("nx = %f ny = %f nz = %f\n", e->norm->x, e->norm->y, e->norm->z);
	angle = (lvec->dir->x * e->norm->x) + (lvec->dir->y * e->norm->y) + (lvec->dir->z * e->norm->z);
	angle = acos(angle);
	angle = fabs(angle * 180 / M_PI);
	angle = angle / 360 * 256;
	angle = l_color(256, angle);
	//printf("%f\n", angle);
	if (angle > 0)
		{
			r = l_color(e->mat->diff->r * (e->light->color & 0xFF0000), angle);
			g = l_color(e->mat->diff->g * (e->light->color & 0x00FF00), angle);
			b = l_color(e->mat->diff->b * (e->light->color & 0x0000FF), angle);
			e->color = get_color(r, g, b);
		}
	/*else
	{
		printf("%f\n", angle);
		e->color = 0x00FF00;
	}*/
}
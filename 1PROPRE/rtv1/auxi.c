/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 18:01:43 by jromagna          #+#    #+#             */
/*   Updated: 2015/09/28 18:01:44 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_normal_plane(t_env *e)
{
	e->norm->x = e->lst->pl->d->x;
	e->norm->y = e->lst->pl->d->y;
	e->norm->z = e->lst->pl->d->z;
}

void	set_normal_sphere(t_env *e)
{
	e->norm->x = (e->cam->pos->x + (e->cam->dir->x * e->ti)) - e->lst->sp->c->x;
	e->norm->y = (e->cam->pos->y + (e->cam->dir->y * e->ti)) - e->lst->sp->c->y;
	e->norm->z = (e->cam->pos->z + (e->cam->dir->z * e->ti)) - e->lst->sp->c->z;
}

void	set_inter_pos(t_env *e)
{
	e->pos->x = (e->cam->pos->x + (e->cam->dir->x * e->ti));
	e->pos->y = (e->cam->pos->y + (e->cam->dir->y * e->ti));
	e->pos->z = (e->cam->pos->z + (e->cam->dir->z * e->ti));
}

int		check_t(t_env *e, double t)
{
	if ((e->ttmp > t && t > 0) || e->ttmp == 0)
	{
		e->ttmp = t;
		return (1);
	}
	return (0);
}

double	carre(double x)
{
	return (x * x);
}

void		check_plane(t_env *e, t_pd *s)
{
	double	t;
	double	x;
	double	y;
	double	z;

	x = s->pos->x - e->lst->pl->p->x;
	y = s->pos->y - e->lst->pl->p->y;
	z = s->pos->z - e->lst->pl->p->z;
	t = -((e->lst->pl->d->x * x + e->lst->pl->d->y * y + e->lst->pl->d->z * z)
		/ (e->lst->pl->d->x * s->dir->x + e->lst->pl->d->y
			* s->dir->y + e->lst->pl->d->z * s->dir->z));
	if (check_t(e, t) == 1)
		set_normal_plane(e);
	return ;
}

void		check_sphere(t_env *e, t_pd *s)
{
	double	a;
	double	b;
	double	c;
	double	del;
	double	t;

	a = carre(s->dir->x) + carre(s->dir->y) + carre(s->dir->z);

	b = 2 * (s->dir->x * (s->pos->x - e->lst->sp->c->x) + s->dir->y
	* (s->pos->y - e->lst->sp->c->y) + s->dir->z * (s->pos->z - e->lst->sp->c->z));

	c = (carre(s->pos->x - e->lst->sp->c->x) + carre(s->pos->y - e->lst->sp->c->y) +
		carre(s->pos->z - e->lst->sp->c->z)) - carre(e->lst->sp->ray);
	del = carre(b) - (4 * a * c);
	//printf("a= %f b= %f c= %f\ndelta =%f\n", a, b, c, del);
	if (del == 0)
	{
		t = -b / (2 * a);
		if (check_t(e, t) == 1)
			set_normal_sphere(e);
		return ;
	}
	else if (del > 0)
	{
		t = ((-b + sqrt(del)) / (2 * a) > (-b - sqrt(del)) / (2 * a))?
		(-b - sqrt(del)) / (2 * a) : (-b + sqrt(del)) / (2 * a);
		if (check_t(e, t) == 1)
			set_normal_sphere(e);
		return ;
	}
	return ;
}

double		check_stuff(t_env *env, t_pd *s)
{
	check_sphere(env, s);
	check_plane(env, s);
	return (env->ttmp);
}

int		creator(t_env *env)
{
	int	x;
	int	y;
	double	tmpz;
	double	tmpy;

	tmpz = env->cam->pos->z;
	tmpy = env->cam->pos->y;
	x = 0;
	while (x <= L_SIZE)
	{
		y = 0;
		env->cam->pos->y = tmpy;
		while (y <= H_SIZE)
		{
			env->ti = check_stuff(env, env->cam);
			set_inter_pos(env);
			env->ttmp = 0;
			if (env->ti > 0)
				get_light(env);
			else
				env->color = 0xFF0000;
			pixel_to_image(env, x, y, env->color);
			y++;
			env->cam->pos->y = 0.01 + env->cam->pos->y;
			env->ttmp = 0;
			env->ti = 0;
			env->tl = 0;
			//printf("X = %d\n", x);
		}
		env->cam->pos->z = 0.01 + env->cam->pos->z;
		x++;

	}
	env->cam->pos->y = tmpy;
	env->cam->pos->z = tmpz;
	return (0);
}
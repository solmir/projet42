/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 17:36:31 by jromagna          #+#    #+#             */
/*   Updated: 2015/10/30 17:36:33 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


t_item			*new_t_item()
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	item->pl = NULL;
	item->sp = NULL;
	item->next = NULL;
	return(item);
}

t_item			*fill_t_item(char **t, t_item *item)
{
	if (strcmp(t[0], "sphere") == 0)
	{
		item->sp = new_t_sphere(ft_fatoi(t[1]), ft_fatoi(t[2]),
		ft_fatoi(t[3]), ft_fatoi(t[4]));
		item->mat = new_t_mat(t[5]);
		item->mat->diff = new_t_color(1, 1, 1);
		item->pl = NULL;
	}
	if (strcmp(t[0], "plane") == 0)
	{
		item->pl = t_plane_creator(ft_fatoi(t[1]), ft_fatoi(t[2]),
		ft_fatoi(t[3]), ft_fatoi(t[4]), ft_fatoi(t[5]), ft_fatoi(t[6]));
		item->mat = new_t_mat(t[8]);
		item->mat->diff = new_t_color(1, 1, 1);
		item->sp  = NULL;
	}
	return (item);
}

t_pd			*set_screen(t_pd *cam)
{
	t_pd	*screen;
	t_vec	*up;
	t_vec	*right;
	t_vec	tmp;

	up = new_t_vec(0, 1, 0);
	right = new_t_vec(cam->dir->z, 0, -cam->dir->x);
	screen = new_t_pd();
	tmp.x = cam->pos->x + cam->dir->x + right->x * L_IND - up->x * H_IND;
	tmp.y = cam->pos->y + cam->dir->y + right->y * L_IND - up->y * H_IND;
	tmp.z = cam->pos->z + cam->dir->z + right->z * L_IND - up->z * H_IND;
	screen->dir = new_t_vec(tmp.x - cam->pos->x, tmp.y - cam->pos->y, tmp.z
		- cam->pos->z);
	screen->pos = new_t_vec(tmp.x - cam->pos->x, tmp.y - cam->pos->y, tmp.z
		- cam->pos->z);
	return (screen);
}

t_pd			*set_cam(char **t)
{
	t_pd	*cam;

	cam = new_t_pd();
	cam->pos = new_t_vec(ft_fatoi(t[1]), ft_fatoi(t[2]), ft_fatoi(t[3]));
	cam->dir = new_t_vec(ft_fatoi(t[4]), 0/*ft_fatoi(t[5])*/, ft_fatoi(t[6]));
	return (cam);
}

void			check_check(t_check check)
{
	if (check.cam == 0)
		ft_error("ray charles");
	if (check.item == 0)
		ft_error("no toy");
	if (check.light == 0)
		ft_error("the sun is broken");
}

int				tlen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void			get_file(t_env *e, char *name)
{
	char	*line;
	char	**t;
	int		fd;
	t_check	check;
	t_item	*item;
	t_light	*light;
	int		i;


	i = 0;
	check.cam = 0;
	check.item = 0;
	check.light = 0;
	e->item = new_t_item();
	item = e->item;
	e->light = new_t_light();
	light = e->light;
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error("error");
	while (get_next_line(fd, &line) > 0)
	{
		printf("ligne gnl%d = %s\n", i, line);
		i++;
		t = ft_strsplit(line, ' ');
		if (strcmp(t[0], "cam") == 0)
		{
			ft_putendl("CAM");
			if (tlen(t) != 7)
				ft_error("mauvais format de fichier1");
			e->cam = set_cam(t);
			e->screen = set_screen(e->cam);
			check.cam++;
		}
		else if (strcmp(t[0], "sphere") == 0 || strcmp(t[0], "plane") == 0)
		{
			ft_putendl("ITEM");
			if (strcmp(t[0], "sphere") == 0 && tlen(t) != 6)
				ft_error("mauvais format de fichier2");
			if (strcmp(t[0], "plane") == 0 && tlen(t) != 8)
				ft_error("mauvais format de fichier3");
			check.item++;
			if (e->item->next != NULL)
				e->item = e->item->next;
			e->item = fill_t_item(t, e->item);
			e->item->next = new_t_item();
		}
		else if (strcmp(t[0], "lum") == 0)
		{
			ft_putendl("LIGHT");
			if (tlen(t) != 7)
				ft_error("mauvais format de fichier4");
			check.light++;
			if (e->light->next != NULL)
				e->light = e->light->next;
			e->light = fill_t_light(t, e->light);
			e->light->next = new_t_light();
		}
		else
			ft_error("mauvais format de fichier5");
	}
	e->light->next = NULL;
	e->item->next = NULL;
	e->light = light;
	e->item = item;
	check_check(check);
}

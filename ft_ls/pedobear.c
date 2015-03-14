/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 19:11:07 by jromagna          #+#    #+#             */
/*   Updated: 2015/01/15 19:11:09 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bloc			*ft_pedobear(t_bloc *bloc, dev_t dev)
{
	int		maj;
	int		min;
	char	*majmin;
	int		lenght;
	int		i;

	i = 0;
	lenght = 0;
	maj = major(dev);
	min = minor(dev);
	majmin = ft_strdup(ft_itoa(maj));
	majmin = ft_strjoin(majmin, ",");
	lenght = ft_strlen(ft_itoa(min));
	while ((4 - i - lenght) != 0)
	{
		majmin = ft_strjoin(majmin, " ");
		i++;
	}
	majmin = ft_strjoin(majmin, ft_itoa(min));
	bloc->size = ft_strdup(majmin);
	return (bloc);
}

t_bloc			*t_bloc_filler_link(t_bloc *bloc)
{
	char	*buf;
	int		buffsize;

	buffsize = 4096;
	buf = (char*)malloc(sizeof(char) * buffsize);
	errno = 0;
	if ((readlink(bloc->path, buf, buffsize)) == -1)
		ft_puterror(strerror(errno), bloc->path);
	bloc->name = ft_strjoin(bloc->name, " -> ");
	bloc->name = ft_strjoin(bloc->name, buf);
	return (bloc);
}

t_bloc			*path_finder(t_bloc *dir, t_bloc *bloc)
{
	if (bloc->path == NULL)
		bloc->path = ft_strdup(bloc->name);
	dir->path = ft_strjoin(bloc->path, "/");
	dir->path = ft_strjoin(dir->path, dir->name);
	return (dir);
}

t_bloc			*bloc_dup(t_bloc *bloc)
{
	t_bloc	*dup;

	dup = new_bloc();
	dup->name = ft_strdup(bloc->name);
	dup->bufpass = bloc->bufpass;
	dup->bufgrp = bloc->bufgrp;
	dup->droit = ft_strdup(bloc->droit);
	dup->link = ft_strdup(bloc->link);
	dup->realtime = bloc->realtime;
	dup->time = ft_strdup(bloc->time);
	dup->block = bloc->block;
	dup->path = bloc->path;
	dup->size = ft_strdup(bloc->size);
	return (dup);
}

t_lstruct		*ft_putpath_error(t_lstruct *opt, t_bloc *bloc)
{
	if (verificator_path(bloc->path, opt) == 1)
	{
		if (opt->nbr == 0 && opt->optgr == 1 && opt->nbrdir < 2)
			opt->nbr++;
		else
		{
			if (opt->nbr > 0)
			{
				ft_putchar_fd ('\n', 2);
			}
			ft_putstr_fd(bloc->path, 2);
			ft_putendl_fd(":", 2);
			opt->nbr++;
		}
	}
	return (opt);
}

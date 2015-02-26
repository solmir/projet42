/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 19:11:38 by jromagna          #+#    #+#             */
/*   Updated: 2015/01/15 19:11:39 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bloc		*t_bloc_filler_l(t_bloc *bloc)
{
	struct stat buf;

	errno = 0;
	if (lstat(bloc->path, &buf) == -1)
	{
		ft_puterror(strerror(errno), bloc->path);
		bloc->inde = 1;
	}
	else
	{
		bloc->inde = 0;
		bloc->block = buf.st_blocks;
		bloc->st_uid = buf.st_uid;
		bloc->st_gid = buf.st_gid;
		bloc->droit = ft_strdup(file_tes_droits(&buf));
		bloc->bufpass = getpwuid(buf.st_uid);
		bloc->bufgrp = getgrgid(buf.st_gid);
		bloc->size = ft_itoa(buf.st_size);
		bloc->realtime = buf.st_mtime;
		bloc->time = ft_strdup(ctime((const time_t*)(&(buf.st_mtime))));
		bloc->link = ft_itoa(buf.st_nlink);
		if ((bloc->droit[0] == 'c' || bloc->droit[0] == 'b') && bloc->name != NULL)
			bloc = ft_pedobear(bloc, buf.st_rdev);
		bloc = uidgid(bloc);
	}
	return (bloc);
}

t_bloc 		*uidgid(t_bloc *bloc)
{
	if (bloc->bufpass == NULL)
	{
		bloc->bufpass = malloc(sizeof(struct passwd));
		bloc->bufpass->pw_name = ft_strdup(ft_itoa(bloc->st_uid));
	}
	if (bloc->bufgrp == NULL)
	{
		bloc->bufgrp = malloc(sizeof(struct group));
		bloc->bufgrp->gr_name = ft_strdup(ft_itoa(bloc->st_gid));
	}
	return(bloc);
}
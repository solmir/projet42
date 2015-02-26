/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 19:11:19 by jromagna          #+#    #+#             */
/*   Updated: 2015/01/15 19:11:22 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bloc		*path_finder(t_bloc *dir, t_bloc *bloc)
{
	if (bloc->path == NULL)
		bloc->path = ft_strdup(bloc->name);
	dir->path = ft_strjoin(bloc->path, "/");
	dir->path = ft_strjoin(dir->path, dir->name);
	return (dir);
}

t_bloc		*bloc_dup(t_bloc *bloc)
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

t_bloc		*bloc_cpy(t_bloc *dst, t_bloc *src)
{
	dst->name = ft_strdup(src->name);
	dst->path = src->path;
	dst->bufpass = src->bufpass;
	dst->bufgrp = src->bufgrp;
	dst->droit = ft_strdup(src->droit);
	dst->link = ft_strdup(src->link);
	dst->realtime = src->realtime;
	dst->time = ft_strdup(src->time);
	dst->block = src->block;
	dst->size = ft_strdup(src->size);
	return (dst);
}

char		*file_ton_type(struct stat *buf,char *droit)
{
	mode_t  mode;

	mode = buf->st_mode;
	if	(S_ISREG(mode))
		return (droit);
	S_ISLNK(mode) ? droit[0] = 'l' : '-';
	S_ISBLK(mode) ? droit[0] = 'b' : '-';
	S_ISSOCK(mode) ? droit[0] = 's' : '-';
	S_ISFIFO(mode) ? droit[0] = 'p' : '-';
	S_ISCHR(mode) ? droit[0] = 'c' : '-';
	S_ISDIR(mode) ? droit[0] = 'd' : '-';

	return (droit);
}

char    *file_tes_droits(struct stat *buf)
{
	char    *droit;
	mode_t  mode;

	mode = buf->st_mode;
	droit = malloc(sizeof(char) * 12);
	droit = ft_memset(droit, '-', 10);
	droit = file_ton_type(buf, droit);
	(mode & S_IRUSR) ? droit[1] = 'r' : '-';
	(mode & S_IWUSR) ? droit[2] = 'w' : '-';
	(mode & S_IXUSR) ? droit[3] = 'x' : '-';
	if (droit[3] == 'x')
		(mode & S_ISUID) ? droit[3] = 's' : 'x';
	else
		(mode & S_ISUID) ? droit[3] = 'S' : '-';
	(mode & S_IRGRP) ? droit[4] = 'r' : '-';
	(mode & S_IWGRP) ? droit[5] = 'w' : '-';
	(mode & S_IXGRP) ? droit[6] = 'x' : '-';
	if (droit[6] == 'x')
		(mode & S_ISGID) ? droit[6] = 's' : 'x';
	else
		(mode & S_ISGID) ? droit[6] = 'S' : '-';
	(mode & S_IROTH) ? droit[7] = 'r' : '-';
	(mode & S_IWOTH) ? droit[8] = 'w' : '-';
	(mode & S_IXOTH) ? droit[9] = 'x' : '-';
	if (droit[9] == 'x')
		(mode & S_ISVTX) ? droit[9] = 't' : 'x';
	else
		(mode & S_ISVTX) ? droit[9] = 'T' : '-';
	droit[10] = ' ';
	droit[11] = '\0';
	return (droit);
}


t_bloc		*t_bloc_filler(t_bloc *bloc)
{
	struct stat buf;

	errno = 0;
	if (stat(bloc->path, &buf) == -1)
	{
		if (lstat(bloc->path, &buf) == -1)
		{
			ft_puterror(strerror(errno), bloc->path);
			bloc->inde = 1;
			return (bloc);
		}
	}
	bloc->inde = 0;
	bloc->block = buf.st_blocks;
	bloc->droit = ft_strdup(file_tes_droits(&buf));
	bloc->bufpass = getpwuid(buf.st_uid);
	bloc->bufgrp = getgrgid(buf.st_gid);
	bloc->size = ft_itoa(buf.st_size);
	bloc->realtime = buf.st_mtime;
	bloc->time = ft_strdup(ctime((const time_t*)(&(buf.st_mtime))));
	bloc->link = ft_itoa(buf.st_nlink);
	if ((bloc->droit[0] == 'c' || bloc->droit[0] == 'b') && bloc->name != NULL)
		bloc = ft_pedobear(bloc, buf.st_rdev);
	return (bloc);
}

t_bloc		*t_bloc_filler_link(t_bloc *bloc)
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

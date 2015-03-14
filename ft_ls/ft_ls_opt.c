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

void		ft_puterror(char *error, char *name)
{
	ft_putstr_fd("ls: ", 2);
	if (ft_strcmp(name, "") == 0)
		ft_putstr_fd("fts_open", 2);
	else
		ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error, 2);
}

void		dir_opener(t_lstruct *opt, t_bloc *bloc)
{
	t_bloc			*tmp;
	t_bloc			*dir;
	DIR				*pt;

	if (opt->optgr == 1 && opt->optr == 1)
		bloc = retournator(bloc);
	while (bloc != NULL && bloc->name != NULL)
	{
		errno = 0;
		tmp = bloc;
		dir = new_bloc();
		pt = opendir(bloc->path);
		if (errno != 0)
		{
			opt = ft_putpath_error(opt, bloc);
			ft_puterror(strerror(errno), bloc->path);
		}
		else
			open_2(opt, dir, tmp, pt);
		if (pt != NULL)
			closedir(pt);
		bloc = bloc->next;
	}
}

void		open_2(t_lstruct *opt, t_bloc *dir, t_bloc *bloc, DIR *pt)
{
	t_bloc			*tmpdir;
	t_bloc			*tmp;
	struct dirent	*drent;

	tmp = bloc;
	tmpdir = dir;
	if (opt->nbrdir > 1 || opt->optgr == 1)
		opt = ft_putpath(opt, bloc);
	while ((drent = readdir(pt)) != 0)
	{
		dir->name = ft_strdup(drent->d_name);
		dir = path_finder(dir, bloc);
		if (opt->optl == 1 || opt->optt == 1)
			dir = t_bloc_filler_l(dir);
		else
			dir = t_bloc_filler(dir);
		dir->next = new_bloc();
		dir = dir->next;
	}
	dirigeator(opt, tmpdir, tmp);
}

void		dirigeator(t_lstruct *opt, t_bloc *dir, t_bloc *bloc)
{
	t_bloc		*blocpoint;

	dir = alpha_list(dir);
	if (opt->optgr == 1)
		blocpoint = director(dir);
	if (opt->optt == 1)
		dir = time_attack(dir);
	if (opt->optl == 1)
		dir = colonisator(dir, opt);
	if (opt->optr == 1)
		dir = retournator(dir);
	if (opt->optgr == 1)
		opt = ft_putlist_gr(opt, dir, bloc);
	else if (opt->nbrdir > 1)
		opt = ft_putlist_mul(opt, dir, bloc);
	else
		opt = ft_putlst(opt, dir);
	if (opt->optgr == 1)
		pre_optr(blocpoint, opt, bloc);
}

t_bloc		*dup_name_path(t_bloc *tmp)
{
	t_bloc	*tmptmp;

	tmptmp = tmp;
	while (tmp != NULL && tmp->name != NULL)
	{
		if (tmp->name != NULL)
			tmp->path = ft_strdup(tmp->name);
		tmp = tmp->next;
	}
	return (tmptmp);
}

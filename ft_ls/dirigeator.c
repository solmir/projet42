/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirigeator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 20:16:52 by jromagna          #+#    #+#             */
/*   Updated: 2015/01/15 20:17:08 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_ls(t_lstruct *opt, t_bloc *bloc)
{
	t_bloc	*file;
	t_bloc	*dir;
	t_bloc	*tmp;

	tmp = bloc;
	file = new_bloc();
	dir = new_bloc();
	while (bloc != NULL && bloc->name != NULL)
	{
		bloc = t_bloc_filler(bloc);
		opt->nbrdir++;
		bloc = bloc->next;
	}
	bloc = tmp;
	if ((bloc = decoupator(bloc)) == NULL)
		exit (1);
	if (bloc != NULL && bloc->name != NULL)
		file = filator(bloc);
	if (bloc != NULL && bloc->name != NULL)
		dir = director_pre(bloc);
	tmp = new_bloc();
	tmp->name = ft_strdup(".");
	tmp->path = ft_strdup(".");
	opt->tot = 1;
	if (file != NULL && file->name != NULL)
		dirigeator(opt, file, tmp);
	if (opt->tot == 1)
		opt->tot = 0;
	if (dir != NULL && dir->name != NULL)
		dir_opener(opt, dir);
}

t_bloc		*filator(t_bloc *bloc)
{
	t_bloc  *dir;
	t_bloc  *tmp;
		   
	dir = new_bloc();
	tmp = dir;
	while (bloc != NULL && bloc->name != NULL)
	{
		if (bloc->droit[0] != 'd')
		{
			dir = bloc_cpy(dir, bloc);
			dir->next = new_bloc();
			dir = dir->next;
		}
		bloc = bloc->next;
	}
	return (tmp);
}

t_bloc		*decoupator(t_bloc *bloc)
{
	t_bloc	*goodlst;
	t_bloc	*tmp;
	int		i;

	i = 0;
	goodlst = new_bloc();
	tmp = goodlst;
	while(bloc != NULL && bloc->name != NULL)
	{
		if (bloc->inde != 1)
		{
			goodlst = bloc_cpy(goodlst, bloc);
			goodlst->next = new_bloc();
			goodlst = goodlst->next;
			i++;
		}
		bloc = bloc->next;
	}
	if (i == 0)
		return (NULL);
	return (tmp);
}

t_bloc		*director_pre(t_bloc *bloc)
{
	t_bloc	*dir;
	t_bloc	*tmp;

	if (!bloc)
		return (NULL);
	dir = new_bloc();
	tmp = dir;
	while (bloc != NULL && bloc->name != NULL)
	{
		if (bloc->droit[0] == 'd')
		{
			dir = bloc_cpy(dir, bloc);
			dir->next = new_bloc();
			dir = dir->next;
		}
		bloc = bloc->next;
	}
	return (tmp);
}

t_bloc		*director(t_bloc *bloc)
{
	t_bloc	*dir;
	t_bloc	*tmp;

	dir = new_bloc();
	tmp = dir;
	while (bloc != NULL && bloc->name != NULL)
	{
		if ((strcmp(bloc->name, ".") != 0) && 
			(strcmp(bloc->name, "..") != 0))
			if (bloc->droit[0] == 'd')
			{
				dir = bloc_cpy(dir, bloc);
				dir->next = new_bloc();
				dir = dir->next;
			}
		bloc = bloc->next;
	}
	return (tmp);
}
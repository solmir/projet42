/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_aux3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 22:55:18 by jromagna          #+#    #+#             */
/*   Updated: 2015/03/11 22:55:21 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

int			pink_ward(t_bloc *bloc, t_lstruct *opt)
{
	if (opt->opta == 1)
		return (1);
	while (bloc != NULL && bloc->name != NULL)
	{
		if (verificator(bloc->name) == 1)
			return (1);
		bloc = bloc->next;
	}
	return (0);
}

int			totverif(t_bloc *bloc, t_lstruct *opt)
{
	int		i;

	i = 0;
	if (opt->opta == 1)
		return (1);
	while (bloc->path[i])
		i++;
	i--;
	while (bloc->path[i] != '/')
		i--;
	i--;
	while (bloc->path[i] != '/')
		i--;
	i++;
	if (bloc->path[i] == '.')
		return (0);
	return (1);
}

t_size		*t_size_builder(void)
{
	t_size	*size;

	size = malloc(sizeof(t_size));
	size->lusr = 0;
	size->lgrp = 0;
	size->llink = 0;
	size->lsize = 0;
	return (size);
}

int			ft_comp_len(t_bloc *bloc, int l, int t, int *w)
{
	int		i;
	char	*str;

	i = 0;
	if (t == 0)
		str = ft_strdup(bloc->bufpass->pw_name);
	else if (t == 1)
		str = ft_strdup(bloc->bufgrp->gr_name);
	else if (t == 2)
		str = ft_strdup(bloc->link);
	else
		str = ft_strdup(bloc->size);
	i = ft_strlen(str);
	if (i > l)
	{
		*w = i;
		return (i);
	}
	*w = 0;
	return (0);
}

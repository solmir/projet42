/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:51:19 by jromagna          #+#    #+#             */
/*   Updated: 2015/01/15 18:51:21 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_size		*t_size_builder()
{
	t_size *size;
	
	size = malloc(sizeof(t_size));
	size->lusr = 0;
	size->lgrp = 0;
	size->llink = 0;
	size->lsize = 0;
	return (size);
}

t_bloc		*colonisator3(t_bloc *bloc)
{
	t_bloc	*tmp;

	tmp = bloc;
	while (bloc != NULL && bloc->name != NULL)
	{
		bloc->name = ft_strjoin(" ", bloc->name);
		bloc->name = ft_strjoin(bloc->time, bloc->name);
		bloc->name = ft_strjoin(bloc->size, bloc->name);
		bloc->name = ft_strjoin("  ", bloc->name);
		bloc->name = ft_strjoin(bloc->bufgrp->gr_name, bloc->name);
		bloc->name = ft_strjoin("  ", bloc->name);
		bloc->name = ft_strjoin(bloc->bufpass->pw_name, bloc->name);
		bloc->name = ft_strjoin(" ", bloc->name);
		bloc->name = ft_strjoin(bloc->link, bloc->name);
		bloc->name = ft_strjoin(" ", bloc->name);
		bloc->name = ft_strjoin(bloc->droit, bloc->name);
		bloc = bloc->next;
	}
	return (tmp);
}

t_bloc		*colonisator2(t_bloc *bloc, t_size *size)
{
	t_bloc	*tmp;

	tmp = bloc;
	while (bloc != NULL && bloc->name != NULL)
	{
		while ((ft_strlen(bloc->bufpass->pw_name)) < (size->lusr))
			bloc->bufpass->pw_name = ft_strjoin(bloc->bufpass->pw_name, " ");
		while ((ft_strlen(bloc->bufgrp->gr_name)) < (size->lgrp))
			bloc->bufgrp->gr_name =  ft_strjoin(bloc->bufgrp->gr_name, " ");
		while ((ft_strlen(bloc->link)) < (size->llink))
			bloc->link = ft_strjoin(" ", bloc->link);
		while ((ft_strlen(bloc->size)) < (size->lsize))
			bloc->size = ft_strjoin(" ", bloc->size);
		bloc = bloc->next;
	}
	bloc = colonisator3(tmp);
   return (bloc);
}

int     calculator(blkcnt_t b, t_lstruct *opt, char point)
{
	if ((opt->opta == 0) && (point == '.'))
		return (0);
	return (b);
}

t_bloc		*colonisator(t_bloc *bloc, t_lstruct *opt)
{
	t_size	*size;
	t_bloc	*tmp;
	int		b;

	b = 0;
	size = t_size_builder();

	tmp = bloc;
	while (bloc != NULL && bloc->name != NULL)
	{
		if (bloc->name[0] != '.' || (opt->opta == 1 && (bloc->name[0] == '.')))
		{
			if (bloc->droit[0] == 'l')
				bloc = t_bloc_filler_link(bloc);
			b = b + calculator(bloc->block, opt, bloc->name[0]);
			bloc->time = time_guardian(bloc->time, bloc->realtime);
			if (ft_strlen(bloc->bufpass->pw_name) > size->lusr)
				size->lusr = (ft_strlen(bloc->bufpass->pw_name));
			if (ft_strlen(bloc->bufgrp->gr_name) > size->lgrp)
				size->lgrp = (ft_strlen(bloc->bufgrp->gr_name));
			if (ft_strlen(bloc->link) > size->llink)
				size->llink = (ft_strlen(bloc->link));
			if (ft_strlen(bloc->size) > size->lsize)
				size->lsize = (ft_strlen(bloc->size));
		}
		bloc = bloc->next;
	}
	bloc = colonisator2(tmp, size);
	if (opt->tot == 0 && bloc->name != NULL)
	{
		ft_putstr("total ");
		ft_putnbr(b);
		ft_putchar('\n');
	}
	return (bloc);
}

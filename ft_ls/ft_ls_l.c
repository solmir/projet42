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

t_bloc	*colonisator3(t_bloc *bloc)
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

t_bloc	*colonisator2(t_bloc *bloc, t_size *size)
{
	t_bloc	*tmp;

	tmp = bloc;
	while (bloc != NULL && bloc->name != NULL)
	{
		while ((ft_strlen(bloc->bufpass->pw_name)) < (size->lusr))
			bloc->bufpass->pw_name = ft_strjoin(bloc->bufpass->pw_name, " ");
		while ((ft_strlen(bloc->bufgrp->gr_name)) < (size->lgrp))
			bloc->bufgrp->gr_name = ft_strjoin(bloc->bufgrp->gr_name, " ");
		while ((ft_strlen(bloc->link)) < (size->llink))
			bloc->link = ft_strjoin(" ", bloc->link);
		while ((ft_strlen(bloc->size)) < (size->lsize))
			bloc->size = ft_strjoin(" ", bloc->size);
		bloc = bloc->next;
	}
	bloc = colonisator3(tmp);
	return (bloc);
}

int		calculator(blkcnt_t b, t_lstruct *opt, char point)
{
	if ((opt->opta == 0) && (point == '.'))
		return (0);
	return (b);
}

t_bloc	*colonisator(t_bloc *bloc, t_lstruct *opt)
{
	t_size	*s;
	t_bloc	*tmp;
	int		b;
	int		i;

	b = 0;
	s = t_size_builder();
	tmp = bloc;
	while (bloc != NULL && bloc->name != NULL)
	{
		if (bloc->name[0] != '.' || (opt->opta == 1))
		{
			if (bloc->droit[0] == 'l')
				bloc = t_bloc_filler_link(bloc);
			b = b + calculator(bloc->block, opt, bloc->name[0]);
			bloc->time = time_guardian(bloc->time, bloc->realtime);
			(ft_comp_len(bloc, s->lusr, 0, &i)) ? s->lusr = i : s->lusr;
			(ft_comp_len(bloc, s->lgrp, 1, &i)) ? s->lgrp = i : s->lgrp;
			(ft_comp_len(bloc, s->llink, 2, &i)) ? s->llink = i : s->llink;
			(ft_comp_len(bloc, s->lsize, 3, &i)) ? s->lsize = i : s->lsize;
		}
		bloc = bloc->next;
	}
	bloc = colonisator2(tmp, s);
	return (put_total(opt, bloc, b));
}

t_bloc	*put_total(t_lstruct *opt, t_bloc *bloc, int b)
{
	if (opt->tot == 0 && bloc->name != NULL && totverif(bloc, opt) == 1
		&& pink_ward(bloc, opt) == 1)
	{
		ft_putstr("total ");
		ft_putnbr(b);
		ft_putchar('\n');
	}
	return (bloc);
}

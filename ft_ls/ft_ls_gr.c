/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_gr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 22:53:57 by jromagna          #+#    #+#             */
/*   Updated: 2015/03/11 22:53:59 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		pre_optr(t_bloc *blocpoint, t_lstruct *opt, t_bloc *bloc)
{
	t_bloc	*tmp;

	tmp = blocpoint;
	while (blocpoint != NULL && blocpoint->name != NULL)
	{
		blocpoint = path_finder(blocpoint, bloc);
		blocpoint = blocpoint->next;
	}
	blocpoint = tmp;
	if (blocpoint->name != NULL)
		dir_opener(opt, blocpoint);
}

t_bloc		*retournator(t_bloc *dir)
{
	t_bloc	*tmp;
	t_bloc	*revdir;

	revdir = new_bloc();
	revdir = bloc_cpy(revdir, dir);
	tmp = revdir;
	dir = dir->next;
	while (dir != NULL && dir->name != NULL)
	{
		revdir = new_bloc();
		revdir = bloc_cpy(revdir, dir);
		revdir->next = tmp;
		tmp = revdir;
		dir = dir->next;
	}
	return (revdir);
}

int			verificator_path(char *tab, t_lstruct *opt)
{
	int		i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	i--;
	while (tab[i] != '/' && tab[i])
		i--;
	i++;
	if (tab[i] == '.' && opt->opta != 1 && strcmp(tab, ".") != 0)
		return (0);
	else if (opt->nbrdir > 1)
		return (1);
	return (1);
}

t_lstruct	*ft_putlist_mul(t_lstruct *opt, t_bloc *lst, t_bloc *bloc)
{
	while (lst != NULL && lst->name != NULL)
	{
		if (opt->opta == 1)
			ft_putendl(lst->name);
		else if (opt->optl == 1)
		{
			if (verificator(lst->name) == 1 && totverif(lst, opt) == 1)
				ft_putendl(lst->name);
		}
		else if ((lst->name[0] != '.' && bloc->name[0] != '.')
			|| (lst->name[0] != '.' && ft_strcmp(bloc->name, ".") == 0)
			|| (lst->name[0] != '.' && ft_strcmp(bloc->name, "./") == 0))
			ft_putendl(lst->name);
		lst = lst->next;
	}
	opt->nbr++;
	return (opt);
}

t_lstruct	*ft_putlist_gr(t_lstruct *opt, t_bloc *lst, t_bloc *bloc)
{
	while (lst != NULL && lst->name != NULL)
	{
		if (opt->opta == 1)
			ft_putendl(lst->name);
		else if (opt->optl == 1)
		{
			if (verificator(lst->name) == 1 && totverif(lst, opt) == 1)
				ft_putendl(lst->name);
		}
		else if ((lst->name[0] != '.' && bloc->name[0] != '.')
			|| (lst->name[0] != '.' && ft_strcmp(bloc->name, ".") == 0))
			ft_putendl(lst->name);
		lst = lst->next;
	}
	opt->nbr++;
	return (opt);
}

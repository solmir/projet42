/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_aux2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 20:10:05 by jromagna          #+#    #+#             */
/*   Updated: 2015/01/15 20:10:20 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bloc			*new_bloc()
{
	t_bloc      *bloc;

	bloc = malloc(sizeof(t_bloc));
	bloc->path = NULL;
	bloc->name = NULL;
	bloc->droit = NULL;
	bloc->link = NULL;
	bloc->time = NULL;
	bloc->size = NULL;
	bloc->next = NULL;
	return (bloc);
}

t_bloc		*alpha_list(t_bloc *dir)
{	
	t_bloc  *tmp;
	t_bloc  *dup;
	t_bloc  *bloc;

	tmp = dir;
	while (dir != NULL && dir->name != NULL)
	{
		dup = dir->next;
		while (dup != NULL && dup->name != NULL)
		{
			if (ft_strcmp(dir->name, dup->name) > 0)
			{
				bloc = bloc_dup(dir);
				dir = bloc_cpy(dir, dup);
				dup = bloc_cpy(dup, bloc);
			}
			dup = dup->next;
		}
		dir = dir->next;
	}
 	return (tmp);
}

t_lstruct		*ft_putpath(t_lstruct *opt, t_bloc *bloc)
{
	if (verificator_path(bloc->path, opt) == 1)
	{
		if (opt->nbr == 0 && opt->optR == 1 && opt->nbrdir < 2)
			opt->nbr++;
		else
		{
			if (opt->nbr > 0)
			{
				ft_putchar ('\n');
			}
			ft_putstr(bloc->path);
			ft_putendl(":");
			opt->nbr++;
		}
	}
	return (opt);
}

t_lstruct		*ft_putlst(t_lstruct *opt, t_bloc *lst)
{
	while (lst != NULL && lst->name != NULL)
	{
		if (opt->opta == 1)
			ft_putendl(lst->name);
		else if (opt->optl == 1)
		{
			if (verificator(lst->name) == 1)
				ft_putendl(lst->name);
		}
		else if (lst->name[0] != '.')
			ft_putendl(lst->name);
		lst = lst->next;
	}
	opt->nbr++;
	return (opt);
}



int			verificator(char *tab)
{
	int i;
	
	i = 0;
	while (tab[i])
		i++;
	i--;
	while (tab[i] == ' ')
		i--;
	while (tab[i] != ' ')
		i--;
	if(tab[i - 1] == '>' && tab[i - 2] == '-')
	{
		i = i - 4;
		while (tab[i] != ' ')
			i--;
	}
	if (tab[i + 1] == '.')
		return (0);
	return (1);
}
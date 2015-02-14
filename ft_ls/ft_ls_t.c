/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:51:27 by jromagna          #+#    #+#             */
/*   Updated: 2015/01/15 18:51:28 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*time_guardian(char *tm, time_t real_tm)
{
	time_t	t;
	char	**tab;

	t = 0;
	tab = ft_strsplit(tm, ' ');
	tm = ft_strsub(tm, 3, 8);
	t = time(&t);
	if ((t - real_tm) > 15778463 || (t - real_tm) < -3600)
	{
		tab[4] = ft_strsub(tab[4], 0, 4);
		tab[4] = ft_strjoin(" ", tab[4]);
		tm = ft_strjoin(tm , tab[4]);
	}
	else
	{
		tab[3] = ft_strsub(tab[3], 0, 5);
		tm = ft_strjoin(tm , tab[3]);
	}
	return (tm);
}

t_bloc		*alpha_time(t_bloc *dir)
{
	t_bloc *tmp;
	t_bloc *dup;
	t_bloc *bloc;

	tmp = dir;
	while (dir != NULL && dir->name != NULL)
	{
		dup = dir->next;
		while ((dir->realtime == dup->realtime) && dup->name != NULL)
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

t_bloc		*time_attack(t_bloc *dir)
{
	t_bloc	*tmp;
	t_bloc	*dup;
	t_bloc	*bloc;

	tmp = dir;
	while (dir != NULL)
	{
		dup = dir->next;
		while (dup != NULL)
		{
			if (dir->realtime < dup->realtime)
			{
				bloc = bloc_dup(dir);
				dir = bloc_cpy(dir, dup);
				dup = bloc_cpy(dup, bloc);
			}
			dup = dup->next;
		}
		dir = dir->next;
	}
	tmp = alpha_time(tmp);
	return (tmp);
}

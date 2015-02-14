/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:50:56 by jromagna          #+#    #+#             */
/*   Updated: 2015/01/15 18:50:58 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			opt_verificator(char *tab)
{
	int				i;

	i = 1;
	if (tab[0] != '-' || tab[1] == '\0')
		return (0);
	if (tab[0] == '-' && tab[1] == '-' && tab[2] == '\0')
		return (2);
	while (tab[i])
	{
		if (ft_strchr("trRla1", tab[i]) == NULL)
		{
			ft_putstr_fd("ls: illegal option -- ", 2);
			ft_putchar_fd(tab[i], 2);
			ft_putendl_fd("\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]", 2);
			exit(1);
		}
		i++;
	}
	if (tab[0] == '-' && tab[1] == '-' && tab[2] != '\0')
	{
		ft_putendl("illegal option");
		exit(1);
	}
	return (1);
}

t_bloc			*docfiller(char **argv, int size, int argc, t_bloc *fichier)
{
	t_bloc		*tmp;
	int			i;

	i = 0;
	tmp = fichier;
	while (i < (size - argc + 1))
		i++;
	while (i != (size) && argv[i])
	{
		fichier->name = ft_strdup(argv[i]);
		fichier->next = new_bloc();
		fichier = fichier->next;
		i++;
	}
	return (tmp);
}

t_lstruct		*lstruct_init(char **opt, int *size)
{
	t_lstruct   *optstr;
	int         i;
	int         j;
			
	i = 1;
	if ((optstr = (t_lstruct*)malloc(sizeof(t_lstruct))) == NULL)
		return (0);
	optstr->nbrdir = 0;
	while (i < *size)
	{
		j = 0;
		if (opt_verificator(opt[i]) == 0)
			break;
		if (opt_verificator(opt[i]) == 2)
		{
			i++;
			break;
		}
		if (opt[i][0] == '-')
			while (opt[i][j] != '\0')
			{
				(opt[i][j] == 'l') ? optstr->optl = 1 : 0;
				(opt[i][j] == 'R') ? optstr->optR = 1 : 0;
				(opt[i][j] == 'r') ? optstr->optr = 1 : 0;
				(opt[i][j] == 'a') ? optstr->opta = 1 : 0;
				(opt[i][j] == 't') ? optstr->optt = 1 : 0;
				j++;
			}
		i++;
	}
	*size = *size - i + 1;
	return (optstr);
}

int				main(int argc, char **argv)
{
	t_lstruct	*opt;
	t_bloc		*fichier;
	t_bloc		*tmp;
	int			i;

	i = argc;
	fichier = new_bloc();
	opt = malloc(sizeof(t_lstruct));
	tmp = fichier;
	fichier->name = ft_strdup(".");
	if (argc > 1)
	{
		if((opt = lstruct_init(argv, &argc)) == NULL)
			return (0);
		if (argc > 1)
			if (((fichier = docfiller(argv, i, argc, fichier)) == NULL))
				return (0);
	}
	while (tmp != NULL && tmp->name != NULL)
	{
		if (tmp->name != NULL)
			tmp->path = ft_strdup(tmp->name);
		tmp = tmp->next;
	}
	opt->nbr = 0;
	ft_ls(opt, fichier);
	return (0);
}
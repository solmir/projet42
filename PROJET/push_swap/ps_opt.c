/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 14:38:48 by jromagna          #+#    #+#             */
/*   Updated: 2015/03/20 14:38:50 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_opt	*new_opt(void)
{
	t_opt	*opt;

	opt = malloc(sizeof(opt));
	opt->v = 0;
	opt->c = 0;
	opt->m = 0;
	return (opt);
}

t_opt	*lstruct_fill(t_opt *opt, char *ot)
{
	int	j;

	j = 1;
	while (ot[j] != '\0')
	{
		(ot[j] == 'v') ? opt->v = 1 : 0;
		(ot[j] == 'c') ? opt->c = 1 : 0;
		(ot[j] == 'm') ? opt->m = 1 : 0;
		j++;
	}
	return (opt);
}


int			opt_verificator(char *tab)
{
	int		i;

	i = 1;
	if (tab[0] != '-' || tab[1] == '\0')
		return (0);
	if (tab[0] == '-' && tab[1] == '-' && tab[2] == '\0')
		return (2);
	while (tab[i])
	{
		if (ft_strchr("cvm", tab[i]) == NULL)
		{
			ft_putendl_fd("you failed ...", 2);
			ft_putstr_fd("push_swap: illegal option -- ", 2);
			ft_putchar_fd(tab[i], 2);
			ft_putstr_fd("\nusage: ./push_swap [-cvm [file ...]]\n", 2);
			ft_putstr_fd("In order to close option use \"--\"\n", 2);
			exit(1);
		}
		i++;
	}
	return (1);
}

t_opt	*get_opt(char **argv, int *size)
{
	t_opt	*opt;
	int		i;

	i = 1;
	opt = new_opt();
	while (i < *size)
	{
		if (opt_verificator(argv[i]) == 0)
			break ;
		if (opt_verificator(argv[i]) == 2)
		{
			i++;
			break ;
		}
		if (argv[i][0] == '-')
			opt = lstruct_fill(opt, argv[i]);
		i++;
	}
	*size = i;
	ft_putnbr(opt->v);
	ft_putnbr(opt->c);
	ft_putnbr(opt->m);
	ft_putchar('\n');
	return (opt);
}
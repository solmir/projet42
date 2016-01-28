/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_act_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 22:54:49 by jromagna          #+#    #+#             */
/*   Updated: 2015/03/16 22:54:50 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		verificator(t_pile *pile)
{
	while (pile->pilenbr != -1)
	{
		if (pile->value > pile->next->value  && pile->next->pilenbr != -1)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int		ft_atoi_verif(const char *str)
{
	int		i;
	int		k;
	int		s;

	i = 0;
	k = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	s = (str[i - 1] == '-') ? -1 : 1;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(ft_strjoin(str, " argument invalide"));
		k = k * 10 + str[i] - '0';
		i++;
	}
	return (s * k);
}

void		verif_doublon(t_pile *pile)
{
	t_pile *tmp;

	while (pile->pilenbr != -1 && pile->next->pilenbr != -1)
	{
		tmp = pile->next;
		while (tmp->pilenbr != -1)
		{
			if (pile->value == tmp->value)
				ft_error("doublon");
			tmp = tmp->next;
		}
		pile = pile->next;
	}
	return ;
}

int		ft_error(char *str)
{
	ft_putendl_fd("-> push_swap : \"ERROR :3 try again <3\"", 2);
	ft_putendl_fd("-> you : let's do this !", 2);
	ft_putstr_fd("ERROR is : ", 2);
	ft_putendl_fd(str, 2);
	exit (1);
	return (0);
}

void	ft_putlist(t_pile *pile)
{
	ft_putendl("PUTLIST");
	while (pile != NULL && pile->pilenbr != -1)
	{
		ft_putnbr(pile->value);
		ft_putstr(" -> ");
		ft_putnbr(pile->pilenbr);
		ft_putendl(" ");
		pile = pile->next;
	}

}
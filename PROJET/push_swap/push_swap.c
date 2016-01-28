/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 22:11:41 by jromagna          #+#    #+#             */
/*   Updated: 2015/03/16 22:11:43 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*new_list(void)
{
	t_pile	*pile;

	pile = malloc(sizeof(pile));
	pile->value = 0;
	pile->pilenbr = 0;
	pile->next = NULL;
	return (pile);
}

t_pile	*ft_create_sec(t_pile *pile)
{
	t_pile	*ret;
	t_pile	*tmp;

	ret = new_list();
	tmp = ret;
	while(pile->pilenbr != -1)
	{
		ret->pilenbr = pile->pilenbr;
		ret->next = new_list();
		pile = pile->next;
		ret = ret->next;
	}
	ret->pilenbr = -1;
	pile->next = tmp;
	return (tmp);
}

t_pile	*get_list(char **argv, int i)
{
	t_pile	*pile;
	t_pile	*tmp;
	int		p;


	p = 0;
	pile = new_list();
	tmp = pile;
	while (argv[i] != NULL)
	{
		pile->value = ft_atoi_verif(argv[i]);
		pile->pilenbr = p;
		pile->next = new_list();
//		pile->next->pre = pile;
		pile = pile->next;
		i++;
		p++;
	}
	pile->pilenbr = -1;
	pile->next = tmp;
	//tmp->pre = pile;
	verif_doublon(tmp);
	return (tmp);
}

int		main(int argc, char **argv)
{
	t_opt	*opt;
	t_pile	*pile;
	t_pile	*pile2;
	int		i;

	i = argc;
	pile = new_list();
	pile2 = new_list();
	if (argc > 1)
	{
		if (argv[1][0] == '-')
			opt = get_opt(argv, &i);
		else
			i = 1;
		if (argv[i] != NULL)
		{
			pile = get_list(argv, i);
			pile2 = ft_create_sec(pile);
		}
		else
			return (ft_error ("no arguments"));
	}
	else
		return (ft_error ("no arguments"));
	ft_putlist(pile);
	ft_putnbr(verificator(pile));
	dirigeator(pile, pile2, opt);
	return (argc);
}
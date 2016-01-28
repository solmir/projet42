/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_diri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:17:38 by jromagna          #+#    #+#             */
/*   Updated: 2015/03/30 18:17:40 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_point	*get_data(t_pile *pile, t_pile *pile2)
{
	t_point *data;

	data = malloc(sizeof(data));
	data->1stdb = pile;
	data->2nddb = pile2;
	while (pile->next->pilenbr != -1 && pile2->next->pilenbr != -1)
	{
		pile = pile->next;
		pile2 = pile2->next;
	}
	data->1stfn = pile;
	data->2ndfn = pile2;
	data->1nope = pile->next;
	data->2nope = pile2->next;
	return (data);
}

void	dirigeator(t_pile *pile, t_pile *pile2, t_opt *opt)
{
	t_point *data;

	data = get_data(pile, pile2);
	while (verificator(pile))
	{
		
	}
	return ;
}
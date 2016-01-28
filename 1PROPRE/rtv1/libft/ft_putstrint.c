/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 09:12:49 by jromagna          #+#    #+#             */
/*   Updated: 2015/05/09 09:12:51 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstrint(int i, char *c)
{
	if (c == NULL)
		return ;
	ft_putstr(c);
	ft_putstr(" : ");
	ft_putnbr(i);
	ft_putchar('\n');
}

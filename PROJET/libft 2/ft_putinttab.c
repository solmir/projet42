/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinttab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 21:27:14 by jromagna          #+#    #+#             */
/*   Updated: 2015/06/03 21:27:17 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putinttab(int **tabint, int x, int y)
{
	int i;
	int j;

	if (tabint == NULL)
		return ;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putnbr(tabint[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

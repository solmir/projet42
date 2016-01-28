/* ************************************************************************** */
/*	                                                                   */
/*                                                        :::      ::::::::   */
/*   recuperator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 15:59:52 by jromagna          #+#    #+#             */
/*   Updated: 2015/04/22 15:59:53 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(char *str)
{
	ft_putendl_fd("-> FDF : \"ERROR :3 try again <3\"", 2);
	ft_putendl_fd("-> you : let's do this !", 2);
	ft_putstr_fd("ERROR is : ", 2);
	ft_putendl_fd(str, 2);
	exit (1);
	return (0);
}

#include <stdio.h>

void 	puttabint(int **tabint, int x, int y)
{
	int i;
	int j;

	i = 0;
	ft_putendl("putinttab");
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putnbr(tabint[i][j]);
			j++;
		}
		ft_putendl("");
		i++;
	}
}

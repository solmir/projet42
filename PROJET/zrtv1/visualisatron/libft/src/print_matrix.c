/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 00:55:48 by alelievr          #+#    #+#             */
/*   Updated: 2016/01/20 15:49:20 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_matrix(t_matrix *m)
{
	int		i;
	int		j;

	i = 0;
	while (i < m->h)
	{
		j = 0;
		while (j < m->w)
		{
			ft_putnbr((int)(float)m->m[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

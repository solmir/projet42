/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixsous.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 00:52:10 by alelievr          #+#    #+#             */
/*   Updated: 2014/12/19 15:11:43 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	*matrixsous(t_matrix *m1, t_matrix *m2)
{
	int		i;
	int		j;

	i = 0;
	if (m1->w == m2->w && m1->h == m2->h)
	{
		while (i < m1->w)
		{
			j = 0;
			while (j < m1->h)
			{
				m1->m[i][j] -= m2->m[i][j];
				j++;
			}
			i++;
		}
	}
	return (m1);
}

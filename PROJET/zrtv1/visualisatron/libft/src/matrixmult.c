/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixmult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 01:38:54 by alelievr          #+#    #+#             */
/*   Updated: 2016/01/20 15:47:41 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

t_matrix	*matrixmult(t_matrix *m1, t_matrix *m2)
{
	double	**i;
	int		row;
	int		col;
	int		inner;
	double	sum;

	row = -1;
	if (!(i = (double **)malloc(sizeof(double *) * (size_t)m2->h)))
		return (NULL);
	while (++row < m2->h)
		i[row] = (double *)malloc(sizeof(double) * (size_t)m1->w);
	row = -1;
	while (++row != m1->h && ((col = -1)))
		while (++col != m2->w && !((int)(float)(sum = 0)))
		{
			inner = -1;
			while (++inner != m1->w)
				sum += (double)m1->m[row][inner] * (double)m2->m[inner][col];
			i[row][col] = sum;
		}
	return (new_matrix(m1->h, m2->w, (double **)i));
}

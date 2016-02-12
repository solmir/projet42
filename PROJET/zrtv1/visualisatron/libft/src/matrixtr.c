/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixtr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:17:52 by alelievr          #+#    #+#             */
/*   Updated: 2016/01/20 15:48:43 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_matrix	*matrixtr(t_matrix *m)
{
	double	**i;
	int		j;
	int		k;
	int		l;
	int		n;

	j = -1;
	l = 0;
	n = 0;
	if (!(i = (double **)malloc(sizeof(double *) * (size_t)m->w)))
		return (NULL);
	while (++j < m->w && ((k = -1)))
	{
		if (!(i[j] = (double *)malloc(sizeof(double) * (size_t)m->h)))
			return (NULL);
		while (++k < m->h)
		{
			i[j][k] = m->m[l][n];
			ft_putnbr((int)(float)m->m[l][n]);
			if (n == m->w - 1 && !((n = 0)))
				l++;
			m++;
		}
	}
	return (new_matrix(m->h, m->w, i));
}

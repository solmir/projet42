/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 13:01:17 by alelievr          #+#    #+#             */
/*   Updated: 2016/01/20 23:35:04 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intsize(int ba)
{
	int		s;
	long	a;

	a = (ba < 0) ? -(long)ba : ba;
	s = 0;
	while (a > 0)
	{
		a /= 10;
		s++;
	}
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 23:15:31 by alelievr          #+#    #+#             */
/*   Updated: 2014/12/16 23:16:51 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	int		ret;

	if (n < 0)
		n = -n;
	ret = 1;
	while (ret <= n)
	{
		ret *= 10;
	}
	return (ret / 10);
}

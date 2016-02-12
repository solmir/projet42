/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:55:17 by alelievr          #+#    #+#             */
/*   Updated: 2016/01/20 15:08:57 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	char				*dest;
	char				*src2;
	unsigned int		i;

	dest = (char *)(unsigned long)dst;
	src2 = (char *)(unsigned long)src;
	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		dest[i] = src2[i];
		i++;
	}
	return ((void *)dest);
}

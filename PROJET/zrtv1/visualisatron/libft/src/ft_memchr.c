/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:30:23 by alelievr          #+#    #+#             */
/*   Updated: 2016/01/20 15:06:07 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	const unsigned char	*str;

	str = (unsigned char *)(unsigned long)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return ((void *)(unsigned long)str);
		str++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deconvert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 20:48:27 by alelievr          #+#    #+#             */
/*   Updated: 2016/01/20 15:11:08 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ret_base(unsigned char c)
{
	if (c <= '9')
		return (c - '0');
	if (c <= 'Z')
		return (c - 'A' + 10);
	if (c <= 'z')
		return (c - 'a' + 10);
	return (-1);
}

int64_t	ft_deconvert(unsigned char *n, int b)
{
	int		c;
	int64_t	buffer;

	buffer = 0;
	c = (int)ft_ustrlen(n) - 1;
	while (c + 1)
		buffer += ret_base(*n++) * ft_pow(b, c--);
	return (buffer);
}

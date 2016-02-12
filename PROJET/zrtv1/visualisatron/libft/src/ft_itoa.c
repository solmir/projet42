/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:51:55 by alelievr          #+#    #+#             */
/*   Updated: 2015/12/19 20:28:09 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#define SHORTCPY *(short *)(t_ptr)--buff = (short)('-' | ((n % 10 + '0') << 8))

char	*ft_itoa(int i)
{
	char		*buff;
	long int	n;

	buff = (char *)(char[0xF0]){[0xF0 - 1]=0} + 0xF0 - 2;
	n = (i < 0 ? -(long)i : i);
	*buff-- = ((i < 0 ? -(long)i : i) % 10) + '0';
	while (n /= 10)
		if (i < 0)
			SHORTCPY;
		else
			*buff-- = (n % 10) + '0';
	return (ft_strdup(buff + (i < 0 ? 0 : 1)));
}

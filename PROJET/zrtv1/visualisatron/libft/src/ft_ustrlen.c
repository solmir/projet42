/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:42:14 by alelievr          #+#    #+#             */
/*   Updated: 2016/01/20 15:44:32 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_ustrlen(unsigned char const *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
			i++;
		return ((size_t)i);
	}
	else
		return (0);
}

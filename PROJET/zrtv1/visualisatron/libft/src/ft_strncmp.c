/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:57:22 by alelievr          #+#    #+#             */
/*   Updated: 2016/01/20 15:30:53 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((*(unsigned char *)(unsigned long)s1 <
						*(unsigned char *)(unsigned long)s2) ? -1 : +1);
		else if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		--n;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:20:52 by alelievr          #+#    #+#             */
/*   Updated: 2016/01/20 15:32:29 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	char	*tmp;

	tmp = (char *)(unsigned long)s;
	while (*tmp != '\0')
		tmp++;
	while (*tmp != (char)c && tmp != s)
		tmp--;
	if (*tmp == (char)c)
		return ((char *)tmp);
	return (NULL);
}

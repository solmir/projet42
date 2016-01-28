/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <jromagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:39:53 by jromagna          #+#    #+#             */
/*   Updated: 2014/11/12 16:47:39 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = s;
	while (n != 0)
	{
		s1[i] = '\0';
		n--;
		i++;
	}
	return (s);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 14:46:40 by alelievr          #+#    #+#             */
/*   Updated: 2015/01/27 15:32:33 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pputchar(va_list *ap, char *buff, int i)
{
	char	c;
	char	tmp[2];

	c = va_arg(*ap, int);
	tmp[0] = c;
	tmp[1] = 0;
	buff = ft_strcat(buff, tmp);
	(void)i;
	return (1);
}

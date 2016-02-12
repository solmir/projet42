/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 14:07:53 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/04 01:19:09 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putaddr(va_list *ap, char *buff, int i)
{
	void			*addr;
	unsigned long	n;
	int				ret;
	char			buffer[0xF000];

	addr = va_arg(*ap, void *);
	n = (unsigned long)addr;
	ret = ft_convert(buffer, n, 16, 0);
	buffer[ret] = 0;
	buff[i++] = '0';
	buff[i++] = 'x';
	buff = ft_strcat(buff, buffer);
	(void)i;
	return (ret + 2);
}

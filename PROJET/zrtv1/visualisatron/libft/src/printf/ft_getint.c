/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 20:21:31 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/23 17:40:37 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getint(va_list *ap, char *buff, int i)
{
	(void)i;
	(void)buff;
	g_tmp = va_arg(*ap, int64_t);
	BIT_ON(g_conv, NORM);
	return (0);
}

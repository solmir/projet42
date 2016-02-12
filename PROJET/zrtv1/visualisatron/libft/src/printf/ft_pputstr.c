/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 15:26:11 by alelievr          #+#    #+#             */
/*   Updated: 2015/02/24 18:06:59 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_pputstr(va_list *ap, char *buff, int i)
{
	char	*str;
	int		ret;

	str = va_arg(*ap, char *);
	if (str != NULL)
	{
		buff = ft_strcat(buff, str);
		ret = ft_strlen(str);
	}
	else
	{
		ft_strcat(buff, "(null)");
		ret = 6;
	}
	(void)i;
	return (ret);
}

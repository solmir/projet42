/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 22:57:48 by alelievr          #+#    #+#             */
/*   Updated: 2015/04/02 18:51:07 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_ftoa(char *buff, double d)
{
	char	*tmp;
	int		max;

	tmp = buff;
	if (d < 0)
		*buff++ = '-';
	d = (d < 0) ? -d : d;
	buff += ft_convert(buff, ABS((int)d), 10, 0);
	d -= (int)d;
	*buff++ = '.';
	max = -1;
	while (d - (int)d > 0.00001f && ++max < 5)
	{
		if ((int)(d * 10.0f) % 10 == 0)
			*buff++ = '0';
		d *= 10;
	}
	buff += ft_convert(buff, ABS((int)d), 10, 0);
	return (buff - tmp);
}

int				ft_float(va_list *ap, char *buff, int i)
{
	double	d;

	d = (double)va_arg(*ap, double);
	return (ft_ftoa(buff + i, d));
}

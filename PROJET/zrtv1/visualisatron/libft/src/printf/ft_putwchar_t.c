/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 15:00:43 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/23 17:16:23 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

int		nbr_bits(unsigned int nbr)
{
	int		i;

	i = 1;
	while ((nbr = nbr >> 1))
		i++;
	return (i);
}

void	ft_putwchart(wchar_t wchar, int *len, char *buff, int i)
{
	unsigned int	ch;
	int				n;

	*len = 0;
	ch = (unsigned int)wchar;
	n = nbr_bits(ch);
	if (n > 7 && ((*len += 1)))
	{
		if (n > 11 && ((*len += 1)))
		{
			if (n > 16 && ((*len += 2)))
			{
				buff[i++] = ((ch >> 18) & 7) | 240;
				buff[i++] = ((ch >> 12) & 63) | 128;
			}
			else if ((*len += 1))
				buff[i++] = ((ch >> 12) & 15) | 224;
			buff[i++] = ((ch >> 6) & 63) | 128;
		}
		else if ((*len += 1))
			buff[i++] = ((ch >> 6) & 31) | 192;
		buff[i++] = (ch & 63) | 128;
	}
	else if ((*len += 1))
		buff[i++] = ch;
}

int		ft_putwchar_t(va_list *ap, char *buff, int i)
{
	wchar_t	wc;
	int		len;

	len = 0;
	wc = va_arg(*ap, wchar_t);
	g_wstr[0] = wc;
	g_wstr[1] = 0;
	ft_putwchart(wc, &len, buff, i);
	return (len);
}

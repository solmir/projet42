/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 15:02:33 by alelievr          #+#    #+#             */
/*   Updated: 2015/02/24 19:21:43 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

int		ft_putwstr_t(va_list *ap, char *buff, int index)
{
	int		len;
	int		ret;
	int		i;
	wchar_t	*wstr;

	len = 0;
	ret = 0;
	wstr = va_arg(*ap, wchar_t *);
	i = 0;
	if (wstr != NULL)
		while (wstr[i])
		{
			g_wstr[i] = wstr[i];
			ft_putwchart(wstr[i], &len, buff, index);
			index += len;
			ret += len;
			i++;
		}
	else
	{
		ft_strcat(buff, "(null)");
		ret = 6;
	}
	g_wstr[i] = 0;
	return (ret);
}

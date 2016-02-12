/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:38:42 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/27 14:46:55 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_point3(char *opl, char op, char *buff, char *value)
{
	int		len;
	int		ret;

	len = ft_atoi(opl + 1);
	if ((op == 'i' || op == 'o' || op == 'O' || op == 'd' || op == 'D'
				|| op == 'x' || op == 'X' || op == 'p' || op == 'u'
				|| op == 'U') && !BIT_TEST(g_conv, ALIGNE) && len)
	{
		BIT_ON(g_conv, ZERO);
		BIT_OFF(g_conv, POINT);
		BIT_ON(g_conv, C_POINT);
		ret = ft_align(value, buff, opl + 1, op);
		BIT_OFF(g_conv, ZERO);
		return (ret);
	}
	return (0);
}

static int	ft_point2(char *opl, char *value, char op, char *buff)
{
	int		*tmp;
	int		n;
	int		ret;
	int		len;

	len = ft_atoi(opl + 1);
	if (op == 's' || op == 'c')
		return ((len - ft_strlen(value) > 0 ? 0 : len - ft_strlen(value)));
	if ((op == 'S' || op == 'C'))
	{
		if (ft_strlen(value) > (size_t)len && ((tmp = g_wstr) || 1))
		{
			ret = 0;
			while (42)
			{
				n = nbr_bits(*tmp) / 4;
				if (n + ret > len && tmp++)
					return (ret - ft_strlen(value));
				ret += n;
			}
		}
		else
			return (-ft_strlen(value) + ft_strlen((char *)g_wstr));
	}
	return (ft_point3(opl, op, buff, value));
}

int			ft_point(char *value, char *buff, char *opl, char op)
{
	int		len;

	len = ft_atoi(opl + 1);
	if ((op == 'i' || op == 'd' || op == 'u' || op == 'U')
			&& len == 0 && !ft_strcmp(value, "0")
			&& len == 0)
		return (-1);
	if (((op == 'O' || op == 'o') && len == 0 && !ft_strcmp(value, "0")) &&
			!BIT_TEST(g_conv, SHARP))
		return (-1);
	if (((op == 'x' || op == 'X') && !ft_strcmp(value, "0"))
			|| ((op == 'p' && !ft_strcmp(value, "0x0")) && len == 0))
		return (-1);
	if ((op == 'i' || op == 'o' || op == 'O' || op == 'd' || op == 'D'
				|| op == 'x' || op == 'X') && BIT_TEST(g_conv, ALIGNE))
		return (0);
	if ((op == 'o' || op == 'O') && BIT_TEST(g_conv, POINT) && len == 0 &&
			!ft_strcmp(value, "0") && !BIT_TEST(g_conv, SHARP))
		return (-1);
	if (len < 0)
		return (-ft_strlen(value));
	return (ft_point2(opl, value, op, buff));
}

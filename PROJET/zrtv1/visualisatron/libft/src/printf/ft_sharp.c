/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sharp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 18:57:23 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/29 16:17:13 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sharp(char *value, char *buff, char *opl, char op)
{
	BIT_ON(g_conv, SHARP);
	if ((op == 'o' || op == 'O') && ft_strcmp(value, "0"))
	{
		value = ft_shl(value, 1);
		*value = '0';
		return (1);
	}
	if ((op == 'x' || op == 'X') && ft_strcmp(value, "0")
			&& !BIT_TEST(g_conv, ALIGNE) && !BIT_TEST(g_conv, POINT))
	{
		if (BIT_TEST(g_conv, ZERO) && ((*buff = '0')))
		{
			buff[1] = op;
			return (2);
		}
		else if ((value = ft_shl(value, 1)))
		{
			value = ft_shl(value, 1);
			*value = '0';
			value[1] = op;
		}
		return (2);
	}
	(void)opl;
	return (0);
}

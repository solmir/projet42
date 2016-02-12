/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:49:26 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/04 02:14:25 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_plus(char *value, char *buff, char *opl, char op)
{
	BIT_ON(g_conv, PLUS);
	if (*value != '-' && (op == 'i' || op == 'd'))
	{
		if (BIT_TEST(g_conv, ZERO))
		{
			g_retlen++;
			*buff = '+';
			return (1);
		}
		ft_shl(value, 1);
		*value = '+';
		return (1);
	}
	(void)buff;
	(void)op;
	(void)opl;
	return (0);
}

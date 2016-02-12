/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 19:35:18 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/04 13:57:18 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_space(char *value, char *buff, char *opl, char op)
{
	BIT_ON(g_conv, SPACE);
	if ((op == 'i' || op == 'd'))
	{
		if (*value != '-' && (BIT_TEST(g_conv, PLUS)) == 0)
		{
			value = ft_shl(value, 1);
			*value = ' ';
			return (1);
		}
	}
	(void)opl;
	(void)buff;
	return (0);
}

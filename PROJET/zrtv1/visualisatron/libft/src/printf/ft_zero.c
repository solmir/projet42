/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 15:46:17 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/07 17:55:27 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_zero(char *value, char *buff, char *opl, char op)
{
	BIT_ON(g_conv, ZERO);
	(void)op;
	(void)opl;
	(void)buff;
	(void)value;
	return (0);
}

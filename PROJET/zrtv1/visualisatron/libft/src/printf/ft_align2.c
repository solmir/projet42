/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 15:57:00 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/27 16:09:22 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_align5(t_align *a)
{
	if ((BIT_TEST(g_conv, ZERO)) && *a->value == '-'
			&& ((*a->buff++ = '-')) && (a->align--) && (a->len--))
		ft_shr(a->value, 1);
	if (BIT_TEST(g_conv, POINT) && *a->value == '-' && (a->len--))
		ft_shr(a->value, 1);
	if (a->op == 'p' && BIT_TEST(g_conv, C_POINT))
		a->align += 2;
	if (BIT_TEST(g_conv, ZERO) && a->value[1] == 'x' && ((*a->buff++ = '0')))
	{
		ft_shr(a->value, 1);
		ft_shr(a->value, 1);
		*a->buff++ = 'x';
	}
}

void	ft_aligninit(t_align *a, char *value, char *opl, char *buff)
{
	char	*tmp;
	char	op;

	tmp = opl;
	while (ft_strchr(FLAG, *tmp))
		tmp++;
	op = *tmp;
	a->value = value;
	a->buff = buff;
	a->opl = opl;
	a->op = op;
	a->retadd = 0;
	a->align = ft_atoi(opl);
	a->len = g_retlen;
}

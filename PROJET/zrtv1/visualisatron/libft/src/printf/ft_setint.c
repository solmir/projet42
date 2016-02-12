/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 16:50:23 by alelievr          #+#    #+#             */
/*   Updated: 2016/01/20 15:52:48 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_ret = 0;

void		ft_setint2(char *buffer, t_data *d, char op, int uns)
{
	if (uns == INT)
	{
		if (op == 'x')
			g_ret = ft_convert(buffer, d->i, 16, 0);
		else if (op == 'X')
			g_ret = ft_convert(buffer, d->i, 16, 1);
		else if (op == 'o' || op == 'O')
			g_ret = ft_convert(buffer, d->i, 8, 0);
		else if (op == 'i' || op == 'D' || op == 'd' || op == 'u' || op == 'U')
			g_ret = ft_itoa64(buffer, d->i);
	}
	else if (uns == UINT)
	{
		if (op == 'x')
			g_ret = ft_convert(buffer, d->u, 16, 0);
		else if (op == 'X')
			g_ret = ft_convert(buffer, d->u, 16, 1);
		else if (op == 'o' || op == 'O')
			g_ret = ft_convert(buffer, d->u, 8, 0);
		else if (op == 'i' || op == 'D' || op == 'd' || op == 'u' || op == 'U')
			g_ret = ft_itoau64(buffer, d->u);
	}
}

void		ft_setint3(char *buffer, t_data *d, char op, int uns)
{
	if (uns == LINT)
	{
		if (op == 'x')
			g_ret = ft_convert(buffer, d->l, 16, 0);
		else if (op == 'X')
			g_ret = ft_convert(buffer, d->l, 16, 1);
		else if (op == 'o' || op == 'O')
			g_ret = ft_convert(buffer, d->l, 8, 0);
		else if (op == 'i' || op == 'D' || op == 'd' || op == 'u' || op == 'U')
			g_ret = ft_itoa64(buffer, d->l);
	}
	else if (uns == LUINT)
	{
		if (op == 'x')
			g_ret = ft_convert(buffer, d->st, 16, 0);
		else if (op == 'X')
			g_ret = ft_convert(buffer, d->st, 16, 1);
		else if (op == 'o' || op == 'O')
			g_ret = ft_convert(buffer, d->st, 8, 0);
		else if (op == 'i' || op == 'D' || op == 'd' || op == 'u' || op == 'U')
			g_ret = ft_itoau64(buffer, d->st);
	}
}

void		ft_setint4(char *buffer, t_data *d, char op, int uns)
{
	if (uns == LLINT)
	{
		if (op == 'x')
			g_ret = ft_convert(buffer, d->ll, 16, 0);
		else if (op == 'X')
			g_ret = ft_convert(buffer, d->ll, 16, 1);
		else if (op == 'o' || op == 'O')
			g_ret = ft_convert(buffer, d->ll, 8, 0);
		else if (op == 'i' || op == 'D' || op == 'd' || op == 'u' || op == 'U')
			g_ret = ft_itoa64(buffer, d->ll);
	}
	else if (uns == LLUINT)
	{
		if (op == 'x')
			g_ret = ft_convert(buffer, d->u64, 16, 0);
		else if (op == 'X')
			g_ret = ft_convert(buffer, d->u64, 16, 1);
		else if (op == 'o' || op == 'O')
			g_ret = ft_convert(buffer, d->u64, 8, 0);
		else if (op == 'i' || op == 'D' || op == 'd' || op == 'u' || op == 'U')
			g_ret = ft_itoau64(buffer, d->u64);
	}
}

void		ft_setint5(char *buffer, t_data *d, char op, int uns)
{
	if (uns == INTMAX)
	{
		if (op == 'x')
			g_ret = ft_convert(buffer, d->max, 16, 0);
		else if (op == 'X')
			g_ret = ft_convert(buffer, d->max, 16, 1);
		else if (op == 'o' || op == 'O')
			g_ret = ft_convert(buffer, d->max, 8, 0);
		else if (op == 'i' || op == 'D' || op == 'd' || op == 'u' || op == 'U')
			g_ret = ft_itoa64(buffer, d->max);
	}
	else if (uns == UINTMAX)
	{
		if (op == 'x')
			g_ret = ft_convert(buffer, d->umax, 16, 0);
		else if (op == 'X')
			g_ret = ft_convert(buffer, d->umax, 16, 1);
		else if (op == 'o' || op == 'O')
			g_ret = ft_convert(buffer, d->umax, 8, 0);
		else if (op == 'i' || op == 'D' || op == 'd' || op == 'u' || op == 'U')
			g_ret = ft_itoau64(buffer, d->umax);
	}
}

int			ft_setint(char *value, t_data *d, char op, int uns)
{
	char		buffer[0xF000];
	char		*tmp;

	tmp = value;
	ft_bzero(buffer, 0xF000);
	ft_setint2(buffer, d, op, uns);
	ft_setint3(buffer, d, op, uns);
	ft_setint4(buffer, d, op, uns);
	ft_setint5(buffer, d, op, uns);
	value = tmp;
	ft_strcat(value, buffer);
	if (*buffer == '-')
		BIT_ON(g_conv, NEG);
	return (g_ret);
}

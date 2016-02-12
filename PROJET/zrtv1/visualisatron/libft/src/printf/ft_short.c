/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:30:54 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/29 16:23:54 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_seth2(char *buff, t_htype *t, char op, int uns)
{
	int		ret;

	ret = 0;
	if (uns == 0)
	{
		if (op == 'i' || op == 'd' || op == 'u' || op == 'U' || op == 'D')
			ret = ft_itoa64(buff, t->us);
		if (op == 'x' || op == 'X')
			ret = ft_convert(buff, t->us, 16, (op == 'x') ? 0 : 1);
		if (op == 'o' || op == 'O')
			ret = ft_convert(buff, t->us, 8, 0);
	}
	if (uns == 1)
	{
		if (op == 'i' || op == 'd' || op == 'u' || op == 'U' || op == 'D')
			ret = ft_itoa64(buff, t->s);
		if (op == 'x' || op == 'X')
			ret = ft_convert(buff, t->s, 16, (op == 'x') ? 0 : 1);
		if (op == 'o' || op == 'O')
			ret = ft_convert(buff, t->s, 8, 0);
	}
	return (ret);
}

static int	ft_seth_ret(char *value, char *buff, int ret)
{
	ft_strcat(value, buff);
	if (*buff == '-')
		BIT_ON(g_conv, NEG);
	return (ret);
}

static int	ft_seth(char *value, t_htype *t, char op, int uns)
{
	char	buff[0xF000];
	int		ret;

	ft_bzero(buff, 0xF000);
	ret = ft_seth2(buff, t, op, uns);
	if (uns == 2)
	{
		if (op == 'i' || op == 'd' || op == 'u' || op == 'U' || op == 'D')
			ret = ft_itoa64(buff, t->uc);
		if (op == 'x' || op == 'X')
			ret = ft_convert(buff, t->uc, 16, (op == 'x') ? 0 : 1);
		if (op == 'o' || op == 'O')
			ret = ft_convert(buff, t->uc, 8, 0);
	}
	else if (uns == 3)
	{
		if (op == 'i' || op == 'd' || op == 'u' || op == 'U' || op == 'D')
			ret = ft_itoa64(buff, t->c);
		if (op == 'x' || op == 'X')
			ret = ft_convert(buff, t->c, 16, (op == 'x') ? 0 : 1);
		if (op == 'o' || op == 'O')
			ret = ft_convert(buff, t->c, 8, 0);
	}
	return (ft_seth_ret(value, buff, ret));
}

int			ft_short(char *value, char *buff, char *opl, char op)
{
	t_htype		t;
	int			uns;

	uns = 0;
	if (BIT_TEST(g_conv, H))
	{
		if ((SIGNED(op) || op == 'D') && !((uns = 0)))
			t.us = (unsigned short)g_tmp;
		else if ((uns = 1))
			t.s = (short)g_tmp;
	}
	else if (BIT_TEST(g_conv, HH))
	{
		if (SIGNED(op) && ((uns = 2)))
			t.uc = (unsigned char)g_tmp;
		else if ((uns = 3))
			t.c = (char)g_tmp;
	}
	(void)opl;
	(void)buff;
	return (ft_seth(value, &t, op, uns));
}

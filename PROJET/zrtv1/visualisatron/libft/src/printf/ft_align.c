/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 16:09:41 by alelievr          #+#    #+#             */
/*   Updated: 2015/08/25 23:52:39 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_point_value(char *expr)
{
	expr--;
	while (*expr != '.')
		expr++;
	return (ft_atoi(expr + 1));
}

void	ft_align2(t_align *a)
{
	if (BIT_TEST(g_conv, NEG) && a->opl[-1] == '.' && !BIT_TEST(g_conv, ALIGNE)
			&& (size_t)get_point_value(a->opl) > ft_strlen(a->value))
		a->align++;
	if (BIT_TEST(g_conv, NEG) && BIT_TEST(g_conv, POINT) &&
			BIT_TEST(g_conv, ALIGNE) && get_point_value(a->opl) > a->align)
	{
		ft_shr(a->value, 1);
		a->len--;
		*a->buff++ = '-';
		a->retadd++;
	}
	if (BIT_TEST(g_conv, SHARP) && (a->op == 'o' || a->op == 'O'))
	{
		ft_shl(a->value, 1);
		a->retadd--;
	}
	if (BIT_TEST(g_conv, SHARP) && (a->op == 'x' || a->op == 'X'))
	{
		*a->buff++ = '0';
		*a->buff++ = a->op;
		a->retadd += 2;
	}
}

void	ft_align3(t_align *a)
{
	if ((a->op == 'd' || a->op == 'i' || a->op == 'D' || a->op == 'o'
				|| a->op == 'O' || a->op == 'u' || a->op == 'U' || a->op == 'x'
				|| a->op == 'X') && (BIT_TEST(g_conv, POINT)) &&
			get_point_value(a->opl) > a->align && !BIT_TEST(g_conv, ZERO))
		a->align = get_point_value(a->opl);
	if (BIT_TEST(g_conv, POINT) && get_point_value(a->opl) > a->align
			&& a->op == 'p')
	{
		*a->buff++ = '0';
		*a->buff++ = 'x';
		a->retadd += 2;
		a->value[1] = '0';
		a->align = get_point_value(a->opl);
	}
	if (BIT_TEST(g_conv, POINT) && get_point_value(a->opl) < g_retlen &&
			(a->op == 's' || a->op == 'S'))
	{
		a->len = get_point_value(a->opl);
		if (BIT_TEST(g_conv, ZERO))
			BIT_ON(g_conv, F_ZERO);
	}
}

void	ft_align4(t_align *a, int i)
{
	while (a->align-- - a->len && ((++i) || 1))
	{
		if (BIT_TEST(g_conv, POINT))
		{
			*a->buff = ((((BIT_TEST(g_conv, ZERO) && get_point_value(a->opl)
								== 0) || BIT_TEST(g_conv, F_ZERO)) &&
						!((a->op == 's' || a->op == 'S') && BIT_TEST(g_conv,
								ALIGNE))) || BIT_TEST(g_conv, F_ZERO))
				? '0' : ' ';
			if (get_point_value(a->opl) > a->align && !((a->op == 's' ||
							a->op == 'S')
						&& BIT_TEST(g_conv, ALIGNE)))
			{
				*a->buff = '0';
				if (a->buff[-1] == ' ' && BIT_TEST(g_conv, NEG))
					a->buff[-1] = '-';
			}
			a->buff++;
		}
		else
			*a->buff++ = ((BIT_TEST(g_conv, ZERO)) ? '0' : ' ');
	}
	if ((BIT_TEST(g_conv, POINT) || BIT_TEST(g_conv, C_POINT)) &&
			BIT_TEST(g_conv, NEG) && get_point_value(a->opl) < a->len)
		*--a->buff = '-';
}

int		ft_align(char *value, char *buff, char *opl, char op)
{
	t_align		a;
	int			tmp;
	int			i;

	ft_aligninit(&a, value, opl, buff);
	ft_align2(&a);
	ft_align3(&a);
	tmp = a.align;
	if ((a.len > a.align && a.align > 0) || ((a.align < 0 && -a.align < a.len)
				? 1 : 0))
		return (0);
	ft_align5(&a);
	i = -1;
	if (a.align - a.len >= 0)
		ft_align4(&a, i);
	else
		while (-a.align - a.len > 0)
		{
			*(a.buff++ + a.len) = ' ';
			a.align++;
		}
	return (((tmp < 0) ? -(tmp + a.len) : tmp - a.len) -
	((BIT_TEST(g_conv, SPACE)) ? 1 : 0) - (BIT_TEST(g_conv, NEG)
	&& (BIT_TEST(g_conv, POINT) || BIT_TEST(g_conv, ZERO)))
	+ ((BIT_TEST(g_conv, C_POINT) && op == 'p') ? 2 : 0) + a.retadd);
}

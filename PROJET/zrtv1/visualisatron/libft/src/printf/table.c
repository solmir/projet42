/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 19:39:46 by alelievr          #+#    #+#             */
/*   Updated: 2015/08/25 23:54:01 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#define ALIGN ft_align

int			g_conv = 0;
int			g_wstr[] = {0};
int64_t		g_tmp = 0;
int			g_retlen = 0;

static int	(*g_flags[128])(va_list *, char *, int) = {
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, ft_putwchar_t, ft_getint, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, ft_getint,
	NULL, NULL, NULL, ft_putwstr_t, NULL, ft_getint, NULL, NULL,
	ft_getint, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, ft_pputchar, ft_getint, NULL, ft_float, NULL,
	NULL, ft_getint, NULL, NULL, NULL, NULL, NULL, ft_getint,
	ft_putaddr, NULL, NULL, ft_pputstr, NULL, ft_getint, NULL, NULL,
	ft_getint, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

static int	(*g_mod[128])(char *, char *, char *, char) = {
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	ft_space, NULL, NULL, ft_sharp, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, ft_plus, NULL, ALIGN, ft_point, NULL,
	ft_zero, ALIGN, ALIGN, ALIGN, ALIGN, ALIGN, ALIGN, ALIGN,
	ALIGN, ALIGN, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, ft_long, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

static int	ft_flagslen(char *expr)
{
	int		i;

	i = 0;
	while (ft_strchr(FLAG, *expr++))
		i++;
	return (i);
}

static char	*ft_vsprintf_init(char *expr, char *buff2, va_list *ap, int *len)
{
	char	*tmp;

	tmp = expr + 1;
	ft_bzero(buff2, 0xf000);
	while (ft_strchr(FLAG, *tmp))
	{
		if (*tmp == '#')
			BIT_ON(g_conv, SHARP);
		if (*tmp == 0 && !BIT_TEST(g_conv, ALIGNE))
			BIT_ON(g_conv, ZERO);
		if (*tmp >= '1' && *tmp <= '9' && tmp[-1] != '.')
			BIT_ON(g_conv, ALIGNE);
		tmp++;
	}
	if (g_flags[(int)*tmp])
		*len = (*g_flags[(int)*tmp])(ap, buff2, 0);
	else if ((*len = 1))
		buff2[0] = *tmp;
	return (tmp);
}

static void	ft_vsprintf2(t_vsprintf *v, char *buff2, va_list *ap)
{
	v->tmp = ft_vsprintf_init(v->expr, buff2, ap, &v->len);
	v->expr++;
	if (ft_strnchr(v->expr, '.', ft_flagslen(v->expr)))
		BIT_ON(g_conv, POINT);
	if (BIT_TEST(g_conv, NORM) && (!ft_strnchr(v->expr, 'h', ft_flagslen(
						v->expr))))
		v->len = ft_long(buff2, v->buff + v->index, v->expr, *v->tmp);
	else if (BIT_TEST(g_conv, NORM) && ft_strnchr(v->expr, 'h',
				ft_flagslen(v->expr)))
	{
		if (ft_strnstr(v->expr, "hh", ft_flagslen(v->expr)))
			BIT_ON(g_conv, HH);
		else if (ft_strnchr(v->expr, 'h', ft_flagslen(v->expr)))
			BIT_ON(g_conv, H);
		v->len = ft_short(buff2, v->buff + v->index, v->expr, *v->tmp);
	}
	v->len2 = 0;
	g_retlen = v->len;
}

static void	ft_vsprintf3(t_vsprintf *v, char *buff2, va_list *ap)
{
	ft_vsprintf2(v, buff2, ap);
	while (ft_strchr(FLAG, *v->expr))
	{
		if (g_mod[(int)*v->expr])
			v->len2 += (*g_mod[(int)*v->expr])(buff2,
					v->buff + v->index + v->len2, v->expr, *v->tmp);
		if ((*v->expr >= '1' && *v->expr <= '9') || *v->expr == '-'
				|| *v->expr == '.')
			while ((v->expr[1] >= '0' && v->expr[1] <= '9'))
				v->expr++;
		v->expr++;
	}
	v->index += v->len;
	v->index += v->len2;
	ft_strn0cat(v->buff + v->index - v->len - v->len2, buff2, v->len + v->len2);
}

int			ft_vsprintf(char *buff, char *format, va_list *ap)
{
	t_vsprintf	v;
	char		buff2[0xf000];
	char		form[0xF000];

	if (!ft_strcmp(format, "%"))
		return (0);
	ft_bzero(form, 0xF000);
	v.expr = ft_organize(form, format);
	v.index = 0;
	v.len = 0;
	v.buff = buff;
	v.format = format;
	while (*v.expr)
	{
		if (*v.expr == '%')
			ft_vsprintf3(&v, buff2, ap);
		else
			buff[v.index++] = *v.expr;
		g_conv = 0;
		v.expr++;
	}
	return (v.index);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:25:18 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/29 17:00:39 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

char	g_op = 0;

int		ft_itoau64(char *buffer, uint64_t n)
{
	int				len;
	uint64_t		tmp;

	tmp = n;
	len = 0;
	while (tmp > 9 && ((tmp /= 10)))
		len++;
	buffer[len++ + 1] = 0;
	while (len)
	{
		buffer[--len] = '0' + n % 10;
		n /= 10;
	}
	return (ft_strlen(buffer));
}

int		ft_itoa64(char *buffer, int64_t s)
{
	uint64_t	n;

	n = s;
	buffer[0] = 0;
	if (s < 0)
	{
		n = -s;
		buffer[0] = '-';
	}
	return (ft_itoau64(buffer + ((buffer[0] == '-') ? 1 : 0), n)
	+ ((buffer[0] == '-') ? 1 : 0));
}

void	ft_long2(t_data *d, int *uns, char *opl, int len)
{
	if (ft_strnchr(opl, 'j', len) && SIGNED(g_op) && ((*uns = UINTMAX)))
		d->umax = (uintmax_t)g_tmp;
	else if (ft_strnchr(opl, 'j', len) && !SIGNED(g_op) && ((*uns = INTMAX)))
		d->max = (intmax_t)g_tmp;
	else if (ft_strnchr(opl, 'z', len) && SIGNED(g_op) && ((*uns = LLUINT)))
		d->u64 = (size_t)g_tmp;
	else if (ft_strnchr(opl, 'z', len) && ((*uns = LLINT)))
		d->ll = (size_t)g_tmp;
	else if (opl[1] == 'l')
	{
		if (SIGNED(g_op) && ((*uns = LLUINT)))
			d->u64 = (unsigned long long int)g_tmp;
		else if ((*uns = LLINT))
			d->ll = (long long int)g_tmp;
	}
	else
	{
		if (SIGNED(g_op) && ((*uns = LLUINT)))
		{
			d->u64 = (unsigned long)g_tmp;
		}
		else if ((*uns = LINT))
			d->l = (long)g_tmp;
	}
}

void	ft_long3(t_data *d, int *uns, char *opl, int len)
{
	if ((g_op == 'D') && ((*uns = LLINT)))
		d->ll = g_tmp;
	else if ((g_op == 'O') && ((*uns = LLUINT)))
		d->u64 = g_tmp;
	else if ((g_op == 'U') && ((*uns = LLUINT)))
		d->u64 = g_tmp;
	else if (!ft_strnchr(opl, 'l', len) && !ft_strnchr(opl, 'h', len) &&
			!ft_strnchr(opl, 'j', len) && !ft_strnchr(opl, 'z', len)
			&& SIGNED(g_op) && ((*uns = UINT)))
		d->u = (unsigned int)g_tmp;
	else if (!ft_strnchr(opl, 'l', len) && !ft_strnchr(opl, 'h', len) &&
			!ft_strnchr(opl, 'j', len) && !ft_strnchr(opl, 'z', len) &&
			(g_op == 'i' || g_op == 'd') && !((*uns = INT)))
		d->i = (int)g_tmp;
	else
		ft_long2(d, uns, opl, len);
}

int		ft_long(char *value, char *buff, char *opl, char op)
{
	t_data		d;
	int			uns;
	int			len;
	char		*tmp;

	g_op = op;
	tmp = opl;
	len = 0;
	while (ft_strchr(FLAG, *tmp++))
		len++;
	d.u64 = 0;
	uns = 0;
	ft_long3(&d, &uns, opl, len);
	(void)buff;
	return (ft_setint(value, &d, op, uns));
}

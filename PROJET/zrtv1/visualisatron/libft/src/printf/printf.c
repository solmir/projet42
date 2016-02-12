/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 16:13:44 by alelievr          #+#    #+#             */
/*   Updated: 2016/01/21 16:30:28 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fprintf(char *expr, int fd, ...)
{
	static char	buff[0xf0000];
	va_list		ap;
	int			tmp;

	ft_bzero(buff, sizeof(buff));
	va_start(ap, fd);
	tmp = ft_vsprintf(buff, expr, &ap);
	write(fd, buff, tmp);
	va_end(ap);
	return (tmp);
}

int		ft_printf(char *expr, ...)
{
	static char	buff[0xf0000];
	va_list		ap;
	int			tmp;

	ft_bzero(buff, sizeof(buff));
	va_start(ap, expr);
	tmp = ft_vsprintf(buff, expr, &ap);
	write(1, buff, tmp);
	va_end(ap);
	return (tmp);
}

int		ft_vprintf(char *expr, va_list *ap)
{
	int			tmp;
	static char	buff[0xf0000];

	ft_bzero(buff, sizeof(buff));
	tmp = ft_vsprintf(buff, expr, ap);
	write(1, buff, tmp);
	return (tmp);
}

int		ft_sprintf(char *buff, char *expr, ...)
{
	va_list	ap;
	int		tmp;

	va_start(ap, expr);
	tmp = ft_vsprintf(buff, expr, &ap);
	va_end(ap);
	return (tmp);
}

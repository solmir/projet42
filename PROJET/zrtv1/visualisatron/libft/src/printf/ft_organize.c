/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_organize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 17:37:23 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/27 14:42:49 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_organize2(char *buff, char *format, int len, int i)
{
	char	*tmp;

	tmp = format;
	while (*tmp && tmp - format < len)
	{
		if (*tmp == '0' && !((tmp[-1] >= '0' && tmp[-1] <= '9')
					|| tmp[-1] == '.'))
			buff[i++] = '0';
		tmp++;
	}
	if (ft_strnchr(format, '+', len))
		buff[i++] = '+';
	if (ft_strnchr(format, ' ', len))
		buff[i++] = ' ';
	tmp = format;
	if (ft_strnchr(format, '#', len))
		buff[i++] = '#';
	return (i);
}

static int	ft_organize3(char *buff, char *format, int len, int i)
{
	char	*tmp;
	int		t;

	tmp = format - 1;
	t = 0;
	while (*++tmp && tmp - format < len)
	{
		if ((((*tmp >= '1' && *tmp <= '9') || *tmp == '-')
					&& tmp[-1] != '.') || (t == 1 && *tmp == '0'))
		{
			buff[i++] = *tmp;
			t = 1;
		}
		if (*tmp == '.')
			break ;
	}
	if (ft_strnchr(format, '.', len))
	{
		t = ft_firstocc(format, '.');
		buff[i++] = '.';
		while ((tmp[t] >= '0' && tmp[t] <= '9') || tmp[t] == '-')
			buff[i++] = tmp[t++];
	}
	return (i);
}

static int	ft_organize5(char *buff, char **form, int len, int i)
{
	char	*tmp;

	tmp = *form;
	while (ft_strchr(FLAG, *tmp))
		tmp++;
	if ((ft_strnstr(*form, "ll", len) || ft_strnchr(*form, 'l', len))
			&& *tmp == 'd' && ((*form += (ft_strnstr(*form, "ll",
							len) ? 2 : 1))))
		buff[i++] = 'D';
	else if (ft_strnstr(*form, "ll", len) && ((buff[i++] = 'l')))
		buff[i++] = 'l';
	else if (ft_strnchr(*form, 'l', len))
		buff[i++] = 'l';
	if (ft_strnstr(*form, "hh", len) && (*tmp == 'D' || *tmp == 'O'
				|| *tmp == 'S' || *tmp == 'U' || *tmp == 'C') && (((*form)++)))
		buff[i++] = 'h';
	else if (ft_strnstr(*form, "hh", len) && ((buff[i++] = 'h')))
		buff[i++] = 'h';
	else if (ft_strnchr(*form, 'h', len))
		buff[i++] = 'h';
	if (ft_strnchr(*form, 'z', len))
		buff[i++] = 'z';
	if (ft_strnchr(*form, 'j', len))
		buff[i++] = 'j';
	return (i);
}

static int	ft_organize4(char *buff, char **format, int len, int i)
{
	char	*tmp;

	tmp = *format;
	while (ft_strchr(FLAG, *tmp))
		tmp++;
	if ((ft_strnstr(*format, "ll", len) || ft_strnchr(*format, 'l', len))
			&& *tmp == 'o' && ((*format += (ft_strnstr(*format, "ll", len)
						? 2 : 1))))
		buff[i++] = 'O';
	else if ((ft_strnstr(*format, "ll", len) || ft_strnchr(*format, 'l',
					len))
			&& *tmp == 's' && ((*format += (ft_strnstr(*format, "ll", len)
						? 2 : 1))))
		buff[i++] = 'S';
	else if ((ft_strnstr(*format, "ll", len) || ft_strnchr(*format, 'l',
					len))
			&& *tmp == 'c' && ((*format += (ft_strnstr(*format, "ll", len)
						? 2 : 1))))
		buff[i++] = 'C';
	else if ((ft_strnstr(*format, "ll", len) || ft_strnchr(*format, 'l',
					len))
			&& *tmp == 'u' && ((*format += (ft_strnstr(*format, "ll",
							len) ? 2 : 1))))
		buff[i++] = 'U';
	return (ft_organize5(buff, format, len, i));
}

char		*ft_organize(char *buff, char *format)
{
	int		len;
	char	*tmp;
	int		i;
	int		l;

	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			l = i;
			buff[i++] = *format++;
			tmp = format;
			len = 0;
			while (ft_strchr(FLAG, *tmp++))
				len++;
			i = ft_organize2(buff, format, len, i);
			i = ft_organize3(buff, format, len, i);
			i = ft_organize4(buff, &format, len, i);
			format += (i - l) - 1;
		}
		buff[i++] = *format++;
	}
	buff[i] = 0;
	return (buff);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 18:03:17 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/28 19:01:24 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_std.h"

t_str	stdtr(t_str *s, char c, char sub)
{
	int		i;

	i = 0;
	while (s->buff[i])
	{
		if (s->buff[i] == c)
			s->buff[i] = sub;
		i++;
	}
	return (*s);
}

int		stdcmp(t_str *s, char *str)
{
	return (ft_strcmp(s->buff, str));
}

int		ret_stdbase(char c)
{
	if (c <= '9')
		return (c - '0');
	if (c <= 'Z')
		return (c - 'A' + 10);
	if (c <= 'z')
		return (c - 'a' + 10);
	return (-1);
}

int		stdconv(t_str *s, int b)
{
	int		c;
	int64_t	buffer;
	int		i;

	i = 0;
	buffer = 0;
	c = ft_strlen(s->buff) - 1;
	while (c + 1)
		buffer += ret_stdbase(s->buff[i++]) * ft_pow(b, c--);
	return (buffer);
}

char	*stdstrstr(t_str *s, char *str)
{
	return (ft_strstr(s->buff, str));
}

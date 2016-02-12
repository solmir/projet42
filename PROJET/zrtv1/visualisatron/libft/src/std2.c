/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:57:01 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/28 21:18:21 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_std.h"

char		*sdup(t_str *s)
{
	if (s->freed == 1)
		free(s->duped);
	s->freed = 1;
	s->duped = ft_strdup(s->buff);
	return (s->duped);
}

char		*val(t_str *s)
{
	return (s->buff);
}

int			stdlen(t_str *s)
{
	return (s->strlen);
}

t_str		set(t_str *s, char *str)
{
	int		i;

	i = 0;
	ft_bzero(s->buff, 0xF00);
	while (*str)
		s->buff[i++] = *str++;
	s->strlen = ft_strlen(s->buff);
	s->null = (char *)1;
	return (*s);
}

t_str		cat(t_str *s, char *str)
{
	int		i;

	if (s->null == NULL)
		std_init(s);
	i = 0;
	while (s->buff[i])
		i++;
	while (*str)
		s->buff[i++] = *str++;
	s->strlen = ft_strlen(s->buff);
	return (*s);
}

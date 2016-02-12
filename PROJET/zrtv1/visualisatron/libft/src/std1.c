/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 17:59:00 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/28 18:59:13 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_std.h"

int		stdatoi(t_str *str)
{
	return (ft_atoi(str->buff));
}

int		tlen(t_str *s)
{
	return (s->tablen);
}

char	**tdup(t_str *s)
{
	int		i;
	char	**ret;

	i = s->tablen;
	if (!(ret = (char **)malloc(sizeof(char *) * (s->tablen + 1))))
		error("malloc");
	ret[i] = NULL;
	while (i--)
		ret[i] = ft_strdup(s->tbuff[i].buff);
	return (ret);
}

void	stdfree(t_str *s)
{
	if (s->freed)
		free(s->duped);
	s->freed = 0;
	if (s->freet)
		free(s->tbuff);
	s->freet = 0;
}

char	*ndup(t_str *s, int n)
{
	if (s->freed == 1)
		free(s->duped);
	s->freed = 1;
	s->duped = ft_strndup(s->buff, n);
	return (s->duped);
}

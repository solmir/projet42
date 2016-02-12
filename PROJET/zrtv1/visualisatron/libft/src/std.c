/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 13:27:16 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/28 20:59:16 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_std.h"

char			*next_word(t_str *s)
{
	static int		i = 0;
	static int		d = 0;
	char			*ret;

	d = 0;
	if (!s->buff[i] && d == 0)
	{
		d = 1;
		i = 0;
		return (NULL);
	}
	while (s->buff[i] && (s->buff[i] == ' ' || s->buff[i] == '\t'
				|| s->buff[i] == '\r' || s->buff[i] == '\n'))
		i++;
	ret = s->buff + i;
	while (s->buff[i] && s->buff[i] != ' ' && s->buff[i] != '\t' &&
			s->buff[i] != '\n' && s->buff[i] != '\r')
		i++;
	return (ret);
}

t_str			std_init(t_str *s)
{
	s->set = set;
	s->cat = cat;
	s->disp = disp;
	s->split = split;
	s->tdisp = tdisp;
	s->null = NULL;
	s->parent = NULL;
	s->dup = sdup;
	s->ndup = ndup;
	s->freed = 0;
	s->freet = 0;
	s->stdfree = stdfree;
	s->tdup = tdup;
	s->tlen = tlen;
	s->val = val;
	s->len = stdlen;
	s->atoi = stdatoi;
	s->icat = icat;
	s->tr = stdtr;
	s->cmp = stdcmp;
	s->conv = stdconv;
	s->str = stdstrstr;
	s->next_word = next_word;
	return (*s);
}

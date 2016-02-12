/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 18:01:45 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/28 21:21:20 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_std.h"

void		disp(t_str *s)
{
	if (s->null)
		ft_putendl(s->buff);
}

void		split2(char tb[0xF0][0xF00], t_str *s, int tlen)
{
	s->tablen = tlen;
	if (s->freet == 1)
		free(s->tbuff);
	if (!(s->tbuff = (t_str *)malloc(sizeof(t_str) * (tlen + 1))))
		error("malloc");
	s->tbuff[tlen + 1].null = NULL;
	while (tlen--)
	{
		std_init(&s->tbuff[tlen]);
		s->tbuff[tlen].set(&s->tbuff[tlen], tb[tlen]);
		s->tbuff[tlen].parent = s;
	}
	s->freet = 1;
}

t_str		*split(t_str *s, char *split)
{
	int		block;
	int		i;
	int		j;
	int		tlen;
	char	tb[0xF0][0xF00];

	i = 0;
	tlen = 0;
	block = ft_strlen(split);
	while (s->buff[i])
	{
		while (!ft_strncmp(s->buff + i, split, block))
			i += block;
		if (!s->buff[i])
			break ;
		j = 0;
		while (ft_strncmp(s->buff + i, split, block) && s->buff[i])
			tb[tlen][j++] = s->buff[i++];
		tb[tlen++][j] = 0;
	}
	split2(tb, s, tlen);
	return (s->tbuff);
}

void		tdisp(t_str *s)
{
	int		i;

	i = 0;
	if (s && s->tbuff)
		while (s->tbuff[i].null)
			ft_putendl(s->tbuff[i++].buff);
}

t_str		icat(t_str *s, int n, int b)
{
	static char		*base = "0123456789abcdefghijklmnopqrstuvwxyz";
	int				i;
	uint64_t		tmp;
	char			*buff;

	if (s->null == NULL)
		std_init(s);
	buff = s->buff;
	i = (n < 0) ? 1 : 0;
	tmp = (n < 0) ? -n : n;
	while (tmp >= (uint64_t)b && ((tmp /= b) || 1))
		i++;
	buff[i + 1] = 0;
	tmp = (n < 0) ? -n : n;
	s->len += i;
	while (tmp >= (uint64_t)b && ((buff[i--] = base[tmp % b])))
		tmp /= b;
	buff[i] = base[tmp % b];
	buff[0] = (n < 0) ? '-' : buff[0];
	return (*s);
}

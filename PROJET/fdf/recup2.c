/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 22:42:23 by jromagna          #+#    #+#             */
/*   Updated: 2015/06/03 22:42:24 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_bzero(char *b, int i)
{
	while (i >= 0)
	{
		if (b[i] == '\0')
			return (1);
		i--;
	}
	return (0);
}

void		la_magicienne(char *name, int *x, int *y)
{
	int		fd;
	char	b[16000];
	int		i;
	int		ret;

	*y = 0;
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error("error");
	while ((ret = read(fd, b, sizeof(b))) > 0)
	{
		if (check_bzero(b, ret - 1) == 1)
			ft_error("binary file?");
		b[ret] = '\0';
		i = -1;
		while (++i <= ret)
		{
			if (count_word_makina(b + i) > *x)
				*x = count_word_makina(b + i);
			if (b[i] == '\n')
				(*y)++;
		}
	}
	close(fd);
}

int			count_word_makina(char *s)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		while (s[i] && s[i] != '\n' && (s[i] == ' ' || s[i] == '	'))
			i++;
		if (s[i] && s[i] != '\n')
			x++;
		else
			break ;
		while (s[i] && s[i] != '\n' && (s[i] != ' ' && s[i] != '	'))
			i++;
	}
	return (x);
}

void		put_endl_in_file(char *name)
{
	int		fd;
	int		errno;
	char	buf[9];
	int		ret;

	errno = 0;
	if ((fd = open(name, O_RDWR | O_APPEND)) == -1)
		ft_error("error");
	while ((ret = read(fd, buf, 8)) > 0)
		buf[ret] = '\0';
	ret = ft_strlen(buf);
	if (buf[ret - 1] != '\n')
		ft_putstr_fd("\n", fd);
}

void		*ftm(size_t size)
{
	static char	bf[0xF0000] = {0};
	static int	i = 0;
	void		*ret;

	ret = bf + i;
	i += size;
	return (ret);
}


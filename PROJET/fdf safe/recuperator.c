/* ************************************************************************** */
/*	                                                                   */
/*                                                        :::      ::::::::   */
/*   recuperator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 15:59:52 by jromagna          #+#    #+#             */
/*   Updated: 2015/04/22 15:59:53 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_spe_atoi(const char *str)
{
	int		i;
	int		k;
	int		s;

	i = 0;
	k = 0;
	while (str[i] && (str[i] < '0' || str[i] > '9'))
		i++;
	if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	s = (str[i - 1] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + str[i] - '0';
		i++;
	}
	return (s * k);
}

#include <stdio.h>

 void	*ftm(size_t size)
 {
	static char buff[0xF0000] = {0};
	static int  i = 0;
	void	*ret;

	ret = buff + i;
	i += size;
	return (ret);
 }

void	la_magicienne(char *name, int *x, int *y/*, int nb*/)
{
	int		fd;
	char	buf[0xf00];
	int		i;
	int		ret;
	int 	roo;

	errno = 0;
	*y = 0;
	roo = 0;
	//ft_putcoolnbr(nb, "nb");
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error("error");
	if (errno != 0)
		ft_error(strerror(errno));
	while ((ret = read(fd, buf, sizeof(buf))) > 0)
	{
		roo++;
		buf[ret] = '\0';
		i = -1;
		//ft_putstr(buf);
		while(++i <= ret)
		{
			if (count_word_makina(buf + i) > *x)
				*x = count_word_makina(buf + i);
			if(buf[i] == '\n' || (buf[i] == '\0'/* && roo == nb*/))
				(*y)++;
		}
	}
	close(fd);
}

int		**intcreator(char *name, int x, int y)
{
	int 	**tabint;
	int 	i[3];
	int 	j;
	int 	fd[2];
	char	buf[0xf00];

	j = 0;
	i[2] = 0;
	if ((fd[0] = open(name, O_RDONLY)) == -1)
		ft_error("error");
	tabint = (int**)ftm(sizeof(int*) * y);
	while (j < y)
	{
		tabint[j] = (int*)ftm(sizeof(int) * x);
		j++;
	}
	j = 0;
	i[1] = 0;
	while ((fd[1] = read(fd[0], buf, sizeof(buf))))
	{
		i[0] = 0;
		buf[fd[1]] = '\0';
		while(i[0] < fd[1])
		{
			tabint[j][i[1]] = ft_spe_atoi(buf + i[0]);
			i[1]++;
			while (buf[i[0]] && buf[i[0]] != '\n' && (buf[i[0]] == ' ' || buf[i[0]] == '	'))
				i[0]++;
			while (buf[i[0]] && buf[i[0]] != '\n' && (buf[i[0]] != ' ' && buf[i[0]] != '	'))
				i[0]++;
			if (buf[i[0]] == '\n' || buf[i[0]] == '\0')
			{
				i[0]++;
				i[1] = 0;
				j++;
				if (j > y)
					break;
			}
		}
	}
	close(fd[1]);
	puttabint(tabint, x, y);
	return (tabint);
}

int		**recuperator(char *name, t_sup *s)
{
	int		x;
	int		y;
	int 	**tabint;

	put_endl_in_file(name);
	la_magicienne(name, &x, &y/*, read_count(name)*/);
	s->xl = x;
	s->yl = y;
	ft_putcoolnbr(x, "x");
	ft_putcoolnbr(y, "y");
	tabint = intcreator(name, x, y);
	return (tabint);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 07:50:24 by jromagna          #+#    #+#             */
/*   Updated: 2015/05/19 07:50:27 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int			ft_spe_atoi(const char *str)
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

int			go_to_next_word(char *b, int i)
{
	while (b[i] && b[i] != '\n' && (b[i] == ' ' || b[i] == '	'))
		i++;
	while (b[i] && b[i] != '\n' && (b[i] != ' ' && b[i] != '	'))
		i++;
	return (i);
}

inline void	intcreator2(int *i, char *b, int **tabint)
{
	i[0] = 0;
	b[i[5]] = '\0';
	while (i[0] < i[5])
	{
		tabint[i[3]][i[1]] = ft_spe_atoi(b + i[0]);
		i[1]++;
		i[0] = go_to_next_word(b, i[0]);
		if (b[i[0]] == '\n')
		{
			i[0]++;
			i[1] = 0;
			i[3]++;
			if (i[3] > i[6])
				break ;
		}
	}
}

int			**intcreator(char *name, int x, int y)
{
	int		**tabint;
	int		i[7];
	char	b[16000];

	i[3] = -1;
	i[2] = 0;
	i[6] = y;
	if ((i[4] = open(name, O_RDONLY)) == -1)
		ft_error("error");
	tabint = (int**)ftm(sizeof(int*) * i[6]);
	while (++i[3] < i[6])
		tabint[i[3]] = (int*)ftm(sizeof(int) * x);
	i[3] = 0;
	i[1] = 0;
	while ((i[5] = read(i[4], b, sizeof(b))))
		intcreator2(i, b, tabint);
	close(i[5]);
	return (tabint);
}

int			**recuperator(char *name, t_env *s)
{
	int		x;
	int		y;
	int		**tabint;

	put_endl_in_file(name);
	x = 0;
	y = 0;
	la_magicienne(name, &x, &y);
	s->maplx = x;
	s->maply = y;
	if (x < 3 || y < 3)
		ft_error("map too small");
	if (x > 983040 || y > 983040)
		ft_error("map too big");
	tabint = intcreator(name, x, y);
	return (tabint);
}

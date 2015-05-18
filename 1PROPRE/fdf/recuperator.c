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

int		ft_error(char *str)
{
	ft_putendl_fd("-> FDF : \"ERROR :3 try again <3\"", 2);
	ft_putendl_fd("-> you : let's do this !", 2);
	ft_putstr_fd("ERROR is : ", 2);
	ft_putendl_fd(str, 2);
	exit (1);
	return (0);
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

int		count_word_makina(char *str)
{
	int i;
	int	x;

	i = 0;
	x = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		while (str[i] && str[i] != '\n' && (str[i] == ' ' || str[i] == '	'))
			i++;
		if (str[i] && str[i] != '\n')
			x++;
		else 
			break;
		while (str[i] && str[i] != '\n' && (str[i] != ' ' && str[i] != '	'))
			i++;
	}
	return (x);
}

void	la_magicienne(char *name, int *x, int *y)
{
	int		fd;
	char	buf[0xf00];
	int		i;
	int		ret;

	*y = 0;
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error("error");
	while ((ret = read(fd, buf, sizeof(buf) - 1)))
	{
		buf[ret] = '\0';
		*x = count_word_makina(buf);
		i = -1;
		while(++i < ret)
			if(buf[i] == '\n')
				(*y)++;
	}
	close(fd);
}

void 	puttabint(int **tabint, int x, int y)
{
	int i;
	int j;

	i = 0;
	ft_putendl("putinttab");
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putnbr(tabint[i][j]);
			j++;
		}
		i++;
	}
}

int		**intcreator(char *name, int x, int y)
{
	int 	**tabint;
	int 	i[2];
	int 	j;
	int 	fd[2];
	char	buf[0xf00];

	j = 0;
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
	while ((fd[1] = read(fd[0], buf, sizeof(buf) - 1)))
	{
		i[0] = 0;
		buf[fd[1]] = '\0';
		while(i[0] < fd[1])
		{
			tabint[j][i[1]] = atoi(buf + i[0]);
			i[1]++;
			while (buf[i[0]] && buf[i[0]] != '\n' && (buf[i[0]] == ' ' || buf[i[0]] == '	'))
				i[0]++;
			while (buf[i[0]] && buf[i[0]] != '\n' && (buf[i[0]] != ' ' && buf[i[0]] != '	'))
				i[0]++;
			if (buf[i[0]] == '\n')
			{
				i[0]++;
				i[1] = 0;
				j++;
				if (j > y)
					break;
			}
		}
	}
	//puttabint(tabint, x, y);
	return (tabint);
}

int		**recuperator(char *name, t_sup *s)
{
	int		fd;
	int		x;
	int		y;
	int 	**tabint;

	la_magicienne(name, &x, &y);
	s->xl = x;
	s->yl = y;
//	ft_putcoolnbr(x,"x = ");
//	ft_putcoolnbr(y,"y = ");
	tabint = intcreator(name, x, y);
	return (tabint);
}

/*
void 	ft_puttabi(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr("  ");
		ft_putendl(tab[i]);
		i++;
	}
}

char		***recuperator(char *str)
{
	int			fd;
	char		buf[65];
	char 		*fich;
	char 		**tab;
	int			ret;
	char		***tab3; 
	int			i;
	int			k;
	int			**tabint;

	i = 0;
	k = 0;
	//ft_putendl("RECUPERATOR");
	fich = ft_strdup("\0");
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("probleme fichier");
	while ((ret = read(fd, buf, 64)) != 0)
	{
		k = 0;
		while (buf[k])
		{
			while (buf[k] != '\n')
			{
				ft_atoi()
			}
				i++;
			k++;
		}
		buf[ret + 1] = '\0';
	//	fich = ft_strjoin(fich, buf);
	}
	//tab = ft_strsplit(fich , '\n');
	//ft_puttabi(tab);
	tab3 = tabsplit(tab);
	//ft_putendl("RETURN TAB3");
	return (tab3);
}

char	***tabsplit(char **tab)
{
	char	***master;
	int		i;

	i = 0;
	master = (char ***)malloc(sizeof(char**) * ft_tablen(tab) + 1);
	while (tab[i] != NULL)
	{
		master[i] = ft_strsplit(tab[i], ' ');
		i++;
	}
	master[i] = NULL;
	overputtab(master);
	ft_putcoolnbr(i , "i = ");
	return (master);
}

int		ft_tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void	overputtab(char ***tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr("||");
		ft_puttab(tab[i]);
		ft_putstr("||\n");
		i++;
	}
}

void 	ft_puttab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		if (tab[i + 1])
			ft_putstr("  .  ");
		i++;
	}
}*/


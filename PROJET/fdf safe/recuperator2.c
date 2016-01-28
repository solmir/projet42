/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recuperator2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/18 21:37:53 by jromagna          #+#    #+#             */
/*   Updated: 2015/05/18 21:37:54 by jromagna         ###   ########.fr       */
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

int		count_word_makina(char *s)
{
	int i;
	int	x;

	i = 0;
	x = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		while (s[i] && s[i] != '\n' && (s[i] == ' ' || s[i] == '	'))
			i++;
		if (s[i] && s[i] != '\n')
			x++;
		else 
			break;
		while (s[i] && s[i] != '\n' && (s[i] != ' ' && s[i] != '	'))
			i++;
	}
	return (x);
}

void	ft_puttab(char **tab)
{
	int	i;

	i = 0;

	while(tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		i++;
	}
}
/*
int		read_count(char *name)
{
	int		fd;
	char	buf[0xf00];
	int		i;
	int		ret;

	i = 0;
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error("error");
	while ((ret = read(fd, buf, sizeof(buf))) > 0)
		i++;
	return (i);
}
*/
void 	puttabint(int **tabint, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putnbr(tabint[i][j]);
			//ft_putchar (' ');
			j++; 
		}
		ft_putchar ('\n');
		i++;
	}
}

void	put_endl_in_file(char *name)
{
	int		fd;
	int 	errno;
	char	buf[9];
	int 	ret;

	errno = 0;
	if ((fd = open(name, O_RDWR | O_APPEND)) == -1)
		ft_error("error");
	while ((ret = read(fd, buf, 8)) > 0)
		buf[ret] = '\0';
	ret = ft_strlen(buf);
	if (buf[ret - 1] != '\n')
		ft_putstr_fd("\n", fd);
	if (errno != 0)
		ft_putendl(strerror(errno));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 19:11:07 by jromagna          #+#    #+#             */
/*   Updated: 2015/01/15 19:11:09 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bloc		*ft_pedobear(t_bloc *bloc, dev_t dev)
{
	char	bin[33];
	int		i;
	int		j;
	int		c;

	bin[33] = '\0';
	i = 32;
	j = 0;
	while (j != 32)
	{
		c = its_over_9000((long int)i);
		j = 32 - i;
		if (c < dev)
		{
			dev = dev - c;
			bin[j] = '1';
		}
		else
			bin[j] = '0';
		i--;
	}
	ft_putendl("\nbinaire time");
	ft_putendl(bin);
	bloc->major = ft_nope(bin);
	bloc->minor = come_here_sweety(bin);
	ft_putchar('\n');
	ft_putnbr(bloc->major);
	ft_putnbr(bloc->minor);
	ft_putchar('\n');
	return (bloc);
}

int		come_here_sweety(char	*bin)
{
	int		minor;
	char	shift[33];
	int 	i;
	int 	j;

	shift[33] = '\0';
	i = 0;
	j = 12;
	while (i != 20)
	{
		shift[i] = bin[j];
		i++;
		j++;
	}
	i = 20;
	while (i != 32)
	{
		shift[i] = '0';
		i++;
	}
	minor = bin_to_int(shift);
	return (minor);
}

int		ft_nope(char	*bin)
{
	int		major;
	char	shift[33];
	int 	i;
	int 	j;

	shift[33] = '\0';
	i = 0;
	j = 20;
	while (i != 12)
	{
		shift[j] = bin[i];
		i++;
		j++;
	}
	i = 0;
	while (i != 20)
	{
		shift[i] = '0';
		i++;
	}
	major = bin_to_int(shift);
	return (major);
}

int		bin_to_int(char *bin)
{
	int 	val;
	int 	i;
	int 	j;
	int 	c;

	i = 32;
	val = 0;
	while(i != 0)
	{
		j = 32 - i;
		if (bin[i] == '1')
		{
			c = its_over_9000((long int)j);
			val = val + c;
		}
		i--;
	}
	return (val);
}

int		its_over_9000(long int	i)
{
	long int	j;

	j = 1;
	i = i ;
	ft_putnbr(i);
	ft_putchar('\n');
	while(i != 0)
	{
		j = (j * 2);
		if (i == 0)
			j = j - 1;
		i--;
	}
	ft_putnbr(j);
	ft_putchar('\n');
	ft_putchar('\n');
	return (j);
}
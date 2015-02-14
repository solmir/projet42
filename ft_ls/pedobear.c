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
	int		maj;
	int		min;
	char	*majmin;
	int		lenght;
	int		i;

	i = 0;
	lenght = 0;
	maj = major(dev);
	min = minor(dev);
	majmin = ft_strdup(ft_itoa(maj));
	majmin = ft_strjoin(majmin, ",");
	lenght = ft_strlen(ft_itoa(min));
	while ((4 - i - lenght) != 0)
	{
		majmin = ft_strjoin(majmin, " ");
		i++;
	}
	majmin = ft_strjoin(majmin, ft_itoa(min));
	bloc->size = ft_strdup(majmin);
	return (bloc);
}
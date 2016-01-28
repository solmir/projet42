/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_endl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 09:07:06 by jromagna          #+#    #+#             */
/*   Updated: 2015/05/09 09:07:07 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab_endl(char **tab)
{
	int i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}
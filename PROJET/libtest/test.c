/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 16:39:06 by jromagna          #+#    #+#             */
/*   Updated: 2015/06/08 17:05:56 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/tmp/jantiope/libft.h"

int		main(int	ac , char **av)
{
	char	*tab[6];
	int		**tabint;
	int		i;
	int		j;
	t_list	*lst;

	(void)ac;
	(void)av;
	i = 0;
	j = 0;
	tab[0] = ft_strdup("ceci ");
	tab[1] = ft_strdup("est ");
	tab[2] = ft_strdup("un ");
	tab[3] = ft_strdup("test de ");
	tab[4] = ft_strdup("qualite");
	tab[5] = NULL;
	tabint = (int**)malloc(sizeof(int*) * 5);
	while(i < 5)
	{
		j = 0;
		tabint[i] = (int*)malloc(sizeof(int) * 5);
		while (j < 5)
		{
			tabint[i][j] = j;
			j++;
		}
		i++;
	}
	ft_putstrint(ft_tablen(tab),"ceci est une fonction permettant de rapidement afficher une string ainsi qu'un int. \n le resultat de tablen est");
	ft_putendl ("puttab endl");
	ft_puttab_endl(tab);
	ft_putendl ("puttab");
	ft_puttab(tab);
	ft_putendl("|| bah ya pas de \\n");
	ft_putendl("tab int;");
	ft_putinttab((int**)tabint, 5, 5);
	put_endl_in_file("fich");
	lst = ft_strsplit_to_lst("je suis une liste chainee ceci est un test pour prouver l'efficasite du split en liste chainee", ' ');
	while (lst != NULL && lst->next != NULL)
	{
		ft_putendl((char*)lst->content);
		lst = lst->next;
	}
	ft_error("Le test est fini");
return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 09:33:40 by jromagna          #+#    #+#             */
/*   Updated: 2015/05/09 09:33:42 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*tmp;

	newlst = f(lst);
	if (newlst == NULL)
		return (NULL);
	tmp = newlst;
	while (lst->next != NULL)
	{
		newlst->next = f(lst->next);
		if (newlst == NULL)
			return (NULL);
		newlst = newlst->next;
		lst = lst->next;
	}
	return (tmp);
}

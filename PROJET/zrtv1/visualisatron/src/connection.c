/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:18:18 by alelievr          #+#    #+#             */
/*   Updated: 2016/01/21 15:27:12 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualisatron.h"

int			get_server_sock(int s)
{
	static int	sock = -1;

	if (s != -1)
		sock = s;
	return (sock);
}

void		close_server_connection(void)
{
	int		s;

	s = get_server_sock(-1);
	close(s);
	return ;
}

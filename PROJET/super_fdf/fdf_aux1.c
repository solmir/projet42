/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_aux1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 23:45:50 by jromagna          #+#    #+#             */
/*   Updated: 2015/06/07 23:45:52 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		pixel_to_image(t_env *s, int x, int y, unsigned int color)
{
	unsigned int	off;

	x = verifl(x);
	y = verifh(y);
	off = y * s->sline + x * s->bpp / 8;
	if (x < 0 || y < 0 || y > H_SIZE || x > L_SIZE)
		return ;
	s->img[off] = color >> 0;
	s->img[off + 1] = color >> 8;
	s->img[off + 2] = color >> 16;
}

void		ft_print_instr(void)
{
	ft_putendl("instruction fdf:");
	ft_putendl("fleches directionnel pour deplacer l'image");
	ft_putendl("pgup and pg down pour zoom /dezoom lent");
	ft_putendl("+ and - pour zoom /dezoom rapide");
	ft_putendl("home and end pour modifier la pente");
	ft_putstr("les touches de 1 a 6 du pave directionnel pour");
	ft_putendl("changer les couleurs");
	ft_putendl("fn pour changer le type d'affichage");
	ft_putendl("b pour passer en mode dessin");
}

int			ft_error(char *str)
{
	ft_putendl_fd("-> FDF : \"ERROR :3 try again <3\"", 2);
	ft_putendl_fd("-> you : let's do this !", 2);
	ft_putstr_fd("ERROR is : ", 2);
	ft_putendl_fd(str, 2);
	exit (1);
	return (0);
}

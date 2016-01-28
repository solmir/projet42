/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 07:51:17 by jromagna          #+#    #+#             */
/*   Updated: 2015/05/19 07:51:18 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void		map_verif(int **tabbint, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	while (j < y)
	{
		i = 0;
		if (j == 0 || j == y - 1)
		{
			while (i < x)
			{
				tabbint[j][i] = 5;
				i++;
			}
		}
		else
		{
			tabbint[j][0] = 5;
			tabbint[j][x - 1] = 5;
		}
		j++;
	}
}

void		ft_print_instr(void)
{
	ft_putendl("instruction wolf3d:");
	ft_putendl("utiliser les touches wasd pour vous deplacer.");
	ft_putendl("utiliser les touches q et e pour strafer.");
	ft_putendl("WARNING : epileptiques, ne faites pas la toupis!");
	ft_putendl("utiliser les touches gauche et droite pour faire la toupis.");
	ft_putendl("utiliser la touche esc pour quitter le jeu.");
	ft_putendl("la touche shift permet de changer la vitesse de deplacement.");
	ft_putendl("les touches de 0 a 9 permettent de choisir le fond musical.");
	ft_putendl("il faut prier a proximite du cube d'obsidienne pour");
	ft_putendl("faire changer la musique.");
	ft_putendl("1 - guiles theme.");
	ft_putendl("2 - extrait live le clown evil.");
	ft_putendl("3 - pokemon intro music.");
	ft_putendl("4 - pokemon battle music.");
	ft_putendl("5 - Diggy diggy hole!.");
	ft_putendl("6 - hotline miami - jasper byrne.");
	ft_putendl("7 - the legend of zelda theme song.");
	ft_putendl("8 - nanatsu no taizai op.");
	ft_putendl("9 - airwolf 2 theme.");
	ft_putendl("0 - song of silence.");
}

void		pixel_to_image(t_env *s, int x, int y, unsigned int color)
{
	unsigned int	off;

	off = y * s->sline + x * s->bpp / 8;
	if (x < 0 || y < 0 || y > H_SIZE || x > L_SIZE)
		return ;
	s->img[off] = color >> 0;
	s->img[off + 1] = color >> 8;
	s->img[off + 2] = color >> 16;
}

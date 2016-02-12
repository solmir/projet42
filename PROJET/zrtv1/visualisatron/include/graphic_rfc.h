/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_rfc.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 22:46:33 by alelievr          #+#    #+#             */
/*   Updated: 2016/02/01 20:07:47 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_RFC_H
# define GRAPHIC_RFC_H

/*
**	Special messages:
*/
# define WELCOME_CODE		"00"
/*
**	Syntax: "01 index playerID"
*/
# define MEMORY_CASE		"01"
/*
**	Syntax: "02 index1 player1ID index2 player2ID ..."
*/
# define MEMORY_MAP			"02"
/*
**	Syntax: "03 index playerID"
*/
# define LIVE				"03"
/*
**	Syntax: "04 playerID"
*/
# define DEATH				"04"
/*
**	Syntax: "05"
*/
# define RESET				"05"
/*
**	Syntax: "06 `memory_size in octet`"
*/
# define MEMORY_SIZE		"06"
/*
**	Syntax: "07 `player number`"
*/
# define PLAYER_NUM			"07"

/*
**	Normal interpretation:
*/
# define INFO_CODE			0
# define ERROR_CODE			1
# define WARNING_CODE		2
# define EOM				"\4"

# define CHK_CODE(x)		((*(x)) - '0')
# define CHK_INFO(x, y)		(!ft_strncmp(x, y, 2))

#endif

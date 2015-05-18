/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 22:11:34 by jromagna          #+#    #+#             */
/*   Updated: 2015/03/16 22:11:36 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
 #define PUSH_SWAP

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct		s_opt
{
	int				v;
	int				c;
	int				m;
}					t_opt;

typedef struct		s_pile
{
	int				value;
	int				pilenbr;
	struct s_pile	*next;
//	struct s_pile	*pre;
}					t_pile;

typedef struct		s_point
{
	struct s_pile	*1stdb;
	struct s_pile	*2nddb;
	struct s_pile	*1stfn;
	struct s_pile	*2ndfn;
	struct s_pile	*1nope;
	struct s_pile	*2nope;
}					t_point;

t_opt		*get_opt(char **argv, int *size);
t_opt		*new_opt(void);
t_pile		*new_list(void);
t_opt		*lstruct_fill(t_opt *opt, char *ot);
int			opt_verificator(char *tab);
int			ft_error(char *str);
void		ft_putlist(t_pile *pile);
t_pile		*get_list(char **argv, int i);
int			ft_atoi_verif(const char *str);
void		verif_doublon(t_pile *pile);
int			verificator(t_pile *pile);
t_pile		*ft_create_sec(t_pile *pile);
void		dirigeator(t_pile *pile, t_pile *pile2, t_opt *opt);

#endif
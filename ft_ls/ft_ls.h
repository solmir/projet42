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


#ifndef FT_LS_H
# define FT_LS_H

# include <errno.h>
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <stdio.h>
# include <sys/_types/_uid_t.h>

typedef struct			s_lstruct
{
	int					optl;
	int					optR;
	int					optr;
	int					opta;
	int					optt;
	int					nbrdir;
	int					nbr;
	int					tot;
}						t_lstruct;

typedef struct			s_size
{
	int					lusr;
	int					lgrp;
	int					llink;
	int					lsize;
}						t_size;

typedef struct			s_bloc
{
	char				*name;
	char				*path;
	struct passwd		*bufpass;
	struct group		*bufgrp;
	char				*droit;
	char				*link;
	int 				major;
	int 				minor;
	time_t				realtime;
	char				*time;
	int					block;
	char				*size;
	int					inde;
	struct s_bloc		*next;
}						t_bloc;


//initialisation
int					main(int argc, char **argv);
t_bloc				*docfiller(char **argv, int size, int argc, t_bloc *fichier);
t_lstruct			*lstruct_init(char **opt, int *size);
int					opt_verificator(char *tab);

//tbloc filler
char				*file_ton_type(struct stat *buf,char *droit);
char				*file_tes_droits(struct stat *buf);
t_bloc				*t_bloc_filler(t_bloc *bloc);

//new_bloc
t_bloc				*new_bloc();

//ecrire la liste
void				ft_puterror(char *error, char *name);
t_lstruct			*ft_putpath(t_lstruct *opt, t_bloc *bloc);
t_lstruct			*ft_putlist_multidir(t_lstruct *opt, t_bloc *lst, t_bloc *bloc);
t_lstruct			*ft_putlst(t_lstruct *opt, t_bloc *lst);
int					verificator(char *tab);
t_bloc				*alpha_list(t_bloc *dir);

//transition
void				ft_ls(t_lstruct *opt, t_bloc *bloc);

//decoupe blocsis
t_bloc				*decoupator(t_bloc *bloc);
t_bloc				*filator(t_bloc *bloc);
t_bloc				*director(t_bloc *bloc);
t_bloc				*director_pre(t_bloc *bloc);

//auxi
t_bloc				*bloc_dup(t_bloc *bloc);
t_bloc				*bloc_cpy(t_bloc *dst, t_bloc *src);
t_bloc				*path_finder(t_bloc *dir, t_bloc *bloc);

//gere le chemin
void				dir_opener(t_lstruct *opt, t_bloc *bloc);
void				dirigeator(t_lstruct *opt,t_bloc *dir, t_bloc *bloc);

//option l
t_bloc				*t_bloc_filler_link(t_bloc *bloc);
char				*time_guardian(char *time, time_t real_tm);
t_size				*t_size_builder();
t_bloc				*colonisator3(t_bloc *bloc);
t_bloc				*colonisator2(t_bloc *bloc, t_size *size);
int					calculator(blkcnt_t b, t_lstruct *opt, char point);
t_bloc				*colonisator(t_bloc *bloc, t_lstruct *opt);


//PEDOBEAR
t_bloc				*ft_pedobear(t_bloc *bloc, dev_t dev);

//option r
t_bloc				*retournator(t_bloc *dir);

//option R
int					verificator_path(char *tab, t_lstruct *opt);
t_lstruct			*ft_putlist_R(t_lstruct *opt, t_bloc *lst, t_bloc *bloc);

//optin t
t_bloc				*alpha_time(t_bloc *bloc);
t_bloc				*time_attack(t_bloc *dir);


#endif

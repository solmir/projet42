# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      ##    By: jromagna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/15 19:25:51 by jromagna          #+#    #+#              #
#    Updated: 2015/01/15 20:17:26 by jromagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ft_ls.c \
	  ft_ls_aux.c \
	  ft_ls_aux2.c \
	  ft_ls_opt.c \
	  ft_ls_R.c \
	  ft_ls_l.c \
	  ft_ls_a.c \
	  ft_ls_t.c \
	  dirigeator.c \
	  pedobear.c

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
	 
all: $(NAME)
		 
$(NAME):
	make -C libft re
	$(CC) $(CFLAGS) -I libft -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) -L libft -lft -o $(NAME)

clean:
	/bin/rm -f *.o
				 
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

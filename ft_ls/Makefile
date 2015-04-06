# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jromagna <marvin@42.fr>                    +#+  +:+       +#+         #
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
	  ft_ls_gr.c \
	  ft_ls_l.c \
	  ft_ls_t.c \
	  dirigeator.c \
	  pedobear.c \
	  symlink.c \
	  ft_ls_aux3.c \

OBJ = $(SRC:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)
		 
$(NAME): $(OBJ)
	@echo "libft start"
	@make -C libft
	@echo "libft ok"
	@echo "comp start"
	$(CC) $(CFLAGS) -I libft -c $(SRC)
	@$(CC) $(CFLAGS) $(OBJ) -L libft -lft -o $(NAME)
	@echo "ALL DONE"

norm:
	norminette $(SRC)

clean:
	@echo "cleaning .o"
	@/bin/rm -f $(OBJ)
	@echo "cleaning .o done"
				 
fclean: clean
	@echo "cleaning NAME"
	@/bin/rm -f $(NAME)
	@echo "cleaning NAME done"

re: fclean all

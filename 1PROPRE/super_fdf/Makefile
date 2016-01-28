# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jromagna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/10 23:44:43 by jromagna          #+#    #+#              #
#    Updated: 2015/05/09 13:44:51 by jromagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c \
	  calculator.c \
	  fdf_aux1.c \
	  recup.c \
	  recup2.c \
	  rendu.c \
	  key_hook.c \
	  key_hook2.c 


OBJ = $(SRC:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror -g -ggdb -g3

all: $(NAME)

do: $(NAME)
	./fdf

$(NAME): $(OBJ)
	@echo "libft start"
	@make -C libft
	@echo "libft ok"
	@echo "comp start"
	@$(CC) $(CFLAGS) -L libft -lft -lmlx -framework OpenGL -framework AppKit $(OBJ) -o fdf
	@echo "ALL DONE"

norm:
	norminette $(SRC)

clean:
	@echo "cleaning .o"
	@/bin/rm -f $(OBJ)
	@make -C libft clean
	@echo "cleaning .o done"
				 
fclean: clean
	@echo "cleaning NAME"
	@/bin/rm -f $(NAME)
	@make -C libft fclean
	@echo "cleaning NAME done"

re: fclean all

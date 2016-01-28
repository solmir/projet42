# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jromagna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/10 23:44:43 by jromagna          #+#    #+#              #
#    Updated: 2015/05/13 20:05:35 by jromagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = ./SRC/wolf3d.c \
	  ./SRC/recup.c \
	  ./SRC/recup2.c \
	  ./SRC/wolf3d_aux1.c \
	  ./SRC/calculator.c \
	  ./SRC/calculator2.c \
	  ./SRC/draw.c \
	  ./SRC/key_hook.c \
	  ./SRC/move.c


OBJ = $(SRC:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror -O3

all: $(NAME)

$(NAME): $(OBJ)
	@echo "libft start"
	@make -C libft
	@echo "libft ok"
	@echo "comp start"
	@$(CC) $(CFLAGS) -L libft -lft -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)
	@echo "ALL DONE"

norm:
	norminette **[ch]

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

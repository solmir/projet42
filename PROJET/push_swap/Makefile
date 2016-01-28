# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jromagna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 23:00:00 by jromagna          #+#    #+#              #
#    Updated: 2015/03/16 23:00:01 by jromagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c \
	  ps_act_2.c \
	  ps_act_1.c \
	  ps_opt.c \
	  ps_diri.c

LIB = libft
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	@echo "libft start"
	@make -C libft
	@echo "libft ok"
	@echo "comp start"
	@$(CC) $(CFLAGS) -I $(LIB) -c $(SRC)
	@$(CC) $(CFLAGS) $(OBJ) -L libft -lft -o $(NAME)
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
	@echo "cleaning NAME done"
	@make -C libft fclean

re: fclean all


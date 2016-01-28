# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jromagna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/05 18:14:34 by jromagna          #+#    #+#              #
#    Updated: 2015/06/08 17:05:21 by jromagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_lib_bonus

SRC = test.c

OBJ = $(SRC:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror -O3

all: $(OBJ)
	$(CC) $(CFLAGS) -L /tmp/jantiope -lft $(OBJ) -o $(NAME)
	cat -e "fich"
	./$(NAME)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 15:43:33 by amdemuyn          #+#    #+#              #
#    Updated: 2023/03/06 16:26:16 by amdemuyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC		= main.c \
		  create_stacks.c \
		  push_swap.c \
		  tiny_sort.c \
		  big_radix.c \
		  a_moves.c \
		  b_moves.c \
		  utils.c \
		  ft_split.c

OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

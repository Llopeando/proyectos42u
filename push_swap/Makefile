# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 13:33:56 by ullorent          #+#    #+#              #
#    Updated: 2022/02/09 13:33:07 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP_EXE = push_swap

CSRC = push_swap.c \
push_swap_utils.c \
push_swap_errorschk.c \
push_swap_cmd_sp.c \
push_swap_cmd_r.c

OSRC = $(CSRC:.c=.o)

LIBFT_LIB = libft/libft.a

GCCCMD = gcc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

all: $(PUSH_SWAP_EXE)

$(PUSH_SWAP_EXE): $(LIBFT_LIB) $(CSRC)
	$(GCCCMD) $(CFLAGS) $(CSRC) $(LIBFT_LIB) -o $(PUSH_SWAP_EXE)

$(LIBFT_LIB): libft/*.c libft/libft.h
	make -C libft

clean:
	make -C libft/ clean
	rm -f $(OSRC)

fclean: clean
	rm -f $(PUSH_SWAP_EXE)

re: fclean all

.PHONY: all clean fclean re

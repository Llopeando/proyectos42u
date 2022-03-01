# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 13:33:56 by ullorent          #+#    #+#              #
#    Updated: 2022/03/01 18:01:01 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP_EXE = push_swap

CSRC = push_swap.c \
push_swap_utils.c \
push_swap_errorschk.c \
push_swap_cmd_sp.c \
push_swap_cmd_r.c \
push_swap_cmd_rr.c \
push_swap_algo.c \
push_swap_quicksort.c

OSRC = $(CSRC:.c=.o)

LIBFT_LIB = libft/libft.a

GCCCMD = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(PUSH_SWAP_EXE)

%.o: %.c
	$(GCCCMD) $(CFLAGS) -c $^ -o $@

$(PUSH_SWAP_EXE): $(LIBFT_LIB) $(OSRC)
	$(GCCCMD) $(CFLAGS) $(CSRC) $(LIBFT_LIB) -o $(PUSH_SWAP_EXE)

$(LIBFT_LIB): libft/*.c libft/libft.h
	make -C libft

clean:
	make -C libft/ clean
	rm -f $(OSRC)

fclean: clean
	make -C libft/ fclean
	rm -f $(PUSH_SWAP_EXE)

re: fclean all

.PHONY: all clean fclean re

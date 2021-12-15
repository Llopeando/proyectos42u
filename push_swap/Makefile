# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 13:33:56 by ullorent          #+#    #+#              #
#    Updated: 2021/12/15 13:39:47 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP_EXE = push_swap

CSRC = main.c

OSRC = $(CSRC:.c=.o)

LIBFT_LIB = libft/libft.a

GCCCMD = gcc
CFLAGS = -Wall -Werror -Wextra

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
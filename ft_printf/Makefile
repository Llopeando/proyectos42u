# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 10:57:25 by ullorent          #+#    #+#              #
#    Updated: 2021/10/04 10:52:43 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c \
	ft_printf_csp.c \
	ft_printf_diu.c \
	ft_printf_xx.c

OSRC = ft_printf.o \
	ft_printf_csp.o \
	ft_printf_diu.o \
	ft_printf_xx.o

CFLAGS = -Wall -Werror -Wextra

ARCMD = ar rc
GCCCMD = gcc

all: $(NAME)

$(NAME): $(OSRC)
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(ARCMD) $(NAME) $(OSRC)

$(OSRC): $(SRC)
	$(GCCCMD) $(CFLAGS) -c $(SRC)

clean:
	make -C libft/ clean
	rm -f $(OSRC)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
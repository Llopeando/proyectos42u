# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 10:57:25 by ullorent          #+#    #+#              #
#    Updated: 2021/09/29 16:38:22 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c \
	ft_printf_csp.c

OSRC = ft_printf.o \
	ft_printf_csp.o

CFLAGS = -Wall -Werror -Wextra

ARCMD = ar rc
GCCCMD = gcc

all: $(NAME)

$(NAME): $(OSRC)
	$(ARCMD) $(NAME) $(OSRC)

$(OSRC): $(SRC)
	$(GCCCMD) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)

re: fclean all
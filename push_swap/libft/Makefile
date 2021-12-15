# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 10:41:19 by ullorent          #+#    #+#              #
#    Updated: 2021/11/30 14:25:50 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CSRC = ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_strrchr.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strncmp.c \
ft_strdup.c \
ft_strnstr.c \
ft_atoi.c \
ft_memset.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_calloc.c \
ft_substr.c \
ft_strjoin.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_strmapi.c \
ft_striteri.c \
ft_itoa.c \
ft_split.c \
ft_strtrim.c \
ft_bzero.c \
ft_printf.c \
ft_printf_xx.c \
ft_printf_diu.c \
ft_printf_csp.c

OSRC = $(CSRC:.c=.o)

CFLAGS = -Werror -Wall -Wextra -D BUFFER_SIZE=4

ARCMD = ar rc
GCCCMD = gcc

all: $(NAME)

$(NAME): $(OSRC)
	$(ARCMD) $(NAME) $(OSRC)

$(OSRC): $(CSRC) 
	$(GCCCMD) $(CFLAGS) -c $(CSRC)
clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 10:41:19 by ullorent          #+#    #+#              #
#    Updated: 2021/09/10 11:47:48 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isalpha.c \
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
ft_bzero.c

CSRC = ft_isalpha.o \
ft_isdigit.o \
ft_isalnum.o \
ft_isascii.o \
ft_isprint.o \
ft_strlen.o \
ft_strlcpy.o \
ft_strlcat.o \
ft_strrchr.o \
ft_strnstr.o \
ft_toupper.o \
ft_tolower.o \
ft_strchr.o \
ft_strncmp.o \
ft_strdup.o \
ft_atoi.o \
ft_memset.o \
ft_memcpy.o \
ft_memccpy.o \
ft_memmove.o \
ft_memchr.o \
ft_memcmp.o \
ft_calloc.o \
ft_bzero.o

CFLAGS = -Werror -Wall -Wextra

ARCMD = ar rc
GCCCMD = gcc

all: $(NAME)

$(NAME): $(CSRC)
	$(ARCMD) $(NAME) $(CSRC)

$(CSRC): $(SRC) 
	$(GCCCMD) $(CFLAGS) -c $(SRC)
clean:
	rm -f $(CSRC)

fclean: clean
	rm -f $(NAME)

re: fclean all

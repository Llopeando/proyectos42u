# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 10:41:19 by ullorent          #+#    #+#              #
#    Updated: 2021/08/03 12:18:39 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c

CSRC = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strlen.o ft_strlcpy.o ft_strlcat.o ft_toupper.o ft_tolower.o ft_strchr.o
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

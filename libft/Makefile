# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 10:41:19 by ullorent          #+#    #+#              #
#    Updated: 2021/07/21 13:22:42 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c
FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): ft_isalpha.o
	ar rc $(NAME) ft_isalpha.o

ft_isalpha.o: ft_isalpha.c 
	gcc $(FLAGS) -c ft_isalpha.c
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

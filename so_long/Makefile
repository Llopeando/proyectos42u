# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 13:36:53 by ullorent          #+#    #+#              #
#    Updated: 2021/10/27 11:11:21 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CSRC = main.c

OSRC = $(CSRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra
GCCCMD = gcc

all: $(NAME)

$(OSRC): $(CSRC)
	$(GCCCMD) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OSRC)
	$(GCCCMD) $(CFLAGS) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit $< -o $(NAME)

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
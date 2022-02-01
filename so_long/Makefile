# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 13:36:53 by ullorent          #+#    #+#              #
#    Updated: 2022/02/01 19:17:40 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CSRC =	sl_main.c \
sl_window.c \
sl_readmap.c \
sl_otherfunctions.c \
sl_keyboard.c \
sl_keyboard_fct.c \
sl_error_mng.c

OSRC = $(CSRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g3
GCCCMD = gcc

all: $(NAME)

%.o: %.c
	make -C libft
	make -C mlx
	cp libft/libft.a .
	$(GCCCMD) $(CFLAGS) -Imlx -c $^ -o $@

$(NAME): $(OSRC)
	$(GCCCMD) $(CFLAGS) libft.a -Imlx -Iso_long.h -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

clean:
	make -C libft/ clean
	make -C mlx/ clean
	rm -f $(OSRC)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
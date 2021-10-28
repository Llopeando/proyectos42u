# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 13:36:53 by ullorent          #+#    #+#              #
#    Updated: 2021/10/28 13:56:52 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CSRC = sl_readmap.c \
sl_otherfunctions.c

OSRC = $(CSRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra
GCCCMD = gcc

all: $(NAME)

$(OSRC): $(CSRC) ./libft/*.c
	make -C libft
	make -C mlx
	cp libft/libft.a .
	# mv libft.a $(NAME)
	# cp mlx/libmlx.a .
	# mv libmlx.a $(NAME)
	$(GCCCMD) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OSRC)
	$(GCCCMD) $(CFLAGS) libft.a -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit $< -o $(NAME)

clean:
	make -C libft/ clean
	make -C mlx/ clean
	rm -f $(OSRC)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
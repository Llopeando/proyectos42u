# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 14:01:37 by ullorent          #+#    #+#              #
#    Updated: 2021/11/30 16:55:47 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_EXE = server
CLIENT_EXE = client

SERVER_C = server.c
CLIENT_C = client.c
LIBFT_LIB = libft/libft.a

CFLAGS = -Wall -Werror -Wextra
GCCCMD = gcc

all: $(SERVER_EXE) $(CLIENT_EXE)

$(SERVER_EXE): $(LIBFT_LIB) $(SERVER_C)
	$(GCCCMD) $(CFLAGS) $(SERVER_C) $(LIBFT_LIB) -o $(SERVER_EXE)

$(CLIENT_EXE): $(LIBFT_LIB) $(CLIENT_C)
	$(GCCCMD) $(CFLAGS) $(CLIENT_C) $(LIBFT_LIB) -o $(CLIENT_EXE)

$(LIBFT_LIB): libft/*.c libft/libft.h
	make -C libft

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(SERVER_EXE) $(CLIENT_EXE)

re: fclean all

.PHONY: all clean fclean re
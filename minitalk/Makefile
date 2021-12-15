# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 14:01:37 by ullorent          #+#    #+#              #
#    Updated: 2021/12/14 14:12:34 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_EXE = server
SERVER_BONUS_EXE = bonus/server_bonus
CLIENT_EXE = client
CLIENT_BONUS_EXE = bonus/client_bonus

SERVER_C = server.c
SERVER_BONUS_C = bonus/server_bonus.c
CLIENT_C = client.c
CLIENT_BONUS_C = bonus/client_bonus.c

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

bonus: $(LIBFT_LIB) $(SERVER_BONUS_C) $(CLIENT_BONUS_C)
	$(GCCCMD) $(CFLAGS) $(SERVER_BONUS_C) $(LIBFT_LIB) -o $(SERVER_BONUS_EXE)
	$(GCCCMD) $(CFLAGS) $(CLIENT_BONUS_C) $(LIBFT_LIB) -o $(CLIENT_BONUS_EXE)

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(SERVER_EXE) $(CLIENT_EXE)
	rm -f $(SERVER_BONUS_EXE) $(CLIENT_BONUS_EXE)

re: fclean all

.PHONY: all clean fclean re
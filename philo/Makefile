# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 19:56:18 by ullorent          #+#    #+#              #
#    Updated: 2022/04/20 17:01:07 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CSRC = 	src/philo.c 		\
		src/philo_start.c	\
		src/philo_utils.c	\
		src/philo_tasks.c	\
		src/philo_mem.c		\
		src/philo_time.c	\
		src/philo_parsers.c	\
		src/philo_forks.c
OSRC = $(CSRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
GCCCMD = gcc

all: $(NAME)

%.o: %.c
	@$(GCCCMD) $(CFLAGS) -c $^ -o $@

$(NAME): $(OSRC)
	@echo "\033[33mCompiling philo project...\033[0m"
	@$(GCCCMD) $(CFLAGS) $^ -o $(NAME)
	@echo "\033[92mphilo has been successfully compiled!\033[0m"
	
clean:
	@echo "\033[33mThe project is being cleaned...\033[0m"
	@rm -f $(OSRC)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[92mAll has been cleaned!\033[0m"

re: 
	@echo "\033[33mRecompiling philo project...\033[0m\n"
	@make fclean all

.PHONY: all clean fclean re
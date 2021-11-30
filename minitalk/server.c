/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:12:11 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/30 18:11:16 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void	signhandler(int signum)
{
	ft_printf("The signal %d was found, exiting...\n", signum);
	exit (1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	(void)argv;
	pid = getpid();
	if (argc != 1)
	{
		ft_printf("Please, don't specify any arguments: ./server\n");
		exit (0);
	}
	ft_printf("PID: %d\n", pid);
	sa.sa_handler = signhandler;
	sa.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause ();
	}
	return (0);
}

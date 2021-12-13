/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:12:18 by ullorent          #+#    #+#             */
/*   Updated: 2021/12/13 14:05:46 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void	signal_sender(char *text, int signum)
{
	int		ret;
	int		c;

	c = 0;
	while (text[c])
	{
		ret = -1;
		while (++ret < 8)
		{
			if (text[c] & 0x80 >> ret)
				kill(signum, SIGUSR2);
			else
				kill(signum, SIGUSR1);
			usleep(200);
		}
		c++;
	}
}

int	main(int argc, char **argv)
{
	int	pid_server;

	if (argc == 3)
	{
		pid_server = ft_atoi(argv[1]);
		signal_sender(argv[2], pid_server);
		ft_printf("Signal sent correctly\n");
	}
	else
		ft_printf("Use the command like this: ./client [PID] [String]\n");
	return (0);
}

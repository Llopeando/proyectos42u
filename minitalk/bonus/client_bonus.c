/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:04:07 by ullorent          #+#    #+#             */
/*   Updated: 2021/12/14 14:04:19 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

void	signal_sender(char *text, int signum)
{
	int		ret;
	int		c;
	int		len;

	c = 0;
	len = ft_strlen(text);
	while (text[c])
	{
		ret = -1;
		while (++ret < 8)
		{
			if (text[c] & 0x80 >> ret)
				kill(signum, SIGUSR2);
			else
				kill(signum, SIGUSR1);
			if (len <= 50)
				usleep(200);
			if (len > 50)
				usleep(1000);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:50:40 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/25 12:58:44 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	signhandler(int signum)
{
	printf("The signal %d was found, resuming...\n", signum);
	exit (1);
}

int	main(void)
{
	signal(SIGINT, signhandler);
	while (1)
	{
		printf("Someone is sleeping right now...\n");
		sleep (1);
	}
	return (0);
}

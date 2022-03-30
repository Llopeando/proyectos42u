/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio5_proccreate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:43:36 by ullorent          #+#    #+#             */
/*   Updated: 2022/03/30 16:00:46 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

int	ft_routine(void)
{
	int	i;

	i = 0;
	i++;
	return (i);
}

int	main(void)
{
	int			c;
	pthread_t	string[1000];

	c = 0;
	while (c < 4)
	{
		if (pthread_create(string + c, NULL, (void *)ft_routine, NULL) != 0)
		{
			printf("\nError creating a thread\n");
			exit (1);
		}
		printf("El thread %d ha comenzado\n", c);
		c++;
	}
	c = 0;
	while (c < 4)
	{
		if (pthread_join(string[c], NULL) != 0)
		{
			printf("\nError returning a thread value\n");
			exit (1);
		}
		sleep(3);
		printf("El thread %d ha finalizado su ejecución\n", c);
		c++;
	}
	return (0);
}

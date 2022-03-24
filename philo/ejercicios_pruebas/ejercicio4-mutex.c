/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio4-mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:11:38 by ullorent          #+#    #+#             */
/*   Updated: 2022/03/24 19:36:27 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

int	i = 0;
pthread_mutex_t	mutex;

void	*ft_prueba(void)
{
	int	count;
	
	for (count = 0; count < 10000; count++)
	{
		pthread_mutex_lock(&mutex);
		i++;
		pthread_mutex_unlock(&mutex);
	}
	return (0);
}

int	main(void)
{
	pthread_t	p1;
	pthread_t	p2;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&p1, NULL, (void *)ft_prueba, NULL);
	pthread_create(&p2, NULL, (void *)ft_prueba, NULL);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_mutex_destroy(&mutex);
	printf("Valor de i = %d\n", i);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:57:39 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/26 19:04:46 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_forks_leftfork(int n_philos, int philo_id)
{
	if (philo_id == 1)
		return (n_philos - 1);
	return (philo_id - 2);
}

int	ft_forks_takeforkleft(t_philos *philos, int left_fork, int boo)
{
	pthread_mutex_t	printf_mutex;

	philos->forks[left_fork].fork = boo;
	if (boo == 0)
	{
		pthread_mutex_lock(&printf_mutex);
		printf("%d %d has taken a fork\n", ft_gettime()
			- philos->time, philos->philo_id);
		pthread_mutex_unlock(&printf_mutex);
	}
	return (1);
}

int	ft_forks_takeforkright(t_philos *philos, int right_fork, int boo)
{
	pthread_mutex_t	printf_mutex;

	if (philos->forks[right_fork].fork != boo)
	{
		philos->forks[right_fork].fork = boo;
		if (boo == 0)
		{
			pthread_mutex_lock(&printf_mutex);
			printf("%d %d has taken a fork\n", ft_gettime()
				- philos->time, philos->philo_id);
			pthread_mutex_unlock(&printf_mutex);
		}
		return (1);
	}
	return (0);
}

int	ft_forks_handler(t_philos *philos, int left_fork, int boo)
{
	int		right_fork;
	int		forkboo1;
	int		forkboo2;

	forkboo1 = 0;
	forkboo2 = 0;
	right_fork = philos->philo_id - 1;
	if (forkboo1 == 0 || forkboo2 == 0)
	{
		pthread_mutex_lock(&philos->forks[left_fork].mutex);
		if (philos->forks[left_fork].fork != boo)
		{
			forkboo1 = ft_forks_takeforkleft(philos, left_fork, boo);
			pthread_mutex_unlock(&philos->forks[left_fork].mutex);
		}
		if (philos->n_philos != 1)
		{
			pthread_mutex_lock(&philos->forks[right_fork].mutex);
			forkboo2 = ft_forks_takeforkright(philos, right_fork, boo);
			pthread_mutex_unlock(&philos->forks[right_fork].mutex);
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:57:39 by ullorent          #+#    #+#             */
/*   Updated: 2022/05/02 16:22:13 by ullorent         ###   ########.fr       */
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
	philos->forks[left_fork].fork = boo;
	pthread_mutex_unlock(&philos->forks[left_fork].mutex);
	if (boo == 0)
	{
		printf("%ld %d has taken a fork\n",
			ft_gettime(philos, 1), philos->philo_id);
	}
	return (0);
}

int	ft_forks_takeforkright(t_philos *philos, int boo)
{
	int	right_fork;

	if (philos->philo_id == 1)
		right_fork = philos->n_philos - 1;
	else
		right_fork = philos->philo_id - 2;
	if (philos->forks[right_fork].fork != boo)
	{
		pthread_mutex_lock(&philos->forks[right_fork].mutex);
		philos->forks[right_fork].fork = boo;
		if (boo == 0)
		{
			printf("%ld %d has taken a fork\n",
				ft_gettime(philos, 1), philos->philo_id);
		}
		pthread_mutex_unlock(&philos->forks[right_fork].mutex);
		return (1);
	}
	return (0);
}

int	ft_forks_handler(t_philos *philos, int forkboo, int boo)
{
	//printf("boo = %d\n", boo);
	//printf("philos->philo_id - 1 = %d\n", philos->philo_id - 1);
	//printf("forkboo = %d\n", forkboo);
	printf("philos->forks[philos->philo_id - 1].fork = %d\n", philos->forks[philos->philo_id - 1].fork);
	// if (philos->forks[philos->philo_id - 1].fork != boo)
	// 	exit (0);
	while (forkboo == 0)
	{
		pthread_mutex_lock(&philos->forks[philos->philo_id - 1].mutex);
		if (philos->forks[philos->philo_id - 1].fork != boo)
		{
			ft_forks_takeforkleft(philos, philos->philo_id - 1, boo);
			if (boo == 0)
			{
				printf("%ld %d has taken a fork\n",
					ft_gettime(philos, 1), philos->philo_id);
			}
			if (philos->n_philos != 1)
			{
				ft_forks_takeforkright(philos, boo);
				forkboo = 1;
			}
		}
		pthread_mutex_unlock(&philos->forks[philos->philo_id - 1].mutex);
		if (ft_dying_check(philos))
			return (1);
	}
	return (0);
}

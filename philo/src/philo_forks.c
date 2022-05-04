/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:57:39 by ullorent          #+#    #+#             */
/*   Updated: 2022/05/04 14:00:05 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_forks_rightforkid(t_philos *philos)
{
	int	right_fork;

	if (philos->philo_id == 1)
	{
		right_fork = philos->core->n_philos - 1;
		return (right_fork);
	}
	else
	{
		right_fork = philos->philo_id - 2;
		return (right_fork);
	}
}

int	ft_forks_takeforkleft(t_philos *philos, int boo)
{
	philos->forks[philos->philo_id - 1].fork = boo;
	pthread_mutex_unlock(&philos->forks[philos->philo_id - 1].mutex);
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

	right_fork = ft_forks_rightforkid(philos);
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
	while (forkboo == 0)
	{
		pthread_mutex_lock(&philos->forks[philos->philo_id - 1].mutex);
		if (philos->forks[philos->philo_id - 1].fork != boo)
		{
			ft_forks_takeforkleft(philos, boo);
			if (philos->core->n_philos != 1)
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

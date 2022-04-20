/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:57:39 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/20 16:52:36 by ullorent         ###   ########.fr       */
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
	philos->fork[left_fork] = boo;
	//printf("entro aquí\n");
	if (boo == 0)
		printf("%d %d has taken a fork\n", ft_gettime()
			- philos->time, philos->philo_id);
	return (1);
}

int	ft_forks_takeforkright(t_philos *philos, int right_fork, int boo)
{
	//printf("entro aquí\n");
	if (philos->fork[right_fork] != boo)
	{
		philos->fork[right_fork] = boo;
		if (boo == 0)
			printf("%d %d has taken a fork\n", ft_gettime()
				- philos->time, philos->philo_id);
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
	while (forkboo1 == 0 || forkboo2 == 0)
	{
		pthread_mutex_lock(&philos->mutex[left_fork]);
		if (philos->n_philos != 1)
			pthread_mutex_lock(&philos->mutex[right_fork]);
		if (philos->fork[left_fork] != boo)
			forkboo1 = ft_forks_takeforkleft(philos, left_fork, boo);
		pthread_mutex_unlock(&philos->mutex[left_fork]);
		if (philos->n_philos != 1)
		{
			forkboo2 = ft_forks_takeforkright(philos, right_fork, boo);
			pthread_mutex_unlock(&philos->mutex[right_fork]);
		}
	}
	return (0);
}

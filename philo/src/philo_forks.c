/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:57:39 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/19 19:18:44 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_forks_leftfork(int n_philos, int philo_id)
{
	if (philo_id == 1)
		return (n_philos - 1);
	else
		return (n_philos - 2);
}

int	ft_forks_handler(t_philos *philos, int left_fork, int boo)
{
	t_forks	*forks;
	int		right_fork;
	int		forkboo1;
	int		forkboo2;

	forkboo1 = 0;
	forkboo2 = 0;
	boo++;
	forks = *philos->forks;
	right_fork = philos->philo_id - 1;
	while (forkboo1 == 0 || forkboo2 == 0)
	{
		pthread_mutex_lock(&forks[left_fork].mutex);
		if (philos->n_philos != 1)
			pthread_mutex_lock(&forks[right_fork].mutex);
		pthread_mutex_unlock(&forks[left_fork].mutex);
	}
	return (0);
}

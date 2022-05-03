/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tasks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:52:02 by ullorent          #+#    #+#             */
/*   Updated: 2022/05/03 15:45:50 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_eat(t_philos *philos)
{
	if (ft_forks_handler(philos, 0, 0))
		return (1);
	printf("%ld %d is eating\n",
		ft_gettime(philos, 1), philos->philo_id);
	philos->time = ft_gettime(philos, 0);
	if (ft_my_usleep(philos, philos->t_toeat))
		return (1);
	ft_forks_handler(philos, 0, 1);
	return (0);
}

int	ft_think(t_philos *philos)
{
	if (philos->has_eated)
		printf("%ld %d is thinking\n",
			ft_gettime(philos, 1), philos->philo_id);
	if (philos->n_philos % 2 != 0)
	{
		if (ft_my_usleep(philos, philos->t_toeat * 2 - philos->t_tosleep))
			return (1);
	}
	else
	{
		if (ft_my_usleep(philos, 0))
			return (1);
	}
	return (0);
}

int	ft_sleep(t_philos *philos)
{
	if (philos->has_eated)
		printf("%ld %d is sleeping\n",
			ft_gettime(philos, 1), philos->philo_id);
	if (ft_my_usleep(philos, philos->t_tosleep))
		return (1);
	return (0);
}

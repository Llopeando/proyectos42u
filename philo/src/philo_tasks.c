/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tasks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:52:02 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/27 18:41:37 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_eat(t_philos *philos)
{
	int	left_fork;

	left_fork = ft_forks_leftfork(philos->n_philos, philos->philo_id);
	if (ft_forks_handler(philos, left_fork, 0))
		return (1);
	philos->time= ft_gettime(philos, 0);
	//printf("philos->t_toeat = %d\n", philos->t_toeat);
	if (!philos->die->die)
		printf("%ld %d is \033[0;32meating\n\033[0m", ft_gettime(philos, 1), philos->philo_id);
	if (ft_my_usleep(philos, philos->t_toeat))
		return (1);
	ft_forks_handler(philos, left_fork, 1);
	return (0);
}

int	ft_think(t_philos *philos)
{
	if (!philos->die->die)
		printf("%ld %d is \033[0;36mthinking\n\033[0m", ft_gettime(philos, 1), philos->philo_id);
	if (ft_my_usleep(philos, philos->t_tosleep))
		return (1);
	return (0);
}

int	ft_sleep(t_philos *philos)
{
	if (!philos->die->die)
		printf("%ld %d is \033[0;33msleeping\n\033[0m", ft_gettime(philos, 1), philos->philo_id);
	if (ft_my_usleep(philos, philos->t_tosleep))
		return (1);
	return (0);
}

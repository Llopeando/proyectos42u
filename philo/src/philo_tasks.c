/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tasks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:52:02 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/12 17:04:53 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_eat(t_philos *philos)
{
	printf("%d %d is eating\n", ft_gettime(philos), philos->philo_id);
	ft_my_usleep(philos, philos->t_toeat);
}

void	ft_think(t_philos *philos)
{
	printf("%d %d is thinking\n", ft_gettime(philos), philos->philo_id);
	ft_my_usleep(philos, philos->t_todie - philos->t_tosleep - philos->t_toeat);
}

void	ft_sleep(t_philos *philos)
{
	printf("%d %d is sleeping\n", ft_gettime(philos), philos->philo_id);
	ft_my_usleep(philos, philos->t_tosleep);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tasks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:52:02 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/08 12:31:53 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_eat(t_philos *philos)
{
	printf("%d %d is eating\n", philos->t_toeat, philos->philo_id);
	usleep(philos->t_toeat);
}

void	ft_think(t_philos *philos)
{
	printf("%d %d is thinking\n", philos->t_toeat, philos->philo_id);
	usleep(philos->t_toeat);
}

void	ft_sleep(t_philos *philos)
{
	printf("%d %d is sleeping\n", philos->t_tosleep, philos->philo_id);
	usleep(philos->t_tosleep);
}

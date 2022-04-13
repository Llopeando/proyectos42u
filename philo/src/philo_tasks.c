/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tasks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:52:02 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/13 19:16:25 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_eat(t_philos *philos)
{
	if (philos->time == ft_gettime(philos))
	{
		printf("%d %d \033[0;32meating\n\033[0m", philos->time
			- ft_gettime(philos), philos->philo_id);
		ft_my_usleep(philos, philos->t_toeat);
		return ;
	}
	printf("%d %d is \033[0;32meating\n\033[0m",
		ft_gettime(philos), philos->philo_id);
	ft_my_usleep(philos, philos->t_toeat);
}

void	ft_think(t_philos *philos)
{
	if (philos->time == ft_gettime(philos))
		printf("%d %d is \033[0;36mthinking\n\033[0m", philos->time
			- ft_gettime(philos), philos->philo_id);
	printf("%d %d is \033[0;36mthinking\n\033[0m",
		ft_gettime(philos), philos->philo_id);
}

void	ft_sleep(t_philos *philos)
{
	if (philos->time == ft_gettime(philos))
		printf("%d %d is \033[0;33msleeping\n\033[0m", philos->time
			- ft_gettime(philos), philos->philo_id);
	printf("%d %d is \033[0;33msleeping\n\033[0m",
		ft_gettime(philos), philos->philo_id);
	ft_my_usleep(philos, philos->t_tosleep);
}

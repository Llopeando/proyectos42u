/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:11:19 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/15 13:45:26 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_process(void *philos)
{
	t_philos	temp;
	int			i;

	i = 0;
	temp = *(t_philos *)philos;
	if (pthread_mutex_init(&temp.has_died, NULL) != 0)
		return (0);
	while (!ft_gettime())
		usleep(1);
	pthread_mutex_lock(&temp.has_died);
	while (1)
	{
		pthread_mutex_unlock(&temp.has_died);
		// if (ft_death_check(temp))
		// 	break ;
		ft_eat(philos);
		// if (ft_death_check(temp))
		// 	break ;
		ft_sleep(philos);
		// if (ft_death_check(temp))
		// 	break ;
		ft_think(philos);
		pthread_mutex_lock(&temp.has_died);
		i++;
	}
	pthread_mutex_unlock(&temp.has_died);
	//free (&temp);
	return (0);
}

// int	ft_philo_tasks(t_philo *philo, int philo_id, int group)
// {
// 	/* aquí van las tareas que hay ahora en process pero basandome en los grupos */
// }

// int	ft_philo_groups()
// {
// 	/* aquí hay que hacer una función para darle un grupo a los filosofos impares y pares */
// }

int	ft_philo_creator(t_core *core)
{
	int	c;

	c = 0;
	core->thread = malloc(sizeof(pthread_t) * core->n_philos);
	core->philos = malloc(sizeof(t_philos) * core->n_philos);
	core->forks = malloc(sizeof(t_forks) * core->n_philos);
	if (!core->thread || !core->philos || !core->forks)
		return (1);
	while (c < core->n_philos)
	{
		ft_philo_philosparser(core, c);
		if (pthread_create(&core->thread[c], NULL,
				ft_process, &core->philos[c]) != 0)
			return (1);
		if (pthread_mutex_init(&core->forks[c].forks, NULL) != 0)
			return (1);
		c++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:11:19 by ullorent          #+#    #+#             */
/*   Updated: 2022/05/04 14:05:42 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_process(void *philos)
{
	t_philos	temp;

	temp = *(t_philos *)philos;
	temp.has_eated = 0;
	pthread_mutex_unlock(temp.mutex);
	while (!temp.core->starttime.tv_sec && !temp.core->starttime.tv_usec)
		usleep(100);
	temp.time = ft_gettime(&temp, 0);
	temp.start_time = temp.time;
	temp.group = ft_philo_groupsparser(&temp);
	ft_philo_tasks(&temp);
	return (NULL);
}

void	ft_philo_tasks(t_philos *philos)
{
	while (!ft_dying_check(philos))
	{
		if (philos->group == 2)
		{
			philos->group = 3;
			if (ft_sleep(philos))
				break ;
		}
		if (philos->group == 3)
		{
			philos->group = 1;
			if (ft_think(philos))
				break ;
		}
		if (philos->group == 1)
		{
			philos->group = 2;
			if (ft_eat(philos))
				break ;
			philos->has_eated++;
			if (philos->core->num_aphiloeats
				&& philos->has_eated == philos->core->num_aphiloeats)
				break ;
		}
	}
}

int	ft_philo_creator(t_core *core, t_forks **forks)
{
	int			c;
	t_philos	philos;

	c = 0;
	philos.mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philos.mutex, NULL);
	while (c < core->n_philos)
	{
		pthread_mutex_lock(philos.mutex);
		ft_philo_philosparser(&philos, forks, core, c);
		if (pthread_create(&core->thread[c], NULL,
				&ft_process, &philos) != 0)
			return (1);
		c++;
	}
	gettimeofday(&core->starttime, NULL);
	if (ft_philo_join(core))
		return (ft_error_msg(6));
	pthread_mutex_destroy(philos.mutex);
	free(philos.mutex);
	return (0);
}

int	ft_philo_mainstarter(t_core *core, t_forks **forks)
{
	int		c;

	c = 0;
	core->thread = (pthread_t *)malloc(sizeof(pthread_t) * core->n_philos);
	core->has_prob_died = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	*forks = (t_forks *)malloc(sizeof(t_forks) * core->n_philos);
	if (!core->thread || !core->has_prob_died || !forks)
		return (1);
	pthread_mutex_init(core->has_prob_died, NULL);
	c = 0;
	while (c < core->n_philos)
	{
		(*forks + c)->fork = 1;
		if (pthread_mutex_init(&(*forks + c)->mutex, NULL) != 0)
			return (1);
		c++;
	}
	return (0);
}

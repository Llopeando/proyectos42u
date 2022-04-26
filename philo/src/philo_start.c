/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:11:19 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/26 19:03:41 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_process(void *philos)
{
	t_philos	temp;
	int			i;
	int			group;

	i = 0;
	temp = *(t_philos *)philos;
	temp.has_eated = 0;
	if (pthread_mutex_init(&temp.has_died, NULL) != 0)
		return (0);
	group = ft_philo_groupsparser(temp.n_philos, temp.philo_id);
	while (!ft_gettime())
		usleep(1);
	//printf("\ngroup = %d\n", group);
	ft_philo_tasks(philos, group);
	return (0);
}

void	ft_philo_tasks(t_philos *philos, int group)
{
	pthread_mutex_lock(&philos->has_died);
	while (1)
	{
		pthread_mutex_unlock(&philos->has_died);
		if (group == 2)
		{
			group = 3;
			ft_sleep(philos);
		}
		if (group == 1)
		{
			group = 3;
			ft_think(philos);
		}
		if (group == 3)
		{
			group = 2;
			ft_eat(philos);
			philos->has_eated++;
		}
		pthread_mutex_lock(&philos->has_died);
	}
	pthread_mutex_unlock(&philos->has_died);
}

int	ft_philo_creator(t_core *core)
{
	int		c;

	c = 0;
	while (c < core->n_philos)
	{
		ft_philo_philosparser(core, c);
		core->philos[c].forks = malloc(sizeof(t_forks) * core->n_philos);
		if (pthread_create(&core->thread[c], NULL,
				ft_process, &core->philos[c]) != 0)
			return (1);
		c++;
	}
	return (0);
}

int	ft_philo_mainstarter(t_core *core, t_forks **forks)
{
	int		c;

	c = 0;
	core->thread = malloc(sizeof(pthread_t) * core->n_philos);
	core->philos = malloc(sizeof(t_philos) * core->n_philos);
	*forks = (t_forks *)malloc(sizeof(t_forks) * core->n_philos);
	if (!core->thread || !core->philos || !forks)
		return (1);
	c = 0;
	while (c < core->n_philos)
	{
		(*forks + c)->fork = 1;
		if (pthread_mutex_init(&(*forks)->mutex, NULL) != 0)
			return (1);
		c++;
	}
	return (0);
}

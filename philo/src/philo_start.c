/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:11:19 by ullorent          #+#    #+#             */
/*   Updated: 2022/05/02 16:22:03 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_process(void *philos)
{
	t_philos	temp;
	int			i;
	//int			group;

	i = 0;
	temp = *(t_philos *)philos;
	temp.has_eated = 0;
	while (!temp.wait->wait)
		usleep(10);
	temp.time = ft_gettime(&temp, 0);
	temp.start_time = temp.time;
	temp.group = ft_philo_groupsparser(&temp);
	ft_philo_tasks(&temp);
	return (NULL);
}

void	ft_philo_tasks(t_philos *philos)
{
	//printf("philo_id = %d\n", philos->philo_id);
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
			if (philos->num_aphiloeats
				&& philos->has_eated == philos->num_aphiloeats)
				break ;
		}
	}
}

int	ft_philo_creator(t_core *core)
{
	int		c;
	t_die	die;
	t_wait	wait;

	c = 0;
	wait.wait = 0;
	while (c < core->n_philos)
	{
		ft_philo_philosparser(core, &die, &wait, c);
		core->philos[c].philo_id = c + 1;
		core->philos->start_time = ft_gettime(core->philos, 0);
		core->philos[c].forks = malloc(sizeof(t_forks) * core->n_philos);
		if (pthread_create(&core->thread[c], NULL,
				ft_process, &core->philos[c]) != 0)
			return (1);
		c++;
	}
	wait.wait = 1;
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
	c = -1;
	while (++c < core->n_philos)
	{
		(*forks + c)->fork = 1;
		if (pthread_mutex_init(&(*forks + c)->mutex, NULL) != 0)
			return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:11:19 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/27 18:41:10 by ullorent         ###   ########.fr       */
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
	while (!temp.wait->wait)
		usleep(10);
	temp.time = ft_gettime(&temp, 0);
	temp.start_time = temp.time;
	//printf("temp.start_time = %ld\n", temp.start_time);
	//printf("temp.gettime = %ld\n", ft_gettime(&temp, 1));
	//printf("\n");
	group = ft_philo_groupsparser(temp.n_philos, temp.philo_id);
	ft_philo_tasks(&temp, group);
	return (NULL);
}

void	ft_philo_tasks(t_philos *philos, int group)
{
	while (!philos->die->die)
	{
		if (group == 2)
		{
			group = 1;
			if (ft_sleep(philos))
				break ;
		}
		if (group == 1)
		{
			group = 3;
			if (ft_think(philos))
				break ;
		}
		if (group == 3)
		{
			group = 2;
			//printf("salgo de aqui\n");
			if (ft_eat(philos))
				break ;
			// philos->has_eated++;
			//printf("philos->has_eated = %d\n", philos->has_eated);
			//printf("philos->num_aphiloeats = %d\n", philos->num_aphiloeats);
			// if (philos->num_aphiloeats != 0 && philos->has_eated >= philos->num_aphiloeats)
			// 	break ;
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
	pthread_mutex_init(&die.mutex, NULL);
	while (c < core->n_philos)
	{
		ft_philo_philosparser(core, &die, &wait, c);
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

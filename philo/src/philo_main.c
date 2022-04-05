/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:11:19 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/05 15:21:42 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_process(void *philos)
{
	t_philos	*temp;

	temp = (t_philos *)philos;
	printf("philo_id = %d\n", temp->philo_id);
	if (temp->philo_id >= 5)
		ft_tasks(temp);
	return (0);
}

void	ft_tasks(t_philos *philos)
{
	ft_sleep(philos);
}

int	ft_groups(char **argv, t_core *core, t_philos *philos)
{
	core->n_philos = ft_atoi(argv[1]);
	core->t_todie = ft_atoi(argv[2]);
	core->t_toeat = ft_atoi(argv[3]);
	core->t_tosleep = ft_atoi(argv[4]);
	philos->t_tosleep = ft_atoi(argv[4]);
	if (argv[5])
		core->num_aphiloeats = ft_atoi(argv[5]);
	if (!argv[5] || argv[5] == 0)
		core->num_aphiloeats = 1;
	if (core->n_philos <= 0 || core->t_todie <= 0
		|| core->t_toeat <= 0 || core->t_tosleep <= 0)
		return (1);
	printf("number_of_philosophers: %d\n", core->n_philos);
	printf("time_to_die: %d\n", core->t_todie);
	printf("time_to_eat: %d\n", core->t_toeat);
	printf("time_to_sleep: %d\n", core->t_tosleep);
	printf("time_to_sleep: %d\n", philos->t_tosleep);
	printf("numbers_of_times_each_philosopher_must_eat: %d\n\n",
		core->num_aphiloeats);
	return (0);
}

int	ft_philo_creator(t_core *core, char **argv, t_philos *philos)
{
	int	c;

	c = 0;
	if (ft_groups(argv, core, philos))
		return (1);
	core->thread = malloc(sizeof(pthread_t) * core->n_philos);
	core->philos = malloc(sizeof(t_philos) * core->n_philos);
	while (c < core->n_philos)
	{
		core->philos[c].philo_id = c + 1;
		if (pthread_create(&core->thread[c], NULL,
				ft_process, &core->philos[c]) != 0)
			return (1);
		c++;
	}
	c = 0;
	while (c < core->n_philos)
	{
		if (pthread_join(core->thread[c], NULL) != 0)
			return (1);
		c++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:11:19 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/04 16:16:41 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_return(void)
{
	// if (core->n_philos % )
	return (0);
}

int	ft_groups(char **argv, t_core *core)
{
	core->n_philos = ft_atoi(argv[1]);
	core->t_todie = ft_atoi(argv[2]);
	core->t_toeat = ft_atoi(argv[3]);
	core->t_tosleep = ft_atoi(argv[4]);
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
	printf("numbers_of_times_each_philosopher_must_eat: %d\n\n",
		core->num_aphiloeats);
	return (0);
}

int	ft_philo_creator(t_core *core, char **argv)
{
	int	c;

	c = 0;
	if (ft_groups(argv, core))
		return (1);
	core->philos = malloc(sizeof(pthread_t) * core->n_philos);
	while (c < core->n_philos)
	{
		if (pthread_create(core->philos + c, NULL,
				(void *)ft_return, NULL) != 0)
			return (1);
		core->philo_id = c + 1;
		printf("El filósofo %d se ha creado\n", core->philo_id);
		c++;
	}
	printf("\n");
	c = 0;
	core->philo_id = 0;
	while (c < core->n_philos)
	{
		if (pthread_join(core->philos[c], NULL) != 0)
			return (1);
		//sleep(1);
		core->philo_id = c + 1;
		printf("El filósofo %d ha finalizado\n", core->philo_id);
		c++;
	}
	return (0);
}

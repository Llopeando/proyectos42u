/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:42:16 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/25 12:48:58 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_philo_coreparser(t_core *core, char **argv)
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

void	ft_philo_philosparser(t_core *core, int c)
{
	core->philos[c].n_philos = core->n_philos;
	core->philos[c].t_tosleep = core->t_tosleep;
	core->philos[c].t_todie = core->t_todie;
	core->philos[c].t_toeat = core->t_toeat;
	core->philos[c].num_aphiloeats = core->num_aphiloeats;
	core->philos[c].philo_id = c + 1;
	core->philos[c].time = ft_gettime();
}

int	ft_philo_groupsparser(int n_philos, int philo_id)
{
	if (n_philos == philo_id || n_philos % 2 != 0)
		return (2);
	if (philo_id % 2 == 0)
		return (1);
	if (philo_id % 2 != 0)
		return (3);
	return (0);
}

// int	ft_philo_forksparser(t_forks *forks, int c)
// {
// 	return (0);
// }

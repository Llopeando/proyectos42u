/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:42:16 by ullorent          #+#    #+#             */
/*   Updated: 2022/05/04 14:14:12 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_philo_coreparser(t_core *core, char **argv)
{
	core->n_philos = ft_atoi(argv[1]);
	core->t_todie = ft_atoi(argv[2]);
	core->t_toeat = ft_atoi(argv[3]);
	core->t_tosleep = ft_atoi(argv[4]);
	core->starttime.tv_sec = 0;
	core->starttime.tv_usec = 0;
	if (argv[5])
		core->num_aphiloeats = ft_atoi(argv[5]);
	if (!argv[5] || argv[5] == 0)
		core->num_aphiloeats = 0;
	if (core->n_philos <= 0 || core->t_todie <= 0
		|| core->t_toeat <= 0 || core->t_tosleep <= 0)
		return (1);
	core->has_died = 0;
	return (0);
}

void	ft_philo_philosparser(t_philos *philos, t_forks **forks,
							t_core *core, int c)
{
	philos->core = core;
	philos->forks = *forks;
	philos->philo_id = c + 1;
}

int	ft_philo_groupsparser(t_philos *philos)
{
	int	group;

	group = 0;
	if (philos->core->n_philos == philos->philo_id
		&& philos->core->n_philos % 2 != 0)
		group = 3;
	else if (philos->philo_id % 2 == 0)
		group = 2;
	else if (philos->philo_id % 2 != 0)
		group = 1;
	return (group);
}

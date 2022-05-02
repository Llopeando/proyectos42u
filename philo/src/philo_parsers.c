/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:42:16 by ullorent          #+#    #+#             */
/*   Updated: 2022/05/02 15:55:58 by ullorent         ###   ########.fr       */
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
		core->num_aphiloeats = 0;
	if (core->n_philos <= 0 || core->t_todie <= 0
		|| core->t_toeat <= 0 || core->t_tosleep <= 0)
		return (1);
	return (0);
}

void	ft_philo_philosparser(t_core *core, t_die *die, t_wait *wait, int c)
{
	core->philos[c].n_philos = core->n_philos;
	core->philos[c].t_tosleep = core->t_tosleep;
	core->philos[c].t_todie = core->t_todie;
	core->philos[c].t_toeat = core->t_toeat;
	core->philos[c].num_aphiloeats = core->num_aphiloeats;
	core->philos[c].has_died_boo = core->has_died;
	core->philos[c].has_prob_died = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	core->philos[c].die = die;
	core->philos[c].wait = wait;
	//core->philos[c].philo_id = c + 1;
	pthread_mutex_init(core->philos->has_prob_died, NULL);
}

int	ft_philo_groupsparser(t_philos *philos)
{
	int	group;

	group = 0;
	if (philos->n_philos == philos->philo_id && philos->n_philos % 2 != 0)
		group = 3;
	else if (philos->philo_id % 2 != 0)
		group = 1;
	else if (philos->philo_id % 2 == 0)
		group = 2;
	return (group);
}

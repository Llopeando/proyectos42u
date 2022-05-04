/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:22:32 by ullorent          #+#    #+#             */
/*   Updated: 2022/05/04 13:45:11 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_freemem(t_core *core, t_forks *forks)
{
	int	c;

	c = 0;
	while (c < core->n_philos)
	{
		pthread_mutex_destroy(&forks[c].mutex);
		c++;
	}
	free(forks);
	free(core->thread);
	pthread_mutex_destroy(core->has_prob_died);
	free(core->has_prob_died);
}

int	ft_philo_join(t_core *core)
{
	int			c;

	c = 0;
	while (c < core->n_philos)
	{
		if (pthread_join(core->thread[c], NULL) != 0)
			return (1);
		c++;
	}
	return (0);
}

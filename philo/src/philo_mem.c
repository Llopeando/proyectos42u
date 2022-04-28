/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:22:32 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/28 18:37:09 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_mutex_init(t_philos *philos)
{
	if (pthread_mutex_init(&philos->has_died, NULL) != 0)
		return (1);
	return (0);
}

int	ft_philo_join(t_core *core)
{
	int	c;

	c = 0;
	while (c < core->n_philos)
	{
		if (pthread_join(core->thread[c], NULL) != 0)
			return (1);
		c++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:22:32 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/12 14:17:29 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_mutex_init(t_philos *philos)
{
	
	if (pthread_mutex_init(&philos->has_died, NULL) != 0)
		return (1);
	return (0);
}

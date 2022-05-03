/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:25:51 by ullorent          #+#    #+#             */
/*   Updated: 2022/05/03 17:13:43 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long int	ft_gettime(t_philos *philos, int boo)
{
	struct timeval	time;
	long int		timenow;

	gettimeofday(&time, NULL);
	timenow = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (boo == 1)
		return (timenow - philos->start_time);
	return (timenow);
}

long int	ft_time_to_ms(struct timeval start_time)
{
	return (start_time.tv_sec * 1000 + start_time.tv_usec / 1000);
}

int	ft_death_check(t_philos *philos)
{
	struct timeval	time;
	long int		time_now;

	gettimeofday(&time, NULL);
	time_now = ft_time_to_ms(time) - philos->time;
	if (time_now > philos->t_todie)
		return (1);
	return (0);
}

int	ft_dying_check(t_philos *philos)
{
	pthread_mutex_lock(philos->has_prob_died);
	if (philos->die->die)
	{
		pthread_mutex_unlock(philos->has_prob_died);
		return (1);
	}
	if (ft_death_check(philos))
	{
		philos->die->die = 1;
		pthread_mutex_unlock(philos->has_prob_died);
		printf("%ld %d died\n", ft_gettime(philos, 1), philos->philo_id);
		return (1);
	}
	pthread_mutex_unlock(philos->has_prob_died);
	return (0);
}

int	ft_my_usleep(t_philos *philo, int time)
{
	struct timeval	start;
	struct timeval	end;
	int				c;

	c = 0;
	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	while (ft_time_to_ms(end) - ft_time_to_ms(start) < time)
	{
		usleep(100);
		gettimeofday(&end, NULL);
		if (ft_time_to_ms(end) - ft_time_to_ms(start) - c > 10)
		{
			c += 10;
			if (ft_dying_check(philo))
				return (1);
		}
	}
	if (ft_dying_check(philo))
		return (1);
	return (0);
}

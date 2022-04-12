/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:25:51 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/12 14:51:25 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_gettime(t_philos *philo)
{
	struct timeval	time;
	long int		timenow;

	gettimeofday(&time, NULL);
	timenow = (time.tv_sec * 1000 + time.tv_usec / 1000)
		- (philo->start_time.tv_sec * 1000 + philo->start_time.tv_usec / 1000);
	return (timenow);
}

int	ft_time_to_ms(struct timeval start_time)
{
	return (start_time.tv_sec * 1000 + start_time.tv_usec / 1000);
}

int	ft_my_usleep(t_philos *philo, int time)
{
	struct timeval	start;
	struct timeval	end;
	int				c;

	c = 0;
	(void)philo;
	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	while ((end.tv_sec * 1000 + end.tv_usec / 1000)
		- (start.tv_sec * 1000 + start.tv_usec / 1000) < time)
	{
		usleep(5);
		gettimeofday(&end, NULL);
		if ((end.tv_sec * 1000 + end.tv_usec / 1000)
			- (start.tv_sec * 1000 + start.tv_usec) - c > 10)
		{
			c += 10;
			// if (ft_death_check(philo))
			// 	return (1);
		}
		c++;
	}
	// if (ft_death_check(philo))
	// 	return (1);
	return (0);
}

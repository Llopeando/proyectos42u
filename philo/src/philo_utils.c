/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:15:11 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/12 14:29:10 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *str)
{
	unsigned int		c;
	int					j;
	unsigned long int	lint;

	c = 0;
	j = 1;
	lint = 0;
	while ((str[c] == ' ') || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			j = -1;
		c++;
	}
	while (str[c] <= '9' && str[c] >= '0')
	{
		lint = (lint * 10) + (str[c] - '0');
		c++;
	}
	if (lint > 9223372036854775807 && j == -1)
		return (0);
	if (lint > 9223372036854775807 && j == 1)
		return (-1);
	return (lint * j);
}

void	ft_philo_dataparser(t_core *core, int c)
{
	core->philos[c].t_tosleep = core->t_tosleep;
	core->philos[c].t_todie = core->t_todie;
	core->philos[c].t_toeat = core->t_toeat;
	core->philos[c].num_aphiloeats = core->num_aphiloeats;
	core->forks[c].fork = 1;
}

int	ft_error_msg(int boo)
{
	if (boo == 1)
		printf("Error: There are too many or insufficient arguments\n");
	if (boo == 2)
		printf("Error: Check your arguments\n");
	if (boo == 3)
		printf("Error: An error ocurred with the threads\n");
	if (boo == 4)
		printf("Error: An error ocurred with the joins\n");
	return (1);
}

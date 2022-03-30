/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:03:17 by ullorent          #+#    #+#             */
/*   Updated: 2022/03/30 19:14:43 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_args_checker(char **argv)
{
	int	c;
	int	i;

	c = 1;
	while (argv[c] != NULL)
	{
		i = 0;
		if ((argv[c][i] < '0' || argv[c][i] > '9'))
			return (1);
		c++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_core		core;

	if (argc != 5 && argc != 6)
	{
		printf("Error: There are too many or insufficient arguments\n");
		return (1);
	}
	if (ft_args_checker(argv))
		return (1);
	ft_groups(argv, &core);
	if (core.n_philos > 0)
		ft_philo_creator(core.n_philos, &core);
	//free (core);
	return (0);
}

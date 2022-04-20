/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:03:17 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/20 12:43:05 by ullorent         ###   ########.fr       */
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
		return (ft_error_msg(1));
	if (ft_args_checker(argv))
		return (ft_error_msg(2));
	if (ft_philo_coreparser(&core, argv))
		return (ft_error_msg(3));
	if (ft_philo_mainstarter(&core))
		return (ft_error_msg(4));
	if (ft_philo_creator(&core))
		return (ft_error_msg(5));
	if (ft_philo_join(&core))
		return (ft_error_msg(6));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:03:17 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/01 14:23:11 by ullorent         ###   ########.fr       */
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

int	ft_error_msg(int boo)
{
	if (boo == 1)
		printf("Error: There are too many or insufficient arguments\n");
	if (boo == 2)
		printf("Error: An error ocurred with the threads\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_core		core;

	if (argc != 5 && argc != 6)
		return (ft_error_msg(1));
	if (ft_args_checker(argv))
		return (1);
	if (!ft_philo_creator(&core, argv))
		return (ft_error_msg(2));
	//free (core);
	return (0);
}

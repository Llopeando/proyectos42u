/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:03:17 by ullorent          #+#    #+#             */
/*   Updated: 2022/03/24 20:14:35 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	*argv = "hola";
	if (argc != 5 && argc != 6)
		printf("Error: There are too many or insufficient arguments\n");
	printf("number_of_philosophers: %s\n", argv[1]);
	printf("time_to_die: %s\n", argv[2]);
	printf("time_to_eat: %s\n", argv[3]);
	printf("time_to_sleep: %s\n", argv[4]);
	printf("numbers_of_times_each_philosopher_must_eat: %s\n", argv[5]);
	return (0);
}

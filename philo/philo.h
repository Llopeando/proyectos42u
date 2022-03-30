/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:05:26 by ullorent          #+#    #+#             */
/*   Updated: 2022/03/30 18:59:30 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_core
{
	pthread_t	*philos;
	int			n_philos;
	int			t_todie;
	int			t_toeat;
	int			t_tosleep;
	int			num_aphiloeats;
	int			philo_id;
}	t_core;

/* ----- utils ----- */
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

/* ----- main functions ----- */
int		ft_philo_creator(int p, t_core *core);
void	ft_groups(char **argv, t_core *core);

/* ----- errors checker ----- */
int		ft_args_checker(char **argv);

#endif
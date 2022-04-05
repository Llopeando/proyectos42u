/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:05:26 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/05 15:21:56 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philos
{
	int			n_philos;
	int			t_todie;
	int			t_toeat;
	int			t_tosleep;
	int			num_aphiloeats;
	int			philo_id;
}	t_philos;

typedef struct s_core
{
	pthread_t	*thread;
	t_philos	*philos;
	int			n_philos;
	int			t_todie;
	int			t_toeat;
	int			t_tosleep;
	int			num_aphiloeats;
}	t_core;

/* ----- utils ----- */
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

/* ----- main functions ----- */
int		ft_philo_creator(t_core *core, char **argv, t_philos *philos);
int		ft_groups(char **argv, t_core *core, t_philos *philos);

void	*ft_process(void *philos);
void	ft_tasks(t_philos *philos);

/* ----- tasks functions ----- */
void	ft_sleep(t_philos *philos);

/* ----- errors checker ----- */
int		ft_args_checker(char **argv);
int		ft_error_msg(int boo);

#endif
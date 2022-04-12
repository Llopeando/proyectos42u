/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:05:26 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/12 14:46:30 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_forks
{
	int				fork;
	pthread_mutex_t	forks;
}	t_forks;

typedef struct s_philos
{
	int				n_philos;
	int				t_todie;
	int				t_toeat;
	int				t_tosleep;
	int				num_aphiloeats;
	int				philo_id;
	int				wait;
	pthread_mutex_t	has_died;
	struct timeval	philo_time;
	struct timeval	start_time;
	t_forks			**forks;
}	t_philos;

typedef struct s_core
{
	pthread_t		*thread;
	t_philos		*philos;
	t_forks			*forks;
	int				n_philos;
	int				t_todie;
	int				t_toeat;
	int				t_tosleep;
	int				num_aphiloeats;
}	t_core;

/* ----- utils ----- */
void	ft_philo_dataparser(t_core *core, int c);
int		ft_mutex_init(t_philos *philos);
int		ft_atoi(const char *str);
int		ft_time_to_ms(struct timeval start_time);
int		ft_my_usleep(t_philos *philo, int time);

/* ----- main functions ----- */
int		ft_philo_creator(t_core *core, char **argv);
int		ft_philo_join(t_core *core);
int		ft_philo_groups(char **argv, t_core *core);

void	*ft_process(void *philos);

/* ----- tasks functions ----- */
void	ft_sleep(t_philos *philos);
void	ft_eat(t_philos *philos);
void	ft_think(t_philos *philos);

int		ft_gettime(t_philos *philo);

/* ----- errors checker ----- */
int		ft_args_checker(char **argv);
int		ft_error_msg(int boo);

#endif
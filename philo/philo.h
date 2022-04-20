/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:05:26 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/20 14:23:48 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>

// typedef struct s_forks
// {
// }	t_forks;

typedef struct s_philos
{
	pthread_mutex_t	has_died;
	struct timeval	start_time;
	//t_forks			**forks;
	int				*fork;
	pthread_mutex_t	*mutex;
	int				n_philos;
	int				t_todie;
	int				t_toeat;
	int				t_tosleep;
	int				num_aphiloeats;
	int				philo_id;
	int				time;
}	t_philos;

typedef struct s_core
{
	pthread_t		*thread;
	t_philos		*philos;
	int				n_philos;
	int				t_todie;
	int				t_toeat;
	int				t_tosleep;
	int				num_aphiloeats;
}	t_core;

/* ----- main functions ----- */
int		ft_philo_mainstarter(t_core *core);
int		ft_philo_creator(t_core *core);
int		ft_philo_join(t_core *core);

void	*ft_process(void *philos);
void	ft_philo_tasks(t_philos *philo, int group);

/* ----- data parsers ----- */
int		ft_philo_coreparser(t_core *core, char **argv);
void	ft_philo_philosparser(t_core *core, int c);
int		ft_philo_groupsparser(int n_philos, int philo_id);
//int		ft_philo_forksparser(t_forks *forks, int c);

/* ----- tasks functions ----- */
int		ft_eat(t_philos *philos);
void	ft_sleep(t_philos *philos);
void	ft_think(t_philos *philos);

/* ----- forks functions ----- */
int		ft_forks_leftfork(int n_philos, int philo_id);

int		ft_forks_handler(t_philos *philos, int left_fork, int boo);

/* ----- time calculation functions ----- */
int		ft_gettime(void);
int		ft_time_to_ms(struct timeval start_time);
int		ft_my_usleep(t_philos *philo, int time);

/* ----- utils ----- */
int		ft_mutex_init(t_philos *philos);
int		ft_atoi(const char *str);

/* ----- errors checker ----- */
int		ft_args_checker(char **argv);
int		ft_error_msg(int boo);

#endif
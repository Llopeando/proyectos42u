/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:05:26 by ullorent          #+#    #+#             */
/*   Updated: 2022/04/27 18:15:34 by ullorent         ###   ########.fr       */
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

typedef struct s_wait
{
	int				wait;
}	t_wait;

typedef struct s_die
{
	int				die;
	pthread_mutex_t	mutex;
}	t_die;

typedef struct s_forks
{
	int				fork;
	pthread_mutex_t	mutex;
}	t_forks;

typedef struct s_philos
{
	pthread_mutex_t	has_died;
	int				has_died_boo;
	long int		start_time;
	t_forks			*forks;
	t_die			*die;
	t_wait			*wait;
	int				n_philos;
	int				t_todie;
	int				t_toeat;
	int				t_tosleep;
	int				num_aphiloeats;
	int				philo_id;
	long int		time;
	int				has_eated;
}	t_philos;

typedef struct s_core
{
	pthread_t		*thread;
	t_philos		*philos;
	int				has_died_boo;
	int				n_philos;
	int				t_todie;
	int				t_toeat;
	int				t_tosleep;
	int				num_aphiloeats;
	int				has_died;
}	t_core;

/* ----- main functions ----- */
int			ft_philo_mainstarter(t_core *core, t_forks **forks);
int			ft_philo_creator(t_core *core);
int			ft_philo_join(t_core *core);

void		*ft_process(void *philos);
void		ft_philo_tasks(t_philos *philo, int group);

/* ----- data parsers ----- */
int			ft_philo_coreparser(t_core *core, char **argv);
void		ft_philo_philosparser(t_core *core, t_die *die,
				t_wait *wait, int c);
int			ft_philo_groupsparser(int n_philos, int philo_id);

/* ----- tasks functions ----- */
int			ft_eat(t_philos *philos);
int			ft_sleep(t_philos *philos);
int			ft_think(t_philos *philos);

/* ----- forks functions ----- */
int			ft_forks_handler(t_philos *philos, int left_fork, int boo);
int			ft_forks_leftfork(int n_philos, int philo_id);
int			ft_forks_takeforkleft(t_philos *philos, int left_fork, int boo);
int			ft_forks_takeforkright(t_philos *philos, int right_fork, int boo);

/* ----- time calculation functions ----- */
long int	ft_gettime(t_philos *philos, int boo);
long int	ft_time_to_ms(struct timeval start_time);
int			ft_my_usleep(t_philos *philo, int time);

/* ----- dying check functions ----- */
int			ft_dying_check(t_philos *philos);
int			ft_death_check(t_philos *philos);

/* ----- utils ----- */
int			ft_mutex_init(t_philos *philos);
int			ft_atoi(const char *str);

/* ----- errors checker ----- */
int			ft_args_checker(char **argv);
int			ft_error_msg(int boo);

#endif
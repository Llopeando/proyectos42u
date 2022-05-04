/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:05:26 by ullorent          #+#    #+#             */
/*   Updated: 2022/05/04 14:24:20 by ullorent         ###   ########.fr       */
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

typedef struct s_core
{
	pthread_t		*thread;
	pthread_mutex_t	*has_prob_died;
	t_die			*die;
	struct timeval	starttime;
	int				n_philos;
	int				t_todie;
	int				t_toeat;
	int				t_tosleep;
	int				num_aphiloeats;
	int				has_died;
}	t_core;

typedef struct s_philos
{
	t_forks			*forks;
	t_core			*core;
	pthread_mutex_t	*mutex;
	int				philo_id;
	int				group;
	int				has_eated;
	long int		start_time;
	long int		time;
}	t_philos;

/* ----- main functions ----- */
int			ft_philo_mainstarter(t_core *core, t_forks **forks);
int			ft_philo_creator(t_core *core, t_forks **forks);
int			ft_philo_join(t_core *core);

void		*ft_process(void *philos);
void		ft_philo_tasks(t_philos *philo );

/* ----- data parsers ----- */
int			ft_philo_coreparser(t_core *core, char **argv);
void		ft_philo_philosparser(t_philos *philos, t_forks **forks,
				t_core *core, int c);
int			ft_philo_groupsparser(t_philos *philos);

/* ----- tasks functions ----- */
int			ft_eat(t_philos *philos);
int			ft_sleep(t_philos *philos);
int			ft_think(t_philos *philos);

/* ----- forks functions ----- */
int			ft_forks_handler(t_philos *philos, int forkboo, int boo);
int			ft_forks_takeforkleft(t_philos *philos, int boo);
int			ft_forks_takeforkright(t_philos *philos, int boo);

int			ft_forks_rightforkid(t_philos *philos);

/* ----- time calculation functions ----- */
long int	ft_gettime(t_philos *philos, int boo);
long int	ft_time_to_ms(struct timeval start_time);
int			ft_my_usleep(t_philos *philo, int time);

/* ----- dying check functions ----- */
int			ft_dying_check(t_philos *philos);
int			ft_death_check(t_philos *philos);

/* ----- utils ----- */
int			ft_mutex_init(t_philos *philos);
void		ft_philo_freemem(t_core *core, t_forks *forks);
int			ft_atoi(const char *str);

/* ----- errors checker ----- */
int			ft_args_checker(char **argv);
int			ft_error_msg(int boo);

#endif
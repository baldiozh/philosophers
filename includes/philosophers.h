/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:10:17 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/21 21:59:24 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# define ERR_ARG		"\x1b[0;31mEnter number of philosophers, time to death, time to eat, time to sleep.\n"
# define ERR_MEMORY		"\x1b[0;31mMemory allocation error.\n"
# define SLEEP 4
# define THINK 5
# define EAT 6


typedef struct s_data
{
	int				philo_num;
	int				prog_st;
	int				tdeath;
	int				teat;
	int				tsleep;
	int				meals; //if no arg for this then -1
	pthread_mutex_t	*forks;
	pthread_mutex_t	*speak_mutex;
	pthread_mutex_t	*death_mutex;
	pthread_t		philos[200];
	int				isdead;
	struct s_philarg		*philo;
}			t_data;

typedef struct s_philarg
{
	int				num;
	time_t			start_meal;
	int				left_fork;
	int				right_fork;
	t_data		*data;

}			t_philarg;


/* init */
void	init(int argc, char **argv, t_data *data);
void	init_data(int argc, char **argv, t_data *data);
void	init_philarg(t_data *data);

/* utils */
int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	message(int action);
void	error(char *str);
void* hello(void *args);

/* time */
long	timeofday(void);
void	ft_usleep(int ms);

/* actions */
void	sleeping(t_data *data);
void	thinking(t_data *data);
void	eating(t_data *data);

/* let's go */
void	*philo_life(void *data);
void	process(t_data *data);

#endif


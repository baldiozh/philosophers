/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:10:17 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/16 20:02:03 by gmckinle         ###   ########.fr       */
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

# define ERR_ARG	"\x1b[0;31mNumber of philosophers, tdeath, teat, tsleep.\n"
# define ERR_MEMORY	"\x1b[0;31mMemory allocation error.\n"
# define SLEEP 		"is sleeping"
# define THINK		"is thinking"
# define TAKE_FORK	"has taken a fork"
# define EAT		"is eating"
# define DIED		"died\n"
# define TAKE 9
# define PUT 10

typedef struct s_data
{
	int					philo_num;
	int					tdeath;
	int					teat;
	int					tsleep;
	int					meals_num;
	long long int		prog_start;
	pthread_mutex_t		*forks;
	pthread_mutex_t		speak_mutex;
	pthread_t			philo_tr[200];
	int					stop;
	struct s_philarg	*philo;
}			t_data;

typedef struct s_philarg
{
	int						id;
	int						meals;
	long long int			last_meal;
	int						left_fork;
	int						right_fork;
	pthread_mutex_t			*death_mutex;
	t_data					*data;

}			t_philarg;

/* init */
void	init(int argc, char **argv, t_data *data);
void	init_data(int argc, char **argv, t_data *data);
void	init_philarg(t_data *data);

/* libft */
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *str, int fd);

/* utils */
void	error(char *str);
long	timeofday(void);
void	ft_usleep(int ms);
void	message(t_philarg *philo, char *action);
int		check_meals(t_data *data);

/* actions */
void	sleep_think(t_philarg *philo);
void	forks(t_philarg *philo, int action);
void	eating(t_philarg *philo);

/* let's go */
void	*philo_life(void *arg);
void	run_threads(t_data *data);
void	monitoring(t_data *data);
int		death_check(t_data *data);
void	terminate(t_data *data, t_philarg *philo);

#endif

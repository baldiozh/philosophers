/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:56:26 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/15 20:18:44 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# define ERR_ARG	"\x1b[0;31mNumber of philosophers, tdeath, teat, tsleep.\n"
# define ERR_MEMORY	"\x1b[0;31mMemory allocation error.\n"
# define ERR_SEM	"\x1b[0;31mSemaphore's error.\n"
# define ERR_PID	"\x1b[0;31mProcess error.\n"
# define SLEEP 		"is sleeping"
# define THINK		"is thinking"
# define TAKE_FORK	"has taken fork"
# define EAT		"is eating"
# define DIED		"died\n"
# define TAKE 9
# define PUT 10

# define FORKS		"/forks"
# define SPEAKLOCK	"/speaklock"
# define DEATHLOCK	"/deathlock_"

typedef struct s_data
{
	int					philo_num;
	int					tdeath;
	int					teat;
	int					tsleep;
	int					meals_num;
	long long int		prog_start;
	sem_t				*forks;
	sem_t				*speaklock;
	pid_t				pids[200];
	int					stop;
	struct s_philarg	*philo;
}			t_data;

typedef struct s_philarg
{
	int						id;
	int						meals;
	long long int			last_meal;
	sem_t					*deathlock;
	t_data					*data;

}			t_philarg;

/* init */
void	init_data(int argc, char **argv, t_data *data);
void	init_child_process(t_data *data, int id);

/* libft */
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	ft_putstr(char *str);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);

/* utils */
void	error(char *str);
long	timeofday(void);
void	ft_usleep(int ms);
void	message(t_philarg *philo, char *action);
int		check_meals(t_data *data);

/* actions */


/* let's go */
void	start_process(t_data *data);
int		death_check(t_data *data);

#endif

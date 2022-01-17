/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:56:26 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/17 20:31:55 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <signal.h>

# define ERR_ARG	"\x1b[0;31mNumber of philosophers, tdeath, teat, tsleep.\n"
# define ERR_MEMORY	"\x1b[0;31mMemory allocation error.\n"
# define ERR_SEM	"\x1b[0;31mSemaphore's error.\n"
# define ERR_PID	"\x1b[0;31mProcess error.\n"
# define SLEEP 		"is sleeping"
# define THINK		"is thinking"
# define TAKE_FORK	"has taken a fork"
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
	volatile int		stop;	//
	volatile int		isdead; //
}			t_data;

typedef struct s_philarg
{
	int				id;
	int				meals;
	long long int	last_meal;
	char			*deathlock_name;
	sem_t			*deathlock;
	t_data			*data;

}			t_philarg;

/* init */
void	init_data(int argc, char **argv, t_data *data);
void	init_child_process(t_data *data, t_philarg *philo, int i);

/* libft */
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *str, int fd);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);

/* utils */
void	error(char *str);
long	timeofday(void);
void	ft_usleep(int ms);
void	message(t_philarg *philo, char *action);
int		check_meals(t_philarg *philo);

/* actions */
void	sleep_think(t_philarg *philo);
void	forks(t_philarg *philo, int action);
void	eating(t_philarg *philo);

/* let's go */
void	*monitoring(void *d);
int		philo_life(t_data *data, int i);
void	start_process(t_data *data);
int		death_check(t_philarg *philo);

/* end */
void	stop(t_data *data);
void	terminate(t_data *data);
void	force_terminate(t_data *data);

#endif

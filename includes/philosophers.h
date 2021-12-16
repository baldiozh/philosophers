/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:10:17 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/16 21:59:42 by gmckinle         ###   ########.fr       */
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


typedef struct s_data
{
	int				philo_num;
	int				tdeath;
	int				teat;
	int				tsleep;
	int				meals;
	time_t			start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	speak_mutex;


}			t_data;

typedef struct s_philo
{
	int						num;
	long long				lastmeal;
	// pthread_mutex_t			left_fork;
	// pthread_mutex_t			right_fork;
	pthread_mutex_t			death_mutex;

	t_data		*data;

}			t_philo;

/* init */
int		init(int argc, char **argv, t_data *data);
t_data	*init_data(int argc, char **argv);
t_philo	*init_philo(t_data *data);

/* utils */
int		ft_atoi(const char *str);

/* time */
long	current_time(void);
void	ft_usleep(int ms);

#endif


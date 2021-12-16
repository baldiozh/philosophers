/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:10:17 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/16 15:55:15 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_data
{
	int	num;
	int	tdeath;
	int	teat;
	int	tsleep;
	int	meals;

	pthread_mutex_t *forks;

}			t_data;

typedef struct s_philo
{
	int		p_id;

}			t_philo;

/* init */
t_data	*init_data(char **argv);

/* utils */
int		ft_atoi(const char *str);
void	ft_usleep(int ms);

#endif


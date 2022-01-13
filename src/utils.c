/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:53:47 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/13 21:59:19 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

long	timeofday(void)
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	res = 1000 * (long)tv.tv_sec + (long)tv.tv_usec / 1000;
	return (res);
}

void	ft_usleep(int ms)
{
	long	time;

	time = timeofday();
	usleep(ms * 920);
	while (timeofday() < time + (long)ms)
		usleep(ms * 3);
}

void	message(t_philarg *philo, int action)
{
	int	current_time;
	int	timestamp;

	current_time = timeofday();
	timestamp = current_time - philo->data->prog_start;
	pthread_mutex_lock(&philo->data->speak_mutex);
	if (action == SLEEP)
		printf("%d ms	%d	is sleeping\n", timestamp, philo->id);
	else if (action == THINK)
		printf("%d ms	%d	is thinking\n", timestamp, philo->id);
	else if (action == TAKE_FORK)
		printf("%d ms	%d	has taken a fork\n", timestamp, philo->id); //printf("%d ms	%d	has taken a fork %d %d\n", timestamp, philo->id, philo->left_fork, philo->right_fork);
	else if (action == EAT)
		printf("%d ms	%d	is eating\n", timestamp, philo->id);
	else if (action == DIED)
		printf("%d ms	%d	died\n", timestamp, philo->id);
	else
	{
		printf("\x1b[0;31mWrong type of action.\n");
		exit(EXIT_FAILURE);
	}
	pthread_mutex_unlock(&philo->data->speak_mutex);
}

int	check_meals(t_data *data)
{
	int	i;

	i = 0;
	if (data->meals_num != -1)
	{
		while(i < data->philo_num)
		{
			if(data->philo[i].meals < data->meals_num)
				return (1);
			i++;
		}
		return(0);
	}
	else
		return (1);
}

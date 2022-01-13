/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:53:47 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/13 22:50:29 by gmckinle         ###   ########.fr       */
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

void	message(t_philarg *philo, char *action)
{
	int	timestamp;

	timestamp = timeofday() - philo->data->prog_start;
	pthread_mutex_lock(&philo->data->speak_mutex);
	if (philo->data->stop == 0)
		printf("%d ms	%d	%s\n", timestamp, philo->id, action);
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
				i++;
			else
			{
				data->stop = 1;
				return (1);
			}
		}
	}
	return (0);
}

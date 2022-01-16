/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:50:48 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/16 18:50:02 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/philosophers_bonus.h"

void	error(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
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
	sem_wait(philo->data->speaklock);
	printf("%d %d %s\n", timestamp, philo->id, action);
	sem_post(philo->data->speaklock);
}

int	check_meals(t_philarg *philo)
{
	if (philo->data->meals_num != -1)
	{
		if (philo->meals == philo->data->meals_num)
		{
			philo->data->stop = 1;
			return (1);
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:53:47 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/22 21:42:44 by gmckinle         ###   ########.fr       */
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
	timestamp = philo->data->prog_start - current_time;
	if (action == SLEEP)
		printf("%d ms	%d	is sleeping\n", timestamp, philo->id); //bc id starts from 0
	else if (action == THINK)
		printf("%d ms	%d	is thinking\n", timestamp, philo->id);
	else if (action == TAKE_FORKS)
		printf("%d ms	%d	has taken forks\n", timestamp, philo->id);
	else if (action == EAT)
		printf("%d ms	%d	is eating\n", timestamp, philo->id);
	else if (action == DIED)
		printf("%d ms	%d	died\n", ++timestamp, philo->id);
	else
	{
		printf("\x1b[0;31mWrong type of action.\n");
		exit(EXIT_FAILURE);
	}
}

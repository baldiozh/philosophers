/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:12:27 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/13 22:56:53 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_life(void *data)
{
	t_philarg	*philo;

	philo = (t_philarg *)data;
	if (philo->id % 2 == 0)
		sleep_think(philo);
	while(!philo->data->stop)
		eating(philo);
	return (NULL);
}

int	death_check(t_data *data)
{
	if ((long long)(timeofday() - data->philo->last_meal) > data->tdeath)
	{
		data->stop = 1;
		printf("%llu ms	%d	died\n", (timeofday() - data->prog_start), data->philo->id);
		return (1);
	}
	return (0);
}

void	monitoring(t_data *data)
{
	int	i = 0;

	while(data->stop != 1)
	{
		i = 0;
		while (i < data->philo_num && data->stop != 1)
		{
			pthread_mutex_lock(data->philo[i].death_mutex);
			death_check(data);
			pthread_mutex_unlock(data->philo[i].death_mutex);
			i++;
		}
		// check_meals(data);
		usleep(500);
	}
}

void	process(t_data *data)
{
	t_philarg	*philo;
	int i;

	i = 0;
	philo = (t_philarg *)data->philo;
	data->prog_start = timeofday();
	while (i < data->philo_num)
	{
		data->philo[i].last_meal = timeofday();
		pthread_create(&data->philo_tr[i], NULL, philo_life, &data->philo[i]);
		i++;
	}
	monitoring(data);
}

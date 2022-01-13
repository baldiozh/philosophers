/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:12:27 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/13 21:44:40 by gmckinle         ###   ########.fr       */
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
		message(data->philo, DIED);
		return (1);
	}
	return (0);
}

void	monitoring(t_data *data)
{
	int	i = 0;

	data->prog_start = timeofday();
	while(data->stop != 1)
	{
		ft_usleep(100);
		i = 0;
		while (i < data->philo_num && data->stop != 1)
		{
			pthread_mutex_lock(data->philo[i].death_mutex);
			death_check(data);
			pthread_mutex_unlock(data->philo[i].death_mutex);
			i++;
		}
	}
}

void	process(t_data *data)
{
	t_philarg	*philo;
	int i;

	i = 0;
	philo = (t_philarg *)data->philo;
	data->prog_start = (int)timeofday();
	while (i < data->philo_num)
	{
		pthread_create(&data->philo_tr[i], NULL, philo_life, &data->philo[i]);
		i++;
	}
	monitoring(data);
}

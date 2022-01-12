/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:12:27 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/12 16:06:24 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_life(void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if (d->philo->id % 2 == 0)
		ft_usleep(100);
	if (!d->isdead)
		eating(d->philo);
	else
		message(d->philo, DIED); //needed?
	// monitoring(d);
	return (NULL);
}

void	*death_check(void *data)
{
	t_data		*d;

	d = (t_data *)data;
	if ((long long)(timeofday() - d->philo->last_meal) > d->tdeath)
	{
		d->isdead = 1;
		message(d->philo, DIED);
		terminate(d);
	}
	
	//add check if meals == meals_num later
	return (NULL);
}

void	monitoring(t_data *data)
{
	(void)data;
	int	i = 0;

	data->prog_start = timeofday();
	while(1)
	{
		ft_usleep(100);
		i = 0;
		while (i < data->philo_num)
		{
			pthread_mutex_lock(data->philo[i].death_mutex);
			death_check(data);
			if (data->isdead == 1)
				terminate(data);
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
	// pthread_create(&data->monitor, NULL, death_check, &data->philo[i]);
	monitoring(data);
}

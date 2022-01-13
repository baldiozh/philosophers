/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:12:27 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/13 16:38:32 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_life(void *data)
{
	t_philarg	*philo;

	philo = (t_philarg *)data;
	if (philo->id % 2 == 0)
		ft_usleep(100);
	while(!philo->data->isdead)
		eating(philo);
	// monitoring(data);
	return (NULL);
}

void	*death_check(void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if ((long long)(timeofday() - d->philo->last_meal) > d->tdeath)
	{
		d->isdead = 1;
		message(d->philo, DIED);
		terminate(d);
	}
	return (NULL);
}

void	*monitoring(void *data)
{
	int	i = 0;
	t_data		*d;

	d = (t_data *)data;
	d->prog_start = timeofday();
	while(1)
	{
		ft_usleep(100);
		i = 0;
		while (i < d->philo_num)
		{
			pthread_mutex_lock(d->philo[i].death_mutex);
			death_check(d);
			if (!check_meals(d) || d->isdead)
				terminate(d);
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
		// printf("!\n");
		pthread_create(&data->philo_tr[i], NULL, philo_life, &data->philo[i]);
		i++;
	}
	monitoring(data);
}

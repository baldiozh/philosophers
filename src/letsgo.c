/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:12:27 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/23 22:44:15 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void* hello(void *args)
{
	(void)args;
	while (1)
		printf("Hello from thread!\n");
    return 0;
}


void	*philo_life(void *data)
{
	t_philarg	*philo;

	philo = (t_philarg *)data;
	if (philo->id % 2 == 0)
		ft_usleep(100);
	if (!philo->data->isdead)
		eating(data);
	else
		message(data, DIED); //needed?
	return (NULL);
}

void	monitoring(t_data *data)
{
	// t_philarg	*philo;

	// philo = (t_philarg *)data;
	data->prog_start = timeofday();
	if ((int)(timeofday() - data->philo->last_meal) > data->tdeath && data->philo->last_meal)
	{
		data->isdead = 1;
		message(data->philo, DIED);
		terminate(data);
	}
	// return(NULL);
}

void	process(t_data *data)
{
	t_philarg	*philo;
	int i;

	i = 0;
	philo = (t_philarg *)data->philo;
	data->prog_start = (int)timeofday();
	while (i++ < data->philo_num)
		pthread_create(&data->philo_tr[i], NULL, philo_life, &data->philo[i]);
	// pthread_create(&data->monitor, NULL, monitoring, &data->philo[i]);
	// pthread_join(data->monitor, NULL);
}

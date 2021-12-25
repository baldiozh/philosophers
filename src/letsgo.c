/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:12:27 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/25 19:58:28 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// void* hello(void *args)
// {
// 	(void)args;
// 	while (1)
// 		printf("Hello from thread!\n");
//     return 0;
// }

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
	pthread_create(&philo->data->monitor, NULL, death_check, &philo[philo->id]);
	return (NULL);
}

void	*death_check(void *data)
{
	t_philarg	*philo;

	philo = (t_philarg *)data;
	if ((long long)(timeofday() - philo->last_meal) > philo->data->tdeath)
	{
		philo->data->isdead = 1;
		message(philo, DIED);
		terminate(data);
	}
	return (NULL);
}

void	monitoring(t_data *data)
{
	// t_philarg	*philo;
	// philo = (t_philarg *)data;
	int	i;

	data->prog_start = timeofday();
	while(1)
	{
		i = 0;
		while (i++ < data->philo_num)
		{
			// if ((int)(timeofday() - data->philo->last_meal) > data->tdeath)
			// {
			// 	data->isdead = 1;
			// 	message(data->philo, DIED);
			// 	terminate(data);
			// }
		}
	}
	// death_check(data);
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
		pthread_create(&data->philo_tr[i - 1], NULL, philo_life, &data->philo[i]);
	// pthread_create(&data->monitor, NULL, death_check, &data->philo_tr[i]);
	// while (i-- > 0)
	// 	pthread_join(data->philo_tr[i], NULL);
}

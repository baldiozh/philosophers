/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:12:27 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/22 21:53:06 by gmckinle         ###   ########.fr       */
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
	// printf
	if (philo->id % 2 == 0)
		ft_usleep(100);
	philo->start_meal = timeofday();
	if (!philo->data->isdead)
	{
		eating(data);
		
		thinking(philo);
	}
	// else
	// 	message(data, DIED); //needed?
	return (NULL);
}

// void	monitoring(t_data *data)
// {

// }

void	process(t_data *data)
{
	t_philarg	*philo;
	int i;

	i = 0;
	philo = (t_philarg *)data->philo;
	data->prog_start = timeofday();

	while (i < data->philo_num)
	{
		pthread_create(&data->philo_tr[i], NULL, philo_life, &data->philo[i]);
		i++;
	}

}

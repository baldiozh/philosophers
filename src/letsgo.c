/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:12:27 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/21 20:48:03 by gmckinle         ###   ########.fr       */
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
	if (philo->num % 2 == 0)
		ft_usleep(100);
	// philo->lastmeal = timeofday();
	// philo->start = timeofday();
	if (!philo->data->isdead)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	process(t_data *data)
{
	t_philarg	*philo;
	int i;

	i = 0;
	philo = (t_philarg *)data->philo;
	data->prog_st = timeofday();
	while (i < data->philo_num)
	{
		pthread_create(&data->philos[i], NULL, hello, &data->philo[i]);
		i++;
	}
}

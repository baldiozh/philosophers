/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:12:27 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/21 18:55:58 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_life(void *data)
{
	t_philarg	*philo;

	philo = (t_philarg *)data;
	if (philo->num % 2 == 0)
		usleep(100);
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

void	letsgo(t_data *data)
{
	int			i;

	i = 0;
	if(!threads || !data->forks)
	{
		printf(ERR_MEMORY);
		exit(EXIT_FAILURE);
	}
	while(i++ < data->philo_num)
	{
		pthread_create(&threads[i], NULL, philo_life, data->philos);
		pthread_mutex_init(&data->forks[i], NULL);
	}

}

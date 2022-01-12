/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:50:23 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/12 16:01:50 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	terminate(t_data *data)
{
	(void)data;
	int	i;

	i = 0;
	while(i++ < data->philo_num)
		pthread_detach(data->philo_tr[i]);
	pthread_detach(data->monitor);
	while(i > 0)
	{
		// printf("%d\n", i);
		pthread_mutex_destroy(&data->forks[i]);
		i--;
	}
	pthread_mutex_destroy(data->philo->speak_mutex);
	pthread_mutex_destroy(data->philo->death_mutex);
}

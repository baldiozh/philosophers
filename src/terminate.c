/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:50:23 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/25 19:59:55 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	terminate(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->philo_num)
		pthread_detach(data->philo_tr[i]);
	pthread_detach(data->monitor);
	while(i-- > 0)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(data->speak_mutex);
	pthread_mutex_destroy(data->death_mutex);
}

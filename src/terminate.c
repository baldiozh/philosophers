/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:50:23 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/13 21:45:28 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	terminate(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->philo_num)
		pthread_join(data->philo_tr[i++], NULL);
	while(i > 0)
		pthread_mutex_destroy(&data->forks[i--]);
	pthread_mutex_destroy(&data->speak_mutex);
	while(i < data->philo_num)
		pthread_mutex_destroy(data->philo[i++].death_mutex);
	free(data->philo);
	free(data);
}

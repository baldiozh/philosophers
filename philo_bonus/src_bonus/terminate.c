/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:14:58 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/14 20:18:35 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	terminate(t_data *data, t_philarg *philo)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
		//process
	sem_close(data->forks);
	sem_unlink(FORKS);
	sem_close(data->speaklock);
	sem_unlink(SPEAKLOCK);
	free(philo);
	free(data);
}

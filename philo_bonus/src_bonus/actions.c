/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:18:26 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/17 20:13:49 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	sleep_think(t_philarg *philo)
{
	message(philo, SLEEP);
	ft_usleep(philo->data->tsleep);
	message(philo, THINK);
}

void	forks(t_philarg *philo, int action)
{
	if (action == TAKE && !philo->data->isdead && !philo->data->stop)
	{
		if (!philo->data->isdead && !philo->data->stop)
		{
			sem_wait(philo->data->forks);
			message(philo, TAKE_FORK);
		}
		if (!philo->data->isdead && !philo->data->stop)
		{
			sem_wait(philo->data->forks);
			message(philo, TAKE_FORK);
		}
	}
	else if (action == PUT)
	{
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
	}
}

void	eating(t_philarg *philo)
{
	forks(philo, TAKE);
	if (!philo->data->isdead && !philo->data->stop)
	{
		sem_wait(philo->deathlock);
		philo->meals++;
		philo->last_meal = timeofday();
		message(philo, EAT);
		ft_usleep(philo->data->teat);
		sem_post(philo->deathlock);
		forks(philo, PUT);
	}
	if (!philo->data->isdead && !philo->data->stop)
		sleep_think(philo);
}

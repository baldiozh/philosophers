/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:25:35 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/12 20:21:15 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


void	sleep_think(t_philarg *philo)
{
	message(philo, SLEEP);
	ft_usleep(philo->data->tsleep);
	message(philo, THINK);
}


void	forks(t_philarg *philo, int action)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->left_fork;
	right_fork = philo->right_fork;
	if (action == TAKE)
	{
		pthread_mutex_lock(&philo->data->forks[left_fork]);
		message(philo, TAKE_FORK);
		pthread_mutex_lock(&philo->data->forks[right_fork]);
		message(philo, TAKE_FORK);
	}
	else if (action == PUT)
	{
		pthread_mutex_unlock(&philo->data->forks[right_fork]);
		pthread_mutex_unlock(&philo->data->forks[left_fork]);
	}
}

void	eating(t_philarg *philo)
{
	if (philo->data->meals_num == philo[philo->id - 1].meals)
		terminate(philo->data);
	forks(philo, TAKE);
	pthread_mutex_lock(philo->death_mutex);
	philo->meals++;
	message(philo, EAT);
	ft_usleep(philo->data->teat);
	pthread_mutex_unlock(philo->death_mutex);
	philo->last_meal = timeofday();
	forks(philo, PUT);
	sleep_think(philo);
}

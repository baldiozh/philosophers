/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:25:35 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/23 20:18:37 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


void	sleep_think(t_philarg *philo)
{
	message(philo, SLEEP);
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
		pthread_mutex_unlock(&philo->data->forks[left_fork]);
		pthread_mutex_unlock(&philo->data->forks[right_fork]);
	}
}

void	eating(t_philarg *philo)
{

	forks(philo, TAKE);
	pthread_mutex_lock(philo->data->death_mutex);
	philo->meals++; //add check if meals == meals_num later
	message(philo, EAT);
	pthread_mutex_unlock(philo->data->death_mutex);
	forks(philo, PUT);
	ft_usleep(philo->data->teat);
	sleep_think(philo);
}

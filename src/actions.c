/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:25:35 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/22 21:40:39 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


void	sleeping(t_philarg *philo)
{
	message(philo, SLEEP);
}

void	thinking(t_philarg *philo)
{
	message(philo, THINK);
}

void	take_forks(t_philarg *philo)
{
	// int	left_fork;
	// int	right_fork;

	// left_fork = philo->left_fork;
	// right_fork = philo->right_fork;
	// pthread_mutex_lock(&philo->forks[left_fork]);
	// pthread_mutex_lock(&philo->forks[right_fork]);
	message(philo, TAKE_FORKS);
}

void	eating(t_philarg *philo)
{

	// take_forks(philo);
	// pthread_mutex_lock(philo->death_mutex);
	philo->meals++; //add check if meals == meals_num later
	message(philo, EAT);
}

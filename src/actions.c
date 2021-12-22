/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:25:35 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/22 21:08:47 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


void	sleeping(t_data *data)
{
	message(data, SLEEP);
}

void	thinking(t_data *data)
{
	message(data, THINK);
}

void	take_forks(t_data *data)
{
	// int	left_fork;
	// int	right_fork;

	// left_fork = data->philo->left_fork;
	// right_fork = data->philo->right_fork;
	// pthread_mutex_lock(&data->forks[left_fork]);
	// pthread_mutex_lock(&data->forks[right_fork]);
	message(data, TAKE_FORKS);
}

void	eating(t_data *data)
{

	// take_forks(data);
	// pthread_mutex_lock(data->death_mutex);
	data->philo->meals++; //add check if meals == meals_num later
	message(data, EAT);
}

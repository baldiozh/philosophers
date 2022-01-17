/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:27:41 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/17 20:46:37 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	check_meals(t_philarg *philo)
{
	if (philo->data->meals_num != -1)
	{
		if (philo->meals >= philo->data->meals_num)
		{
			philo->data->stop = 1;
			return (1);
		}
	}
	return (0);
}

int	death_check(t_philarg *philo)
{
	if ((long long)(timeofday() - philo->last_meal) > philo->data->tdeath)
	{
		philo->data->isdead = 1;
		sem_wait(philo->data->speaklock);
		printf("%llu %d died\n",
			(timeofday() - philo->data->prog_start), philo->id);
		return (1);
	}
	return (0);
}

void	*monitoring(void *d)
{
	t_philarg	*philo;

	philo = (t_philarg *)d;
	while (!philo->data->stop && !philo->data->isdead)
	{
		sem_wait(philo->deathlock);
		if (death_check(philo))
		{
			stop(philo->data);
			terminate(philo->data);
		}
		sem_post(philo->deathlock);
		usleep(500);
	}
	return (NULL);
}

int	philo_life(t_data *data, int i)
{
	pthread_t	monitor;
	t_philarg	philo;

	init_child_process(data, &philo, i);
	pthread_create(&monitor, NULL, monitoring, &philo);
	while (!data->stop && !data->isdead)
	{
		if (!philo.data->isdead && !philo.data->stop)
			eating(&philo);
		if (check_meals(&philo))
			return (EXIT_FAILURE);
		if (!philo.data->isdead && !philo.data->stop)
			sleep_think(&philo);
	}
	pthread_join(monitor, NULL);
	sem_unlink(philo.deathlock_name);
	free(philo.deathlock_name);
	if (philo.data->isdead == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


void	start_process(t_data *data)
{
	int	i;

	i = 0;
	data->prog_start = timeofday();
	while (i < data->philo_num)
	{
		data->pids[i] = fork();
		if (data->pids[i] == 0)
			exit(philo_life(data, i));
		if (data->pids[i] == -1)
			error(ERR_PID);
		i++;
	}
}

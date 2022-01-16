/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:27:41 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/16 20:07:40 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*monitoring(void *d)
{
	t_philarg	*philo;

	philo = (t_philarg *)d;
	while (!philo->data->stop && !philo->data->isdead)
	{
		sem_wait(philo->deathlock);
		check_meals(philo);
		death_check(philo);
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
	if (philo.id % 2 == 0)
		sleep_think(&philo);
	while (!data->stop && !data->isdead)
		eating(&philo);
	pthread_join(monitor, NULL);
	sem_unlink(philo.deathlock_name);
	free(philo.deathlock_name);
	if (philo.data->isdead == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	death_check(t_philarg *philo)
{
	if ((long long)(timeofday() - philo->last_meal) > philo->data->tdeath)
	{
		philo->data->isdead = 1;
		printf("%llu %d died\n",
			(timeofday() - philo->data->prog_start), philo->id);
		return (1);
	}
	return (0);
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
		{
			exit(philo_life(data, i));
		}
		if (data->pids[i] == -1)
			error(ERR_PID);
		i++;
	}
}

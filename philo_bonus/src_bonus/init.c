/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:22:13 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/17 20:31:52 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/philosophers_bonus.h"

void	init_data(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	data->philo_num = ft_atoi(argv[1]);
	data->tdeath = ft_atoi(argv[2]);
	data->teat = ft_atoi(argv[3]);
	data->tsleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meals_num = ft_atoi(argv[5]);
	else
		data->meals_num = -1;
	if (data->philo_num < 1 || data->tdeath < 0
		|| data->teat < 0 || data->tsleep < 0)
		error(ERR_ARG);
	data->stop = 0;
	data->isdead = 0;
	sem_unlink(FORKS);
	sem_unlink(SPEAKLOCK);
	data->forks = sem_open(FORKS, O_CREAT, 0777, data->philo_num);
	data->speaklock = sem_open(SPEAKLOCK, O_CREAT, 0777, 1);
	if (data->forks == SEM_FAILED || data->speaklock == SEM_FAILED)
		error(ERR_SEM);
}

void	init_child_process(t_data *data, t_philarg *philo, int i)
{
	char		*num;

	philo->id = i + 1;
	philo->meals = 0;
	philo->last_meal = timeofday();
	num = ft_itoa(i);
	philo->deathlock_name = ft_strjoin(DEATHLOCK, num);
	free(num);
	sem_unlink(philo->deathlock_name);
	philo->deathlock = sem_open(philo->deathlock_name, O_CREAT, 0777, 1);
	philo->data = data;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:22:13 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/15 20:21:45 by gmckinle         ###   ########.fr       */
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
	sem_unlink(FORKS);
	sem_unlink(SPEAKLOCK);
	data->forks = sem_open(FORKS, O_CREAT, 0777, data->philo_num);
	data->speaklock = sem_open(SPEAKLOCK, O_CREAT, 0777, 1);
	if(data->forks == SEM_FAILED || data->speaklock == SEM_FAILED)
		error(ERR_SEM);
	data->philo = (t_philarg *)malloc(sizeof(t_philarg) * data->philo_num);
	if (!data->philo)
		error(ERR_MEMORY);
}

void	init_child_process(t_data *data, int id)
{
	char		*deathlock_name;
	t_philarg	*philo;

	philo = data->philo;
	philo[id].id = id + 1;
	printf("philo[id].id = %d\n", philo[id].id);
	philo[id].meals = 0;
	philo[id].last_meal = timeofday();
	deathlock_name = ft_strjoin(DEATHLOCK, ft_itoa(id));
	printf("%s\n", deathlock_name);
	sem_unlink(deathlock_name);
	philo[id].deathlock = sem_open(deathlock_name, O_CREAT, 0777, 1);
	philo[id].data = data;
	data->philo[id] = philo[id];

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:11:27 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/17 15:39:28 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_data(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	data->philo_num = ft_atoi(argv[1]);
	data->tdeath = ft_atoi(argv[2]);
	data->teat = ft_atoi(argv[3]);
	data->tsleep = ft_atoi(argv[4]);
	data->meals_num = -1;
	if (argc == 6)
		data->meals_num = ft_atoi(argv[5]);
	if (data->philo_num < 1 || data->tdeath <= 0
		|| data->teat <= 0 || data->tsleep <= 0
		|| (argc == 6 && data->meals_num <= 0))
		error(ERR_ARG);
	data->stop = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (data->philo_num));
	if (!data->forks)
		error(ERR_MEMORY);
	while (i < data->philo_num)
		pthread_mutex_init(&(data->forks[i++]), NULL);
	pthread_mutex_init(&(data->speak_mutex), NULL);
	data->philo = (t_philarg *)malloc(sizeof(t_philarg) * (data->philo_num));
	if (!data->philo)
		error(ERR_MEMORY);
}

void	init_death_mutexes(t_data *data, t_philarg *philo)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		philo[i].death_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
				* 1);
		if (!philo[i].death_mutex)
			error(ERR_MEMORY);
		i++;
	}
}

void	init_philarg(t_data *data)
{
	t_philarg	*philo;
	int			i;

	i = 0;
	philo = (t_philarg *)data->philo;
	init_death_mutexes(data, philo);
	while (i < data->philo_num)
	{
		philo[i].id = i + 1;
		philo[i].meals = 0;
		philo[i].last_meal = 0;
		philo[i].left_fork = i;
		philo[i].right_fork = i + 1;
		if (i == data->philo_num - 1)
			philo[i].right_fork = 0;
		philo[i].data = data;
		data->philo[i] = philo[i];
		pthread_mutex_init(philo[i].death_mutex, NULL);
		i++;
	}
}

void	init(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
		error(ERR_ARG);
	init_data(argc, argv, data);
	init_philarg(data);
}

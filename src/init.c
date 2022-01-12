/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:11:27 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/12 14:42:33 by gmckinle         ###   ########.fr       */
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
	if (argc == 6)
		data->meals_num = ft_atoi(argv[5]);
	else
		data->meals_num = -1;
	if (data->philo_num < 1 || data->tdeath < 0 ||
			data->teat < 0 || data->tsleep < 0 )
		error(ERR_ARG);
	data->isdead = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (data->philo_num + 1));
	if (!data->forks)
		error(ERR_MEMORY);
	while (i++ < data->philo_num)
		pthread_mutex_init(&data->forks[i], NULL);
	data->philo = (t_philarg *)malloc(sizeof(t_philarg) * (data->philo_num + 1));
	if (!data->philo)
		error(ERR_MEMORY);
}

void	init_philarg(t_data *data)
{
	t_philarg	*philo;
	int		i;

	i = 0;
	philo = (t_philarg *)data->philo;
	// philo = malloc(sizeof(t_philarg) * (data->philo_num + 1));
	// if (!data->philo)
	// 	error(ERR_MEMORY);
	while(i < data->philo_num)
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
		i++;
	}
	philo->speak_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 2);
	if (!philo->speak_mutex)
		error(ERR_MEMORY);
	pthread_mutex_init(philo->speak_mutex, NULL);
	philo->death_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 2); //2?
	pthread_mutex_init(philo->death_mutex, NULL);
}


void	init(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
		error(ERR_ARG);
	init_data(argc, argv, data);
	init_philarg(data);
}

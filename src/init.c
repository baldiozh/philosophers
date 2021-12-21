/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:11:27 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/21 20:46:22 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void init_data(int argc, char **argv, t_data *data)
{
	int i;

	i = 0;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		printf(ERR_MEMORY);
		exit(EXIT_FAILURE);
	}
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philo_num);
	while (i < data->philo_num)
		pthread_mutex_init(&data->forks[i], NULL);
	data->speak_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 2);
	if (!data)
	{
		printf(ERR_MEMORY);
		exit(EXIT_FAILURE);
	}
	pthread_mutex_init(data->speak_mutex, NULL);
	pthread_mutex_init(data->death_mutex, NULL);
	data->philo_num = ft_atoi(argv[1]);
	data->isdead = 0;
	data->tdeath = ft_atoi(argv[2]);
	data->teat = ft_atoi(argv[3]);
	data->tsleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meals = ft_atoi(argv[5]);
	else
		data->meals = -1;
	if (data->philo_num < 1 || data->tdeath < 0 ||
			data->teat < 0 || data->tsleep < 0 )
	{
		printf(ERR_ARG);
		exit(EXIT_FAILURE);
	}
	data->philo = (t_philarg *)malloc(sizeof(t_philarg) * data->philo_num);
}


void	init_philarg(t_data *data)
{
	t_philarg *philoo;
	int		i;

	i = 0;
	philoo = malloc(sizeof(t_philarg) * data->philo_num);
	if (!data->philo)
	{
		printf(ERR_MEMORY);
		exit(EXIT_FAILURE);
	}
	while(i < data->philo_num)
	{
		philoo[i].num = i;
		philoo[i].start_meal = timeofday(); //0!
	    philoo[i].left_fork = i;
		philoo[i].right_fork = i + 1;
		if (i == data->philo_num - 1)
			philoo[i].right_fork = 0;
		philoo[i].data = data;
		data->philo[i] = philoo[i];
		i++;
	}
}


void	init(int argc, char **argv, t_data *data)
{

	if (argc < 5 || argc > 6)
	{
		printf(ERR_ARG);
		exit(EXIT_FAILURE);
	}
	init_data(argc, argv, data);
	init_philarg(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:11:27 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/18 17:41:08 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		printf(ERR_MEMORY);
		return (NULL);
	}
	data->philo_num = ft_atoi(argv[1]);
	if (data->philo_num == 1)
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
	return (data);
}


t_philarg	*init_philo(t_data *data)
{
	int		i;
	t_philarg	*philo;

	i = 1;
	philo = (t_philarg *)malloc(sizeof(t_philarg) * data->philo_num);
	if (!philo)
	{
		printf(ERR_MEMORY);
		return (NULL);
	}
	pthread_mutex_init(&(data->speak_mutex), NULL);
	while(i < data->philo_num)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		philo[i].num = i;
		philo[i].lastmeal = current_time();
		// pthread_mutex_init(&philo[i].left_fork, NULL);          //???
		// if (i == data->philo_num)
		// 	pthread_mutex_init(&philo[1].right_fork, NULL);
		// else
		// 	pthread_mutex_init(&philo[i + 1].right_fork, NULL);
		pthread_mutex_init(&philo->death_mutex, NULL); //???
	}
	return (philo);
}


int	init(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
	{
		printf(ERR_ARG);
		return (-1);
	}
	if (!init_data(argc, argv))
		return (-1);
	if (!init_philo(data))
		return (-1);
	return (0);
}

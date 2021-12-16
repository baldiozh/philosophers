/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:11:27 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/16 21:59:39 by gmckinle         ###   ########.fr       */
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

	return (data);
}


t_philo	*init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 1;
	philo = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
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
		return (-1);
	if (!init_data(argc, argv))
		return (-1);
	if (!init_philo(data))
		return (-1);
	return (0);
}

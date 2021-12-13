/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:11:27 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/13 19:49:16 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*init_philo(char **argv)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		printf("Memory allocation for the philo struct error.\n");
	philo->num = ft_atoi(argv[1]);
	philo->tdeath = ft_atoi(argv[2]);
	philo->teat = ft_atoi(argv[3]);
	philo->tsleep = ft_atoi(argv[4]);
	return (philo);
}

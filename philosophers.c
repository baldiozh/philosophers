/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:09:40 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/13 21:10:22 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc < 4 || argc > 4)
		printf("Enter number of philosophers, time to death, time to eat, time to sleep.\n");
	philo = init_philo(argv);
	// pthread_create(&t1)
	// printf("num = %d\n death = %d\n eat = %d\n sleep = %d\n", philo->num, philo->tdeath, philo->teat, philo->tsleep);
	return(0);
}

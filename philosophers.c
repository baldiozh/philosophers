/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:09:40 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/15 18:48:42 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void* hello(void *args)
{
	(void)args;
    printf("Hello from thread!\n");
    return 0;
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	pthread_t t1;

	if (argc < 5 || argc > 5)
	{
		printf("Enter number of philosophers, time to death, time to eat, time to sleep.\n");
		exit(EXIT_FAILURE);
	}
	philo = init_philo(argv);

	if (!pthread_create(&t1, NULL, hello, NULL))
		printf("thread ctreated.\n");
	// printf("num = %d\n death = %d\n eat = %d\n sleep = %d\n", philo->num, philo->tdeath, philo->teat, philo->tsleep);
	return(0);
}

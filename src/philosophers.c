/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:09:40 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/21 20:32:13 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void* hello(void *args)
{
	(void)args;
	while (1)
		printf("Hello from thread!\n");
    return 0;
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int i;

	data = (t_data *)malloc(sizeof(t_data));
	i = 0;
	init(argc, argv, data);
	data->prog_st = timeofday();
	while (i < data->philo_num)
	{
		pthread_create(&data->philos[i], NULL, hello, &data->philo[i]);
		i++;
	}
	while (1)
	{

	}
	// if (!pthread_create(&t1, NULL, hello, NULL))
	// 	printf("thread ctreated.\n");
	// pthread_join(t1, NULL);
	// pthread_detach(t1);
	// printf("%ld\n", timeofday());
	return(0);
}

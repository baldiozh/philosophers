/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:09:40 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/21 21:45:19 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error(ERR_MEMORY);
	init(argc, argv, data);
	// while (1)
	// {

	// }
	// if (!pthread_create(&t1, NULL, hello, NULL))
	// 	printf("thread ctreated.\n");
	// pthread_join(t1, NULL);
	// pthread_detach(t1);
	printf("%d\n", data->philo_num);
	return(0);
}

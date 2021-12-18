/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:09:40 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/18 20:54:30 by gmckinle         ###   ########.fr       */
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
	t_data	data;
	pthread_t t1;

	if (init(argc, argv,  &data) == -1)
		return (-1);
	if (!pthread_create(&t1, NULL, hello, NULL))
		printf("thread ctreated.\n");
	pthread_join(t1, NULL);
	pthread_detach(t1);
	printf("%ld\n", timeofday());
	return(0);
}

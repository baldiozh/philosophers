/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:53:47 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/21 21:57:47 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

long	timeofday(void)
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	res = 1000 * (long)tv.tv_sec + (long)tv.tv_usec / 1000;
	return (res);
}

void	ft_usleep(int ms)
{
	long	time;

	time = timeofday();
	usleep(ms * 920);
	while (timeofday() < time + (long)ms)
		usleep(ms * 3);
}

void	message(int action)
{
	if (action == SLEEP)
		printf("is sleeping\n");
	else if (action == THINK)
		printf("is thinking\n");
	else if (action == EAT)
		printf("is eating\n");
	else
		printf("\x1b[0;31mWrong type of action.\n");
}

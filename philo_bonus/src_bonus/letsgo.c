/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:27:41 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/14 21:41:17 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	death_check(t_data *data)
{
	if ((long long)(timeofday() - data->philo->last_meal) > data->tdeath)
	{
		data->stop = 1;
		printf("%llu ms	%d	died\n",
			(timeofday() - data->prog_start), data->philo->id);
		return (1);
	}
	return (0);
}

void	monitoring(t_data *data)
{
	int	i;

	i = 0;
	while (!data->stop)
	{
		i = 0;
		check_meals(data);
		death_check(data);
		usleep(500);
	}
}

void	start_process(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		data->pids[i] = fork();
		if (data->pids[i] == -1)
			error(ERR_PID);
		i++;
	}
	monitoring(data);

}

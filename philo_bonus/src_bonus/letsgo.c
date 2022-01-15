/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:27:41 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/15 19:55:21 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	death_check(t_data *data)
{
	if ((long long)(timeofday() - data->philo->last_meal) > data->tdeath)
	{
		data->stop = 1;
		printf("%llu	%d	died\n",
			(timeofday() - data->prog_start), data->philo->id);
		return (1);
	}
	return (0);
}

void	monitoring(void *d)
{
	t_data	*data;
	int	i;

	i = 0;
	data = (t_data *)d;
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
	data->prog_start = timeofday();
	while (i < data->philo_num)
	{
		data->pids[i] = fork();
		if (data->pids[i] == 0)
		{
			init_child_process(data, i);
			printf("my pid = %d\n", getpid());
			// monitoring(data);
		}
		else if (data->pids[i] == -1)
			error(ERR_PID);
		i++;
	}

}

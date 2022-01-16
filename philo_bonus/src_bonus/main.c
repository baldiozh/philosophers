/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:55:30 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/16 20:08:25 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/philosophers_bonus.h"

void	stop(t_data *data)
{
	int	i;
	int	status;

	i = data->philo_num;
	while (i)
	{
		waitpid(0, &status, 0);
		if (WEXITSTATUS(status) == EXIT_FAILURE)
		{
			i = 0;
			while (i < data->philo_num)
				kill(data->pids[i++], SIGKILL);
			break ;
		}
		--i;
	}
	i = 0;
	while (i < data->philo_num)
		waitpid(data->pids[i++], NULL, 0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		error(ERR_ARG);
	init_data(argc, argv, &data);
	start_process(&data);
	stop(&data);
	terminate(&data);
}

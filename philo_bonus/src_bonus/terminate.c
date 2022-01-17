/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:14:58 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/17 20:37:04 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	force_terminate(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_num)
		kill(data->pids[i++], SIGKILL);
}

void	terminate(t_data *data)
{
	sem_close(data->forks);
	sem_unlink(FORKS);
	sem_close(data->speaklock);
	sem_unlink(SPEAKLOCK);
}

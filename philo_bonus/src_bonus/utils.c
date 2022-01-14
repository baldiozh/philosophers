/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:50:48 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/14 16:51:41 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/philosophers_bonus.h"

void	error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

void	message(t_philarg *philo, char *action)
{
	int	timestamp;

	timestamp = timeofday() - philo->data->prog_start;
	if (philo->data->stop == 0)
		printf("%d ms	%d	%s\n", timestamp, philo->id, action);
}

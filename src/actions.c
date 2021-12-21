/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:25:35 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/21 22:07:27 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	sleeping(t_data *data)
{
	data->tdeath -= data->tsleep; //?
	message(SLEEP);
}

void	thinking(t_data *data)
{
	data->tdeath -= data->tsleep;
	message(THINK);
}

void	eating(t_data *data)
{
	(void)data;
	// data->tdeath
	message(EAT);
}
